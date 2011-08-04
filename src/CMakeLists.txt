rock_library(vizkit_plugin_tutorial
    SOURCES Dummy.cpp
    HEADERS Dummy.hpp)

rock_executable(vizkit_plugin_tutorial_bin Main.cpp
    DEPS vizkit_plugin_tutorial)

