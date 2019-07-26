#ifndef _MountProxySetup_h_
#define _MountProxySetup_h_

#include <msgpack.hpp>
#include <ocs_core_fwk.h>
#include <ocs_io_fwk.h>
#include "../../include/mount_dcs_port_types.h"

namespace gmt
{

struct MountProxySetup : public  OpcuaProxySetup
{
  struct StateVarConf: public OpcuaProxySetup::StateVarConf
  {
      MSGPACK_DEFINE_MAP(op_state)
  };

  struct InputConf: public OpcuaProxySetup::InputConf
  {
      DataIODef<bool>        TestBool_to_device;
      DataIODef<int32_t>     TestInt_to_device;
      DataIODef<float>       TestFloat_to_device;
      DataIODef<std::string> TestString_to_device;
      MSGPACK_DEFINE_MAP(opcua_bus, TestBool_to_device, TestInt_to_device, TestFloat_to_device, TestString_to_device, op_state_goal)
  };

  struct OutputConf: public OpcuaProxySetup::OutputConf
  {
      DataIODef<bool>        TestBool_from_device;
      DataIODef<int32_t>     TestInt_from_device;
      DataIODef<float>       TestFloat_from_device;
      DataIODef<std::string> TestString_from_device;
      MSGPACK_DEFINE_MAP(TestBool_from_device, TestInt_from_device, TestFloat_from_device, TestString_from_device, heartbeat_out, op_state_value)
  };

  struct PropertyConf: public OpcuaProxySetup::PropertyConf
  {
      MSGPACK_DEFINE_MAP(uri, name, host, port, scan_rate, acl, priority, opcua_cfg_name)
  };

  PropertyConf     properties;
  StateVarConf     state_vars;
  InputConf        inputs;
  OutputConf       outputs;

  MSGPACK_DEFINE_MAP(properties, state_vars, inputs, outputs)
};

} //namespace gmt

#endif // _HdkHwAdapterSetup_h_
