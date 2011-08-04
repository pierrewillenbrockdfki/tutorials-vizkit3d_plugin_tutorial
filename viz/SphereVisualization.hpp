#ifndef SphereVisualization_H
#define SphereVisualization_H

#include <boost/noncopyable.hpp>
#include <vizkit/VizPlugin.hpp>
#include <osg/Geode>
#include <osg/PositionAttitudeTransform>
#include <base/eigen.h>

namespace vizkit
{
    class SphereVisualization
        : public vizkit::VizPlugin<base::Vector3d>
        , boost::noncopyable
    {
    public:
        SphereVisualization();
        ~SphereVisualization();
        void setTransparency(float f);

    protected:
        virtual osg::ref_ptr<osg::Node> createMainNode();
        virtual void updateMainNode(osg::Node* node);
        virtual void updateDataIntern(base::Vector3d const& value);
        
    private:
        osg::ref_ptr<osg::PositionAttitudeTransform> spherePos;
        float transparency;
        struct Data;
        Data* p;
    };
}
#endif
