#version 3.7;

#include "colors.inc"
#include "shapes.inc"
#include "rad_def.inc"

#include "debug.inc"

#include "scene/ship.inc"

global_settings { assumed_gamma 2.2 }

#warning Str(clock)
#warning Str(mod(clock*10000, 28.14*10000)/10000)

camera {
    location <0, 2, -3>
    look_at <0, 1, 2>
}

sphere {
    <0, 1, 2>, 2
    texture {
        pigment { color rgb <mod((clock+33.96)*10000, 28.14*10000)/(28.14*10000), 1.0, 1.0> }
    }
}

light_source { <2, 4, -3> color White }
