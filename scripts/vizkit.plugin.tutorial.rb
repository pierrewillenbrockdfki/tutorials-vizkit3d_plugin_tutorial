require 'vizkit'
require 'Qt4'
require 'vizkittypelib'
include Orocos
Orocos.initialize

# create an instance of the vizkit main window
# alternatively vizkit::QVizkitWidget could also be used
widget = Vizkit.default_loader.create_widget("vizkit::QVizkitMainWindow")
plugin = widget.createPlugin("vizkit_plugin_tutorial", "SphereVisualization")

# use a configuration method of the plugin to set the transparency of the sphere
plugin.setTransparency(1.0)

# create an instance of the base type Vectro3d
position = Types::Base::Vector3d.new

# a global index
i = 0.0
# initialize timer
timer = Qt::Timer.new
timer.connect(SIGNAL('timeout()')) do
    i += 1.0
    j = i / 200.0
    position.x = Math::cos(j) * j
    position.y = Math::sin(j) * j
    position.z = 0.5
    
    plugin.updatePosition(position)
end

# start the timer with a timeout of 10 ms
timer.start(10)

widget.show
Vizkit.exec 
