require 'vizkit'
Orocos.initialize

#register plugin 
Vizkit.default_loader.register_3d_plugin 'SphereViz',
    'vizkit3d_plugin_tutorial', 'SphereVisualization'

#create plugin
plugin = Vizkit.default_loader.SphereViz

# use a configuration method of the plugin to set the transparency of the sphere
plugin.Transparency = 1.0

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
Vizkit.exec 
