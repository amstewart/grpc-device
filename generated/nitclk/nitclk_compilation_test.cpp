//---------------------------------------------------------------------
// This file is automatically generated. All manual edits will be lost.
//---------------------------------------------------------------------
// Compilation test for the NI-TClk Metadata
//---------------------------------------------------------------------
#include "nitclk_library.h"

namespace nitclk_grpc {

ViStatus ConfigureForHomogeneousTriggers(ViUInt32 sessionCount, ViSession sessions[])
{
  return niTClk_ConfigureForHomogeneousTriggers(sessionCount, sessions);
}

ViStatus FinishSyncPulseSenderSynchronize(ViUInt32 sessionCount, ViSession sessions[], ViReal64 minTime)
{
  return niTClk_FinishSyncPulseSenderSynchronize(sessionCount, sessions, minTime);
}

ViStatus GetAttributeViReal64(ViSession session, ViConstString channelName, ViAttr attributeId, ViReal64* value)
{
  return niTClk_GetAttributeViReal64(session, channelName, attributeId, value);
}

ViStatus GetAttributeViSession(ViSession session, ViConstString channelName, ViAttr attributeId, ViSession* value)
{
  return niTClk_GetAttributeViSession(session, channelName, attributeId, value);
}

ViStatus GetAttributeViString(ViSession session, ViConstString channelName, ViAttr attributeId, ViInt32 bufSize, ViChar value[])
{
  return niTClk_GetAttributeViString(session, channelName, attributeId, bufSize, value);
}

ViStatus GetExtendedErrorInfo(ViChar errorString[], ViUInt32 errorStringSize)
{
  return niTClk_GetExtendedErrorInfo(errorString, errorStringSize);
}

ViStatus Initiate(ViUInt32 sessionCount, ViSession sessions[])
{
  return niTClk_Initiate(sessionCount, sessions);
}

ViStatus IsDone(ViUInt32 sessionCount, ViSession sessions[], ViBoolean* done)
{
  return niTClk_IsDone(sessionCount, sessions, done);
}

ViStatus SetAttributeViReal64(ViSession session, ViConstString channelName, ViAttr attributeId, ViReal64 value)
{
  return niTClk_SetAttributeViReal64(session, channelName, attributeId, value);
}

ViStatus SetAttributeViSession(ViSession session, ViConstString channelName, ViAttr attributeId, ViSession value)
{
  return niTClk_SetAttributeViSession(session, channelName, attributeId, value);
}

ViStatus SetAttributeViString(ViSession session, ViConstString channelName, ViAttr attributeId, ViConstString value)
{
  return niTClk_SetAttributeViString(session, channelName, attributeId, value);
}

ViStatus SetupForSyncPulseSenderSynchronize(ViUInt32 sessionCount, ViSession sessions[], ViReal64 minTime)
{
  return niTClk_SetupForSyncPulseSenderSynchronize(sessionCount, sessions, minTime);
}

ViStatus Synchronize(ViUInt32 sessionCount, ViSession sessions[], ViReal64 minTclkPeriod)
{
  return niTClk_Synchronize(sessionCount, sessions, minTclkPeriod);
}

ViStatus SynchronizeToSyncPulseSender(ViUInt32 sessionCount, ViSession sessions[], ViReal64 minTime)
{
  return niTClk_SynchronizeToSyncPulseSender(sessionCount, sessions, minTime);
}

ViStatus WaitUntilDone(ViUInt32 sessionCount, ViSession sessions[], ViReal64 timeout)
{
  return niTClk_WaitUntilDone(sessionCount, sessions, timeout);
}

}  // namespace nitclk_grpc