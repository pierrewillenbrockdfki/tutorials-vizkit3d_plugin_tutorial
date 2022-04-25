# CMakeLists.txt has to be located in the project folder and cmake has to be
# executed from 'project/build' with 'cmake ../'.
cmake_minimum_required(VERSION 3.0)
project(vizkit3d_plugin_tutorial VERSION 0.1 DESCRIPTION "vizkit3d plugin tutorial")
find_package(Rock)
rock_init()
rock_find_qt5(Core)
rock_standard_layout()
