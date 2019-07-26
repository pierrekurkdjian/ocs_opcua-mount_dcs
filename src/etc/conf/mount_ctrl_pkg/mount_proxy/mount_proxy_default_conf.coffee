
module.exports =

    properties:
        uri: { name: 'uri', default_value: 'gmt://127.0.0.1/io_fwk/mount_proxy' , type: 'String', desc: 'Uri path for the component' }
        name: { name: 'name', default_value: 'mount_proxy' , type: 'String', desc: 'Name the component' }
        host: { name: 'host', default_value: '127.0.0.1' , type: 'String', desc: 'Default host for deployment.' }
        port: { name: 'port', default_value: 8011 , type: 'Integer', desc: 'Default configuration port' }
        scan_rate: { name: 'scan_rate', default_value: 100 , type: 'Float', desc: 'The scanning rate of the component loop in Hz. In each iteration of the loop the component must process its ports and health status. The estimation of the state variables, is defined by the state variable sampling rate and it may use an estimation model. The control of the state variable is defined by the state variable control rate. It must calculate the control output, if necessary with a control model. The scanning rate shall be always higher that the maximum of the sampling or control rate of any of its states variables' }
        acl: { name: 'acl', default_value: 'PRIVATE' , type: 'String', desc: 'Access Control List. List of namespaces that can issue a command to the controller. TBC' }
        priority: { name: 'priority', default_value: 0 , max: 100, type: 'Integer', desc: 'The priority property defines the relative priority between Component running in different Threads. The priority shall be interpreted higher when the value is higher. This property can be used by implementations that support real time behavior. When the property value is 0 the Component doesn&#x27;t require any real-time consideration by the implementation' }
        opcua_cfg_name: { name: 'opcua_cfg_name', default_value: 'opcua_default' , type: 'String', desc: 'Name of the configuration of the OPCUA field bus' }

    state_vars:
        op_state: { name: 'op_state', default_value: 'OFF', type: 'OperationalState', desc: 'Operational Mode State Variable' }

    inputs:
        op_state_goal:            { name: 'op_state_goal',            protocol: 'pull',  url: 'tcp://127.0.0.1:8110',  blocking_mode: 'sync', max_rate: 1,    nom_rate: 1,   owner: true     }
        TestBool_to_device:       { name: 'TestBool_to_device',       protocol: 'pull',  url: 'tcp://127.0.0.1:10127', blocking_mode: 'sync', max_rate: 1,    nom_rate: 1,   owner: true     }
        TestInt_to_device:        { name: 'TestInt_to_device',        protocol: 'pull',  url: 'tcp://127.0.0.1:20129', blocking_mode: 'sync', max_rate: 1,    nom_rate: 1,   owner: true     }
        TestFloat_to_device:      { name: 'TestFloat_to_device',      protocol: 'pull',  url: 'tcp://127.0.0.1:10131', blocking_mode: 'sync', max_rate: 1,    nom_rate: 1,   owner: true     }
        TestString_to_device:     { name: 'TestString_to_device',     protocol: 'pull',  url: 'tcp://127.0.0.1:10133', blocking_mode: 'sync', max_rate: 1,    nom_rate: 1,   owner: true     }

    outputs:
        op_state_value:           { name: 'op_state_value',           protocol: 'push',  url: 'tcp://127.0.0.1:8112',  blocking_mode: 'sync', max_rate: 1,    nom_rate: 1,   owner: false    }
        opcua_status:             { name: 'opcua_status',             protocol: 'push',  url: 'tcp://127.0.0.1:10121', blocking_mode: 'sync', max_rate: 1,    nom_rate: 1,   owner: false    }
        TestBool_from_device:     { name: 'TestBool_from_device',     protocol: 'push',  url: 'tcp://127.0.0.1:10128', blocking_mode: 'sync', max_rate: 1,    nom_rate: 1,   owner: false    }
        TestInt_from_device:      { name: 'TestInt_from_device',      protocol: 'push',  url: 'tcp://127.0.0.1:10130', blocking_mode: 'sync', max_rate: 1,    nom_rate: 1,   owner: false    }
        TestFloat_from_device:    { name: 'TestFloat_from_device',    protocol: 'push',  url: 'tcp://127.0.0.1:10132', blocking_mode: 'sync', max_rate: 1,    nom_rate: 1,   owner: false    }
        TestString_from_device:   { name: 'TestString_from_device',   protocol: 'push',  url: 'tcp://127.0.0.1:10134', blocking_mode: 'sync', max_rate: 1,    nom_rate: 1,   owner: false    }
