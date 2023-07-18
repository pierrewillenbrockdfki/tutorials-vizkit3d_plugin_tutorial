#include "SphereVisualization.hpp"
#include <osg/Geometry>

using namespace vizkit3d;


struct SphereVisualization::Data {
    // Copy of the value given to updateDataIntern.
    //
    // Making a copy is required because of how OSG works
    base::Vector3d data;
};


SphereVisualization::SphereVisualization()
    : transparency(1.0),p(new Data)
{
}

SphereVisualization::~SphereVisualization()
{
    delete p;
}

osg::ref_ptr<osg::Node> SphereVisualization::createMainNode()
{
    // create a sphere with radius 0.5
    osg::ref_ptr<osg::Sphere> sp = new osg::Sphere(osg::Vec3d(0,0,0), 0.5);
    sd = new osg::ShapeDrawable(sp.get());
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

void SphereVisualization::setTransparency(double f)
{
    transparency = f;
    if(sd.valid())
        sd->setColor(osg::Vec4(0.0f, 0.59f, 0.59f, transparency));
    emit propertyChanged("Transparency");
}

double SphereVisualization::getTransparency()
{
    return transparency;
}

namespace vizkit3d
{
VizkitQtPluginImpl(SphereVisualization)
}
