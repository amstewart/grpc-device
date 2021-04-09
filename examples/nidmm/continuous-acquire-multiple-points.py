import grpc
import sys
import time
import nidmm_pb2 as nidmm_types
import nidmm_pb2_grpc as grpc_nidmm
import session_pb2 as session_types
import session_pb2_grpc as grpc_session

server_address = "localhost"
server_port = "31763"
session_name = "NI-DMM-Session-1"

# Resource name and options for a simulated 4065 client. Change them according to the NI-DMM model.
resource = "SimulatedDMM"
options = "Simulate=1, DriverSetup=Model:4065; BoardType:PCI"

# parameters
MAXPTSTOREAD        = 1000
config_range        = 10.00
resolution          = 5.5
measurementType     = nidmm_types.Function.FUNCTION_NIDMM_VAL_DC_VOLTS

# Read in cmd args
if len(sys.argv) >= 2:
    server_address = sys.argv[1]
if len(sys.argv) >= 3:
    server_port = sys.argv[2]
if len(sys.argv) >= 4:
    resource = sys.argv[3]
    options = ""

# Create the communication channel for the remote host and create connections to the NI-DMM and session services.
channel = grpc.insecure_channel(f"{server_address}:{server_port}")
nidmm_client = grpc_nidmm.NiDMMStub(channel)

any_error = False
# Checks for errors. If any, throws an exception to stop the execution.
def CheckForError (vi, status) :
    global any_error
    if(status != 0 and not any_error):
        any_error = True
        ThrowOnError (vi, status)

# Converts an error code returned by NI-DMM into a user-readable string.
def ThrowOnError (vi, error_code):
    error_message_request = nidmm_types.ErrorMessageRequest(
        vi = vi,
        error_code = error_code
    )
    error_message_response = nidmm_client.ErrorMessage(error_message_request)
    raise Exception (error_message_response.error_message)

try:
    # Open session to NI-DMM with options
    print('\nInitializing session...')
    init_with_options_response = nidmm_client.InitWithOptions(nidmm_types.InitWithOptionsRequest(
        session_name = session_name,
        resource_name = resource,
        id_query = False,
        option_string = options
    ))
    vi = init_with_options_response.vi
    CheckForError(vi, init_with_options_response.status)
    print(f'Session initialized with name {session_name} and id {vi.id}.\n')

    # Configure measurement
    print('Configuring Measurement...')
    config_measurement_response = nidmm_client.ConfigureMeasurementDigits(nidmm_types.ConfigureMeasurementDigitsRequest(
        vi = vi,
        measurement_function = measurementType,
        range = config_range,
        resolution_digits = resolution
    ))
    CheckForError(vi, config_measurement_response.status)
    print('Measurement Configured.\n')

    # Configure a multipoint acquisition
    print('Configuring Multipoint Acquisition...')
    config_multipoint_response = nidmm_client.ConfigureMultiPoint(nidmm_types.ConfigureMultiPointRequest(
        vi = vi,
        trigger_count = 1,
        sample_count = 0,
        sample_trigger = nidmm_types.SampleTrigger.SAMPLE_TRIGGER_NIDMM_VAL_IMMEDIATE,
        sample_interval = 0.0
    ))
    CheckForError(vi, config_multipoint_response.status)
    print('Multipoint Acquisition Configured.\n')

    # Initiate Acquisition
    print('Initiating Acquisition...')
    initiate_acquisition_response = nidmm_client.Initiate(nidmm_types.InitiateRequest(
        vi = vi
    ))
    CheckForError(vi, initiate_acquisition_response.status)
    print('Acquisition Initiated.\n')

    # Set while loop control
    stop_measurement = False

    # initialize variables
    num_measurements = 0
    sum_measurements = 0

    while(not stop_measurement):
        pts_available = 0
        # Check available data
        read_status_response = nidmm_client.ReadStatus(nidmm_types.ReadStatusRequest(
            vi = vi
        ))
        CheckForError(vi, read_status_response.status)
        pts_available = read_status_response.acquisition_backlog

        # if there are more than MAXPTSTOREAD measurements
        # available, set pts_available to MAXPTSTOREAD in order to
        # avoid reallocating the array for measurements
        pts_available = min(pts_available, MAXPTSTOREAD)

        if pts_available > 0:

            # Fetch data
            fetch_multipoints_response = nidmm_client.FetchMultiPoint(nidmm_types.FetchMultiPointRequest(
                vi = vi,
                maximum_time = -1,
                array_size = pts_available
            ))
            CheckForError(vi, fetch_multipoints_response.status)
            num_pts_read = fetch_multipoints_response.actual_number_of_points
            measurements = fetch_multipoints_response.reading_array

            # Increment number of measurements
            num_measurements += num_pts_read

            # Calculate sum
            for i in range(num_pts_read):
                sum_measurements += measurements[i]
            
            # Set stop_measurement when done
            if num_measurements >= 10*MAXPTSTOREAD:
                stop_measurement = True

    print('Acquisition Completed.\n')

    print(f'Number of measurements = {num_measurements}')

    # Calculate average
    average = sum_measurements/num_measurements
    print(f'Average = {average}')

    # Close NI-DMM session
    print('Closing session...')
    close_session_response = nidmm_client.Close(nidmm_types.CloseRequest(
        vi = vi
    ))
    CheckForError(vi, close_session_response.status)
    print('Session closed.\n')

# If NI-DMM API throws an exception, print the error message  
except grpc.RpcError as rpc_error:
    error_message = rpc_error.details()
    if rpc_error.code() == grpc.StatusCode.UNAVAILABLE :
        error_message = f"Failed to connect to server on {server_address}"
    print(f"{error_message}") 