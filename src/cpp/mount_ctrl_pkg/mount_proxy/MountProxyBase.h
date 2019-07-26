#ifndef _MountProxyBase_h_
#define _MountProxyBase_h_

#include <ocs_core_fwk.h>
#include <ocs_io_fwk.h>
#include "../../include/mount_dcs_port_types.h"

class MountProxySetup;

namespace gmt
{

class MountProxyBase : public OpcuaProxy
{
    public:
        MountProxyBase(
                        const  std::string& comp_uri,
                        const  std::string& comp_name,
                        const  std::string& comp_host,
                        int    comp_port,
                        const  std::string& comp_acl,
                        double comp_scan_rate = 1.0,
                        int comp_prio = GMT_THREAD_DEFAULT_PRIO,
                        int comp_stack_size = GMT_DEFAULT_STACK_SIZE);

        virtual ~MountProxyBase();

    protected:

        typedef MountProxySetup Setup;
        typedef OpcuaProxy Base;

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
        //
        // // Inputs declaration
        // hdk_hmi_leds             operator_leds;       // Human Machine Interface (HMI) digital outputs
        // hdk_motor_control        motor_ctrl;          // motor control
        // hdk_sdo_data             sdo_in;              // sdo set config values
        //
        // // Outputs declaration
        // hdk_hmi_buttons          operator_buttons;    // Human Machine Interface (HMI) digital inputs
        // hdk_temp_measurements    temperatures;        // temperature measurements
        // hdk_motor_status         motor_state;         // motor state
        // hdk_sdo_data             sdo_out;             // sdo get configured values
        //
        // // Configuration properties
};

} // namespace gmt

#endif   // _HdkHwAdapterBase_h_
