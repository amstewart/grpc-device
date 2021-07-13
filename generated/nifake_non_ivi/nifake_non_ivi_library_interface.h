//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Library wrapper for implementing interactions with NI-FAKE-NON-IVI
//---------------------------------------------------------------------
#ifndef NIFAKE_NON_IVI_GRPC_LIBRARY_WRAPPER_H
#define NIFAKE_NON_IVI_GRPC_LIBRARY_WRAPPER_H

#include <grpcpp/grpcpp.h>
#include <niFakeNonIvi.h>

namespace nifake_non_ivi_grpc {

class NiFakeNonIviLibraryInterface {
 public:
  virtual ~NiFakeNonIviLibraryInterface() {}

  virtual int32 Close(FakeHandle handle) = 0;
  virtual int32 Init(const char sessionName[], FakeHandle* handle) = 0;
  virtual int32 InitWithHandleNameAsSessionName(const char handleName[], FakeHandle* handle) = 0;
};

}  // namespace nifake_non_ivi_grpc
#endif  // NIFAKE_NON_IVI_GRPC_LIBRARY_WRAPPER_H