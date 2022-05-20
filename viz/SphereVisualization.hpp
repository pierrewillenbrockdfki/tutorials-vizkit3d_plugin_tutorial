#ifndef SphereVisualization_H
#define SphereVisualization_H

#include <boost/noncopyable.hpp>
#include <vizkit3d/Vizkit3DPlugin.hpp>
#include <osg/Geode>
#include <osg/PositionAttitudeTransform>
#include <osg/ShapeDrawable>
#include <base/Eigen.hpp>

namespace vizkit3d
{
    class SphereVisualization
        : public vizkit3d::Vizkit3DPlugin<base::Vector3d>
        , boost::noncopyable
    {
    Q_OBJECT
    Q_PROPERTY(double Transparency READ getTransparency WRITE setTransparency)

    public:
        SphereVisualization();
        ~SphereVisualization();
        void setTransparency(double f);
        double getTransparency();

        Q_INVOKABLE void updatePosition(base::Vector3d const &value)
        {Vizkit3DPlugin<base::Vector3d>::updateData(value);}

    protected:
        virtual osg::ref_ptr<osg::Node> createMainNode();
        virtual void updateMainNode(osg::Node* node);
        virtual void updateDataIntern(base::Vector3d const& value);
        
    private:
        osg::ref_ptr<osg::PositionAttitudeTransform> spherePos;
        osg::ref_ptr<osg::ShapeDrawable> sd;
        float transparency;
        struct Data;
        Data* p;
    };

    VizkitQtPlugin(SphereVisualization)
}
#endif
