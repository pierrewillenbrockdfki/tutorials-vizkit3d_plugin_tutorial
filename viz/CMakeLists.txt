
rock_find_qt5(OPTIONAL)
rock_find_qt4(OPTIONAL)

if (ROCK_QT_VERSION_4)
    rock_vizkit_plugin(vizkit3d_plugin_tutorial-viz
        SphereVisualization.cpp
        DEPS vizkit3d_plugin_tutorial
        DEPS_PKGCONFIG base-types
        MOC SphereVisualization.hpp
        HEADERS SphereVisualization.hpp)
endif()
if (ROCK_QT_VERSION_5)
    rock_vizkit_plugin_qt5(vizkit3d_plugin_tutorial-viz-qt5
        SphereVisualization.cpp
        DEPS vizkit3d_plugin_tutorial
        DEPS_PKGCONFIG base-types
        MOC5 SphereVisualization.hpp
        HEADERS SphereVisualization.hpp)
endif()

