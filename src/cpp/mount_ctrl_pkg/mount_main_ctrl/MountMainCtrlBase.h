#ifndef _MountMainCtrlBase_h_
#define _MountMainCtrlBase_h_

// GMT AUTO GENERATED CODE

#include <ocs_core_fwk.h>
#include <ocs_ctrl_fwk.h>
#include "../../include/mount_dcs_port_types.h"

class MountMainCtrlSetup;

namespace gmt
{

class MountMainCtrlBase : public BaseController
{
    public:
        MountMainCtrlBase(
                        const  std::string& comp_uri,
                        const  std::string& comp_name,
                        const  std::string& comp_host,
                        int    comp_port,
                        const  std::string& comp_acl,
                        double comp_scan_rate = 1.0,
                        int comp_prio = GMT_THREAD_DEFAULT_PRIO,
                        int comp_stack_size = GMT_DEFAULT_STACK_SIZE);

        virtual ~MountMainCtrlBase();

    protected:

        typedef MountMainCtrlSetup Setup;
        typedef BaseController Base;

        /**
        * Creates the state of the Component, i.e., state variables,
        * inputs, outputs, properties, alarms and faults
        * Overriden from the Component class
        */
        virtual void create_state() override;

        /**
        * Uses the given Component::Setup parameter to configure all the
        * Component interface features (state vars, inputs, outputs, properties, ...)
        * Overriden from the Component class
        */
        virtual void setup_state (ComponentSetup& conf) override;

        /**
        * Configure the object from a file. The classes that derive from Component
        * must reimplement this method, in order to unpack the binary contents of
        * the configuration file with their Setup structure.
        * Overriden from the Component class
        */
        virtual void configure_from_file (const std::string& fname) override;

    protected:

        // // Create state variables
        // StateVar<hdk_hmi>              hmi;
        // StateVar<hdk_motor>            motor;
        // StateVar<hdk_temp_measurements> temperatures;
        //
        // // Inputs declaration
        // hdk_hmi_buttons          hmi_inputs_val;      // HMI operation buttons
        // hdk_motor_status         motor_state_val;     // motor state
        // hdk_temp_measurements    temperatures_val;    // temperature measurements
        //
        // // Outputs declaration
        // hdk_hmi_leds             hmi_outputs_req;     // digital outputs
        // hdk_motor_control        motor_ctrl_req;      // motor control
        // hdk_sdo_data             sdo_config_req;      // SDO config

        // Configuration properties
};

} // namespace gmt

#endif   // _HdkMainCtrlBase_h_
