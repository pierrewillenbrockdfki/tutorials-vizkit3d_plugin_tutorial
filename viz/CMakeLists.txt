rock_find_qt5(Core)

rock_vizkit_plugin(vizkit3d_plugin_tutorial-viz
    SphereVisualization.cpp
    DEPS vizkit3d_plugin_tutorial
    DEPS_PKGCONFIG base-types
    MOC SphereVisualization.hpp
    HEADERS SphereVisualization.hpp)

