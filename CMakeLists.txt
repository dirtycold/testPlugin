cmake_minimum_required(VERSION 2.8)
project(testPlugin)

include_directories(3rdparty/plugin/include)

add_executable("PluginLoader" loader.cpp)
target_link_libraries("PluginLoader" dl)
add_library("Plugin" SHARED plugin.cpp)
