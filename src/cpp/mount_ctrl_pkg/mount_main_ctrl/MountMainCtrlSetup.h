#ifndef _MountMainCtrlSetup_h_
#define _MountMainCtrlSetup_h_

#include <msgpack.hpp>
#include <ocs_core_fwk.h>
#include <ocs_ctrl_fwk.h>
#include "../../include/mount_dcs_port_types.h"

namespace gmt
{

struct MountMainCtrlSetup : public  BaseControllerSetup
{

    struct PropertyConf : public  BaseControllerSetup::PropertyConf
    {
        MSGPACK_DEFINE_MAP(uri, name, host, port, scan_rate, acl, priority)
    };

    struct StateVarConf : public  BaseControllerSetup::StateVarConf
    {

        MSGPACK_DEFINE_MAP(op_state, sim_mode, control_mode)
    };

    struct InputConf : public BaseControllerSetup::InputConf
    {
        MSGPACK_DEFINE_MAP(op_state_goal, sim_mode_goal, control_mode_goal)
    };

    struct OutputConf : public BaseControllerSetup::OutputConf
    {
        //DataIODef<hdk_hmi_leds>        hmi_outputs_req;
        MSGPACK_DEFINE_MAP(op_state_value, sim_mode_value, control_mode_value)
    };

    PropertyConf     properties;
    StateVarConf     state_vars;
    InputConf        inputs;
    OutputConf       outputs;

    MSGPACK_DEFINE_MAP(properties, state_vars, inputs, outputs, connectors)
};

} //namespace gmt

#endif // _HdkMainCtrlSetup_h_
