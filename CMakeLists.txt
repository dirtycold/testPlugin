cmake_minimum_required(VERSION 2.8)
project(testPlugin)

include_directories(3rdparty/plugin/include)

add_executable("PluginLoader" loader.cpp)
add_library("Plugin" SHARED plugin.cpp)

if(UNIX)
    target_link_libraries("PluginLoader" dl)
endif()
