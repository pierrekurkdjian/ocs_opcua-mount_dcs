// GMT AUTO GENERATED CODE

#include "MountProxySetup.h"
#include "MountProxyBase.h"

using namespace std;
using namespace gmt;

MountProxyBase::MountProxyBase(
                            const string& comp_uri,
                            const string& comp_name,
                            const string& comp_host,
                            int comp_port,
                            const string& comp_acl,
                            double comp_scan_rate,
                            int comp_prio,
                            int comp_stack_size)
    : OpcuaProxy(comp_uri, comp_name, comp_host, comp_port, comp_acl, comp_scan_rate, comp_prio, comp_stack_size)

{
}

MountProxyBase::~MountProxyBase()
{
}

void MountProxyBase::create_state()
{
    //create the features inherited from the base class
    Base::create_state();

    // //create the input dataio of the class, and assign the default value
    // new_input_dataio(operator_leds,             "operator_leds",         hdk_hmi_leds());
    // new_input_dataio(motor_ctrl,                "motor_ctrl",            hdk_motor_control());
    // new_input_dataio(sdo_in,                    "sdo_in",                hdk_sdo_data());
    //
    // //create the output dataio of the class, and assign the default value
    // new_output_dataio(operator_buttons,          "operator_buttons",      hdk_hmi_buttons());
    // new_output_dataio(temperatures,              "temperatures",          hdk_temp_measurements());
    // new_output_dataio(motor_state,               "motor_state",           hdk_motor_status());
    // new_output_dataio(sdo_out,                   "sdo_out",               hdk_sdo_data());
    //
    // //create the state vars of the class and assign the "class" default value
    //
    // //create the properties of the class and assign the "class" default value
}

//reads and unpacks the configuration file, and calls the setup() method with
//the decoded configuration
void MountProxyBase::configure_from_file (const std::string& fname)
{
    try
    {
        log_info ("Configure from file "+fname);
        Setup conf;

        load_conf_file (fname, conf);
        setup_wrapper (conf);
    }
    catch (std::exception& ex)
    {
        throw std::runtime_error("ERROR while opening configuration file "+fname+": "+ex.what());
    }
    catch (...)
    {
        throw std::runtime_error("ERROR while opening configuration file "+fname);
    }

    log_info ("Configuration applied!");
}

void MountProxyBase::setup_state(ComponentSetup& config)
{
    Setup::StateVarConf&  sv_conf        = dynamic_cast<Setup&>(config).state_vars;
    Setup::InputConf&     input_confs    = dynamic_cast<Setup&>(config).inputs;
    Setup::OutputConf&    output_confs   = dynamic_cast<Setup&>(config).outputs;
    Setup::PropertyConf&  property_confs = dynamic_cast<Setup&>(config).properties;

    log_info("state setup");

    // // create inputs
    // new_input_dataio(operator_leds,             "operator_leds",         input_confs.operator_leds);
    // new_input_dataio(motor_ctrl,                "motor_ctrl",            input_confs.motor_ctrl);
    // new_input_dataio(sdo_in,                    "sdo_in",                input_confs.sdo_in);
    // new_input_dataio(sdo_read_update_req,       "sdo_read_update_req",   input_confs.sdo_read_update_req);
    // new_input_dataio(sdo_write_enable,          "sdo_write_enable",      input_confs.sdo_write_enable);
    // new_input_dataio(slave_state_req,           "slave_state_req",       input_confs.slave_state_req);
    //
    // // create outputs
    // new_output_dataio(operator_buttons,         "operator_buttons",      output_confs.operator_buttons);
    // new_output_dataio(temperatures,             "temperatures",          output_confs.temperatures);
    // new_output_dataio(motor_state,              "motor_state",           output_confs.motor_state);
    // new_output_dataio(sdo_out,                  "sdo_out",               output_confs.sdo_out);
    // new_output_dataio(sdo_read_update_done,     "sdo_read_update_done",  output_confs.sdo_read_update_done);
    // new_output_dataio(slave_state_result,       "slave_state_result",    output_confs.slave_state_result);
    //
    // // Create state variables
    // new_state_var(op_state,                     "op_state",              sv_conf.op_state,             input_confs.op_state_goal,    output_confs.op_state_value);
    //
    // // Create properties
    // new_property(uri,                           "uri",                   property_confs.uri);
    // new_property(name,                          "name",                  property_confs.name);
    // new_property(host,                          "host",                  property_confs.host);
    // new_property(port,                          "port",                  property_confs.port);
    // new_property(scan_rate,                     "scan_rate",             property_confs.scan_rate);
    // new_property(acl,                           "acl",                   property_confs.acl);
    // new_property(priority,                      "priority",              property_confs.priority);
    // new_property(ecat_cfg_name,                 "ecat_cfg_name",         property_confs.ecat_cfg_name);
    //
    // // create data_object references
    // create_data_object_ref(operator_leds.pilot,                     "pilot");
    // create_data_object_ref(operator_leds.emergency_light,           "emergency_light");
    // create_data_object_ref(operator_leds.heartbeat,                 "heartbeat");
    // create_data_object_ref(operator_leds.counter,                   "counter");
    // // create_data_object_ref(motor_ctrl.enable,                       "motor_enable");
    // // create_data_object_ref(motor_ctrl.reset,                        "motor_reset");
    // // create_data_object_ref(motor_ctrl.velocity,                     "motor_velocity");
    // create_data_object_ref(sdo_in.the_sdo,                    "the_rx_sdo");
    // //create_data_object_ref(sdo_in.sensor_type_2,                    "sensor_type_2");
    // create_data_object_ref(operator_buttons.red_push_button,        "red_push_button");
    // create_data_object_ref(operator_buttons.green_push_button,      "green_push_button");
    // create_data_object_ref(operator_buttons.emergency_button,       "emergency_button");
    // create_data_object_ref(temperatures.temp_sensor1,               "temp_sensor1");
    // create_data_object_ref(temperatures.temp_sensor2,               "temp_sensor2");
    // // create_data_object_ref(motor_state.ready,                       "motor_ready");
    // // create_data_object_ref(motor_state.enabled,                     "motor_enabled");
    // // create_data_object_ref(motor_state.warning,                     "motor_warning");
    // // create_data_object_ref(motor_state.error,                       "motor_error");
    // // create_data_object_ref(motor_state.moving_positive,             "motor_moving_positive");
    // // create_data_object_ref(motor_state.moving_negative,             "motor_moving_negative");
    // create_data_object_ref(sdo_out.the_sdo,                   "the_tx_sdo");
    // //create_data_object_ref(sdo_out.sensor_type_2,                   "sensor_type_2");
}
