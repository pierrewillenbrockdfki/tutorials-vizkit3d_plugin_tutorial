rock_library(vizkit3d_plugin_tutorial
    SOURCES Dummy.cpp
    HEADERS Dummy.hpp)

rock_executable(vizkit3d_plugin_tutorial_bin Main.cpp
    DEPS vizkit3d_plugin_tutorial)

