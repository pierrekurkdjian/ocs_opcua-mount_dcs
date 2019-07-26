#include "MountProxy.h"

using namespace std;
using namespace gmt;

MountProxy::MountProxy(
                            const string& comp_uri,
                            const string& comp_name,
                            const string& comp_host,
                            int comp_port,
                            const string& comp_acl,
                            double comp_scan_rate,
                            int comp_prio,
                            int comp_stack_size)
    : MountProxyBase(comp_uri, comp_name, comp_host, comp_port, comp_acl, comp_scan_rate, comp_prio, comp_stack_size)
{
}

MountProxy::~MountProxy()
{
}

void MountProxy::step()
{
}

void MountProxy::setup()
{
}
