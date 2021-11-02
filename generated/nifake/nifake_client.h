
//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// EXPERIMENTAL Client convenience wrapper for NI-FAKE.
//---------------------------------------------------------------------
#ifndef NIFAKE_GRPC_CLIENT_H
#define NIFAKE_GRPC_CLIENT_H

#include <grpcpp/grpcpp.h>

#include <nifake.grpc.pb.h>
#include <tests/utilities/client_helpers.h>

#include <memory>
#include <vector>

namespace nifake_grpc::experimental::client {

namespace pb = ::google::protobuf;
using StubPtr = std::unique_ptr<NiFake::Stub>;
using namespace nidevice_grpc::experimental::client;


AbortResponse abort(const StubPtr& stub, const nidevice_grpc::Session& vi);
AcceptListOfDurationsInSecondsResponse accept_list_of_durations_in_seconds(const StubPtr& stub, const nidevice_grpc::Session& vi, const std::vector<double>& delays);
AcceptViSessionArrayResponse accept_vi_session_array(const StubPtr& stub, const pb::uint32& session_count, const std::vector<nidevice_grpc::Session>& session_array);
AcceptViUInt32ArrayResponse accept_vi_uint32_array(const StubPtr& stub, const nidevice_grpc::Session& vi, const std::vector<pb::uint32>& u_int32_array);
BoolArrayOutputFunctionResponse bool_array_output_function(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& number_of_elements);
BoolArrayInputFunctionResponse bool_array_input_function(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& number_of_elements, const std::vector<bool>& an_array);
CommandWithReservedParamResponse command_with_reserved_param(const StubPtr& stub, const nidevice_grpc::Session& vi);
CreateConfigurationListResponse create_configuration_list(const StubPtr& stub, const std::vector<NiFakeAttributes>& list_attribute_ids);
DoubleAllTheNumsResponse double_all_the_nums(const StubPtr& stub, const nidevice_grpc::Session& vi, const std::vector<double>& numbers);
EnumArrayOutputFunctionResponse enum_array_output_function(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& number_of_elements);
EnumInputFunctionWithDefaultsResponse enum_input_function_with_defaults(const StubPtr& stub, const nidevice_grpc::Session& vi, const simple_variant<Turtle, pb::int32>& a_turtle);
ExportAttributeConfigurationBufferResponse export_attribute_configuration_buffer(const StubPtr& stub, const nidevice_grpc::Session& vi);
FetchWaveformResponse fetch_waveform(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& number_of_samples);
GetABooleanResponse get_a_boolean(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetANumberResponse get_a_number(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetAStringOfFixedMaximumSizeResponse get_a_string_of_fixed_maximum_size(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetBitfieldAsEnumArrayResponse get_bitfield_as_enum_array(const StubPtr& stub);
GetAnIviDanceStringResponse get_an_ivi_dance_string(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetAnIviDanceWithATwistArrayResponse get_an_ivi_dance_with_a_twist_array(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& a_string);
GetAnIviDanceWithATwistArrayOfCustomTypeResponse get_an_ivi_dance_with_a_twist_array_of_custom_type(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetAnIviDanceWithATwistByteArrayResponse get_an_ivi_dance_with_a_twist_byte_array(const StubPtr& stub);
GetAnIviDanceWithATwistStringResponse get_an_ivi_dance_with_a_twist_string(const StubPtr& stub);
GetAnIviDanceWithATwistStringStrlenBugResponse get_an_ivi_dance_with_a_twist_string_strlen_bug(const StubPtr& stub);
GetArraySizeForCustomCodeResponse get_array_size_for_custom_code(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetArrayUsingIviDanceResponse get_array_using_ivi_dance(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetArrayViUInt8WithEnumResponse get_array_vi_uint8_with_enum(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& array_len);
GetAttributeViBooleanResponse get_attribute_vi_boolean(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFakeAttributes& attribute_id);
GetAttributeViInt32Response get_attribute_vi_int32(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFakeAttributes& attribute_id);
GetAttributeViInt64Response get_attribute_vi_int64(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFakeAttributes& attribute_id);
GetAttributeViReal64Response get_attribute_vi_real64(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFakeAttributes& attribute_id);
GetAttributeViSessionResponse get_attribute_vi_session(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& attribute_id);
GetAttributeViStringResponse get_attribute_vi_string(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const NiFakeAttributes& attribute_id);
GetCalDateAndTimeResponse get_cal_date_and_time(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& cal_type);
GetCalIntervalResponse get_cal_interval(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetCustomTypeResponse get_custom_type(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetCustomTypeArrayResponse get_custom_type_array(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& number_of_elements);
GetEnumValueResponse get_enum_value(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetViUInt8Response get_vi_uint8(const StubPtr& stub, const nidevice_grpc::Session& vi);
GetViInt32ArrayResponse get_vi_int32_array(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& array_len);
GetViUInt32ArrayResponse get_vi_uint32_array(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& array_len);
ImportAttributeConfigurationBufferResponse import_attribute_configuration_buffer(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& configuration);
InitWithOptionsResponse init_with_options(const StubPtr& stub, const pb::string& resource_name, const bool& id_query, const bool& reset_device, const pb::string& option_string);
InitExtCalResponse init_ext_cal(const StubPtr& stub, const pb::string& resource_name, const pb::string& calibration_password);
InitWithVarArgsResponse init_with_var_args(const StubPtr& stub, const pb::string& resource_name, const std::vector<StringAndTurtle>& name_and_turtle);
MultipleArrayTypesResponse multiple_array_types(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& output_array_size, const std::vector<double>& input_array_of_floats, const std::vector<pb::int32>& input_array_of_integers);
MultipleArraysSameSizeResponse multiple_arrays_same_size(const StubPtr& stub, const nidevice_grpc::Session& vi, const std::vector<double>& values1, const std::vector<double>& values2, const std::vector<double>& values3, const std::vector<double>& values4);
OneInputFunctionResponse one_input_function(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& a_number);
ParametersAreMultipleTypesResponse parameters_are_multiple_types(const StubPtr& stub, const nidevice_grpc::Session& vi, const bool& a_boolean, const pb::int32& an_int32, const pb::int64& an_int64, const simple_variant<Turtle, pb::int32>& an_int_enum, const double& a_float, const simple_variant<FloatEnum, double>& a_float_enum, const pb::string& a_string);
PoorlyNamedSimpleFunctionResponse poorly_named_simple_function(const StubPtr& stub, const nidevice_grpc::Session& vi);
ReadResponse read(const StubPtr& stub, const nidevice_grpc::Session& vi, const double& maximum_time);
ReadDataWithInOutIviTwistResponse read_data_with_in_out_ivi_twist(const StubPtr& stub);
ReadFromChannelResponse read_from_channel(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::string& channel_name, const pb::int32& maximum_time);
ReturnANumberAndAStringResponse return_a_number_and_a_string(const StubPtr& stub, const nidevice_grpc::Session& vi);
ReturnDurationInSecondsResponse return_duration_in_seconds(const StubPtr& stub, const nidevice_grpc::Session& vi);
ReturnListOfDurationsInSecondsResponse return_list_of_durations_in_seconds(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& number_of_elements);
ReturnMultipleTypesResponse return_multiple_types(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& array_size);
SetCustomTypeResponse set_custom_type(const StubPtr& stub, const nidevice_grpc::Session& vi, const FakeCustomStruct& cs);
SetCustomTypeArrayResponse set_custom_type_array(const StubPtr& stub, const nidevice_grpc::Session& vi, const std::vector<FakeCustomStruct>& cs);
StringValuedEnumInputFunctionWithDefaultsResponse string_valued_enum_input_function_with_defaults(const StubPtr& stub, const nidevice_grpc::Session& vi, const simple_variant<MobileOSNames, std::string>& a_mobile_os_name);
TwoInputFunctionResponse two_input_function(const StubPtr& stub, const nidevice_grpc::Session& vi, const double& a_number, const pb::string& a_string);
Use64BitNumberResponse use64_bit_number(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int64& input);
WriteWaveformResponse write_waveform(const StubPtr& stub, const nidevice_grpc::Session& vi, const std::vector<double>& waveform);
CloseResponse close(const StubPtr& stub, const nidevice_grpc::Session& vi);
CloseExtCalResponse close_ext_cal(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& action);
ViUInt8ArrayInputFunctionResponse vi_uint8_array_input_function(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& number_of_elements, const pb::string& an_array);
ViUInt8ArrayOutputFunctionResponse vi_uint8_array_output_function(const StubPtr& stub, const nidevice_grpc::Session& vi, const pb::int32& number_of_elements);
ViInt16ArrayInputFunctionResponse vi_int16_array_input_function(const StubPtr& stub, const nidevice_grpc::Session& vi, const std::vector<pb::int32>& an_array);

} // namespace nifake_grpc::experimental::client

#endif /* NIFAKE_GRPC_CLIENT_H */
