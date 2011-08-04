#ifndef vizkit_plugin_tutorial_SphereVisualization_H
#define vizkit_plugin_tutorial_SphereVisualization_H

#include <boost/noncopyable.hpp>
#include <vizkit/VizPlugin.hpp>
#include <osg/Geode>

namespace vizkit
{
    class SphereVisualization
        : public vizkit::VizPlugin<base::Vector3d>
        , boost::noncopyable
    {
    public:
        SphereVisualization();
        ~SphereVisualization();

    protected:
        virtual osg::ref_ptr<osg::Node> createMainNode();
        virtual void updateMainNode(osg::Node* node);
        virtual void updateDataIntern(base::Vector3d const& plan);
        
    private:
        struct Data;
        Data* p;
    };
}
#endif
