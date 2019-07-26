
#!/usr/bin/coffee
module.exports =
    devices: [
        { name: "device1", endpoint: "opc.tcp://172.16.10.71", port: 4840}
      ]

    nodes: [
        { node_name: "MAIN.TestBool",     node_namespace: 4,    device_name: "device1",    rx_data_name: "TestBool_to_device",      tx_data_name: "TestBool_from_device" }
        { node_name: "MAIN.TestInt",      node_namespace: 4,    device_name: "device1",    rx_data_name: "TestInt_to_device",       tx_data_name: "TestInt_from_device" }
        { node_name: "MAIN.TestFloat",    node_namespace: 4,    device_name: "device1",    rx_data_name: "TestFloat_to_device",     tx_data_name: "TestFloat_from_device" }
        { node_name: "MAIN.TestString",   node_namespace: 4,    device_name: "device1",    rx_data_name: "TestString_to_device",    tx_data_name: "TestString_from_device" }
    ]
