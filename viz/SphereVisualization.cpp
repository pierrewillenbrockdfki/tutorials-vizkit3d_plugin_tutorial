#include "SphereVisualization.hpp"
#include <osg/Geometry>
#include <osg/ShapeDrawable>

using namespace vizkit;

struct SphereVisualization::Data {
    // Copy of the value given to updateDataIntern.
    //
    // Making a copy is required because of how OSG works
    base::Vector3d data;
};


SphereVisualization::SphereVisualization()
    : p(new Data), transparency(1.0)
{
    /* Makes a method updatePosition availabe on ruby side, which will call
     * the updateData method for the data type base::Vector3d.
     * This macro is optional. */ 
    VizPluginRubyAdapter(SphereVisualization, base::Vector3d, Position)

    /* This macro makes the method 'setTransparency' with a float attribute
     * availabe in ruby, for configuration purposes */
    VizPluginRubyConfig(SphereVisualization, float, setTransparency)
}

SphereVisualization::~SphereVisualization()
{
    delete p;
}

osg::ref_ptr<osg::Node> SphereVisualization::createMainNode()
{
    // create a sphere with radius 0.5
    osg::ref_ptr<osg::Sphere> sp = new osg::Sphere(osg::Vec3d(0,0,0), 0.5);
    osg::ref_ptr<osg::ShapeDrawable> sd = new osg::ShapeDrawable(sp.get());
    // set a color
    sd->setColor(osg::Vec4(0.0f, 0.59f, 0.59f, transparency));
    osg::ref_ptr<osg::Geode> spGeode = new osg::Geode();
    spGeode->addDrawable(sd.get());
    // attach it to a parent which is a osg::PositionAttitudeTransform
    spherePos = new osg::PositionAttitudeTransform();
    spherePos->addChild(spGeode);

    return spherePos;
}

void SphereVisualization::updateMainNode ( osg::Node* node )
{
    // Update the main node using the data in p->data
    osg::Vec3d position(p->data.x(), p->data.y(), p->data.z());
    spherePos->setPosition(position);
}

void SphereVisualization::updateDataIntern(base::Vector3d const& value)
{
    p->data = value;
}

void SphereVisualization::setTransparency(float f)
{
    transparency = f;
}

//Macro that makes this plugin loadable in ruby, this is optional.
VizkitQtPlugin(SphereVisualization)
