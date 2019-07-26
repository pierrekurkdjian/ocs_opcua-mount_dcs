#include "MountMainCtrl.h"

using namespace std;
using namespace gmt;

MountMainCtrl::MountMainCtrl(
                            const string& comp_uri,
                            const string& comp_name,
                            const string& comp_host,
                            int comp_port,
                            const string& comp_acl,
                            double comp_scan_rate,
                            int comp_prio,
                            int comp_stack_size)
    : MountMainCtrlBase(comp_uri, comp_name, comp_host, comp_port, comp_acl, comp_scan_rate, comp_prio, comp_stack_size)
{
}

MountMainCtrl::~MountMainCtrl()
{
}

void MountMainCtrl::step()
{
    // if (!hmi_inputs_val.emergency_button) { motor_ctrl_req.velocity = 0; motor_ctrl_req.enable = false; }
    // else if (motor_state_val.ready && !motor_state_val.enabled) { motor_ctrl_req.enable = true; } // enable motor if not enabled
    //
    // if (motor_state_val.enabled)
    // {
    //     if (hmi_inputs_val.green_push_button) { motor_ctrl_req.velocity++; }
    //     if (hmi_inputs_val.red_push_button)   { motor_ctrl_req.velocity--; }
    //     if (!hmi_inputs_val.emergency_button) { motor_ctrl_req.velocity = 0; motor_ctrl_req.enable = false; }
    // }
    //
    // bool moving                     = motor_state_val.moving_positive || motor_state_val.moving_negative;
    // hmi_outputs_req.pilot           = moving; // pilot on when moving
    // hmi_outputs_req.emergency_light = !hmi_inputs_val.emergency_button; // ligth on when button pressed
    // float estimated_temperature = temperatures_val.temp_sensor1 / 10.0;  // 10.0 will be a property
    //
    // if (is_step_rate(100))    // every 1000 steps = 1 second
    // {
    //
    //     // following values should go to user interface
    //     log_info("Green button = " + std::to_string(hmi_inputs_val.green_push_button));
    //     log_info("Red button   = " + std::to_string(hmi_inputs_val.red_push_button));
    //     log_info("Emergency    = " + std::to_string(hmi_inputs_val.emergency_button));
    //     log_info("Temperature  = " + std::to_string(estimated_temperature));
    //     log_info("Temperature1 = " + std::to_string(temperatures_val.temp_sensor1));
    //     log_info("Temperature2 = " + std::to_string(temperatures_val.temp_sensor2));
    //     log_info("Axis Ready   = " + std::to_string(motor_state_val.ready));
    //     log_info("Axis Enabled = " + std::to_string(motor_state_val.enabled));
    //     log_info("Axis Warning = " + std::to_string(motor_state_val.warning));
    //     log_info("Axis Error   = " + std::to_string(motor_state_val.error));
    //     log_info("Axis Moving+ = " + std::to_string(motor_state_val.moving_positive));
    //     log_info("Axis Moving- = " + std::to_string(motor_state_val.moving_negative));
    // }
    //
    // if(is_step_rate(500))
    // {
    //     hmi_outputs_req.heartbeat = !hmi_outputs_req.heartbeat; // flip bit on each step to indicate component is alive
    // }
    //
    // hmi.value.input = hmi_inputs_val;
    // hmi.value.output = hmi_outputs_req;
    // motor.value.state = motor_state_val;
    // motor.value.command = motor_ctrl_req;
    // temperatures.value = temperatures_val;
}

void MountMainCtrl::setup()
{
    //setup async input handlers

    //ex: new_async_input_handler ("input_name", this, &HdkMainCtrl::input_handler);

    //add behaviors to features

    //other initializations

}
