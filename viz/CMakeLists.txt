
rock_find_qt5(OPTIONAL)
rock_find_qt4(OPTIONAL)

include(RockQt)

rock_qt_vizkit_plugin(
    TARGETPREFIX vizkit3d_plugin_tutorial-viz
    QT4_SUFFIX ""
    SOURCES SphereVisualization.cpp
    MOC SphereVisualization.hpp
    HEADERS SphereVisualization.hpp
    DEPS vizkit3d_plugin_tutorial
    DEPS_PKGCONFIG base-types)
