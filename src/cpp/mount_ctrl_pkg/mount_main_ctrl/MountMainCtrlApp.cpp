#include "MountMainCtrl.h"

using namespace std;
using namespace gmt;

void run() {
    try
    {
        // create instances
        MountMainCtrl mount_main_ctrl("gmt://127.0.0.1/opcua-mount_dcs/mount_main_ctrl", "mount_main_ctrl", "127.0.0.1", 8020, "PRIVATE", 100);

        // start instances
        mount_main_ctrl.start();

        // wait until components finish
        mount_main_ctrl.wait();
    }
    catch(std::runtime_error& e) { cerr<<"ERROR in mount_main_ctrl_app: "<<e.what()<<endl;            }
    catch(std::exception& e)     { cerr<<"ERROR in mount_main_ctrl_app: "<<e.what()<<endl;            }
    catch(...)                   { cerr<<"ERROR in mount_main_ctrl_app: unknown exception"<<endl; }
}

int main() {
    run();
    return(0);
}
