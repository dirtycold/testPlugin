#include "Plugin/IPlugin.h"
#include "Plugin/PluginFactory.h"

using namespace std;

class MyPlugin : public Plugin::IPlugin
{
public:
    MyPlugin() : Plugin::IPlugin () {}
    virtual ~MyPlugin() {}

    virtual const string& name() const override;
    virtual const Version& version() const override;

private:
    std::string _name {"MyPlugin"};
    Version _version {1, 0, 0, 1};
};



const string &MyPlugin::name() const
{
    return _name;
}

const Version &MyPlugin::version() const
{
    return _version;
}

PLUGIN_FACTORY_DECLARATION(MyPlugin)
PLUGIN_FACTORY_DEFINITION(MyPlugin)
