#include <string>
#include <memory>

#include <ocs_core_fwk.h>

#include "./mount_main_ctrl/MountMainCtrl.h"
#include "./mount_proxy/MountProxy.h"

using namespace std;
using namespace gmt;

class MountCtrlPkgApp : public CoreApplication
{
    public:

        MountCtrlPkgApp();

        virtual ~MountCtrlPkgApp();

        virtual void start(int argc, char* argv[]);

    protected:

        CLIHandler cli;
};

MountCtrlPkgApp::MountCtrlPkgApp()
 : CoreApplication()
 , cli("MountCtrlPkg application", "GMT_")
{
    //setup command line
    cli.add_option<string> ("config",  "Name of the configuration snapshot to apply", "default", "")
       .add_option<string> ("logging", "Logging level", "info")
       .add_option<string> ("ctnr_config", "Name of the container configuration file", "default")
       .add_option<void>   ("help",    "Show help");

    auto cntr = make_unique<CoreContainer>();

    // create hdk_main_ctrl instances
    cntr->add (make_unique<MountMainCtrl>("gmt://127.0.0.1/opcua-mount_dcs/mount_main_ctrl", "mount_main_ctrl", "127.0.0.1", 8020, "PRIVATE", 100));

    // create hdk_hw_adapter instances
    cntr->add (make_unique<MountProxy>("gmt://127.0.0.1/opcua-mount_dcs/mount_proxy", "mount_proxy", "127.0.0.1", 9020, "PRIVATE", 100));

    // create hdk_ctrl_app instances


    this->add (std::move(cntr));
}

MountCtrlPkgApp::~MountCtrlPkgApp()
{
}

void MountCtrlPkgApp::start(int argc, char* argv[])
{
    CoreApplication::initialize_rt_system();

    cli.parse_cmd_line (argc, argv, true);

    if (cli.is_opt("help"))
    {
        cout<<cli<<endl;
    }
    else
    {
        auto cli_opts = cli.get_opt_values();
        configure (*cli_opts);
        CoreApplication::start ();
    }
}

int main (int argc, char* argv[])
{
    //create the application
    MountCtrlPkgApp mount_ctrl_pkg_app;

    try
    {
        //configure and start the application
        mount_ctrl_pkg_app.start (argc, argv);

        //wait until execution end
        mount_ctrl_pkg_app.wait();
    }
    catch(std::runtime_error& e) { cerr<<"ERROR in mount_ctrl_pkg_app: "<<e.what()<<endl;            }
    catch(std::exception& e)     { cerr<<"ERROR in mount_ctrl_pkg_app: "<<e.what()<<endl;            }
    catch(...)                   { cerr<<"ERROR in mount_ctrl_pkg_app: unknown exception"<<endl; }

    return 0;
}
