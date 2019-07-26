#include "MountProxy.h"

using namespace std;
using namespace gmt;

void run() {
    try
    {
        // create instances
        MountProxy mount_proxy("gmt://127.0.0.1/opcua-mount_dcs/opcua-mount_proxy", "mount_proxy", "127.0.0.1", 9020, "PRIVATE", 100);

        // start instances
        mount_proxy.start();

        // wait until components finish
        mount_proxy.wait();
    }
    catch(std::runtime_error& e) { cerr<<"ERROR in mount_hw_adapter_app: "<<e.what()<<endl;            }
    catch(std::exception& e)     { cerr<<"ERROR in mount_hw_adapter_app: "<<e.what()<<endl;            }
    catch(...)                   { cerr<<"ERROR in mount_hw_adapter_app: unknown exception"<<endl; }
}

int main() {
    run();
    return(0);
}
