#include "SphereVisualization.hpp"

using namespace vizkit;

struct SphereVisualization::Data {
    // Copy of the value given to updateDataIntern.
    //
    // Making a copy is required because of how OSG works
    base::Vector3d data;
};


SphereVisualization::SphereVisualization()
    : p(new Data)
{
}

SphereVisualization::~SphereVisualization()
{
    delete p;
}

osg::ref_ptr<osg::Node> SphereVisualization::createMainNode()
{
    // Geode is a common node used for vizkit plugins. It allows to display
    // "arbitrary" geometries
    return new osg::Geode();
}

void SphereVisualization::updateMainNode ( osg::Node* node )
{
    osg::Geode* geode = static_cast<osg::Geode*>(node);
    // Update the main node using the data in p->data
}

void SphereVisualization::updateDataIntern(base::Vector3d const& value)
{
    p->data = value;
}

