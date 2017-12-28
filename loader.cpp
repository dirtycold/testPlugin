#include <iostream>

#include "Plugin/PluginLoader.h"
#include "Plugin/IPlugin.h"

int main(int argc, char* argv[])
{
    using namespace std;
    cout << "PluginLoader" << endl;
    cout << "==================" << endl;

    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " ./path/myPlugin.<ext>" << endl;
        return 0;
    }

    string pluginPath(argv[1]);

    Plugin::PluginLoader<Plugin::IPlugin> loader(pluginPath);
    Plugin::IPlugin* plugin = nullptr;

    bool isLoaded = loader.load();

    if(isLoaded)
    {
        plugin = loader.getPluginInstance();
    }

    if (plugin)
    {
        cout << "Plugin name    = " << plugin->name() << endl;
        cout << "Plugin version = " << plugin->version () << endl;
    }
    else
    {
        cout << "Failed to load plugin = " << pluginPath << endl;
        cout << "Reason = " << loader.getErrorMsg() << endl;
    }
    return 0;
}
