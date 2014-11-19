#version 3.7;

#include "colors.inc"
#include "shapes.inc"
#include "rad_def.inc"

#include "textures.inc"

#include "scene/ship.inc"

global_settings { assumed_gamma 2.2 }

#macro beatLocation()
    mod((clock+33.96)*10000, 28.14*10000)/(28.14*10000)
#end

camera {
    location <0, 2, -3>
    look_at <0, 1, 2>
}

light_source { <2, 4, -3> color White }
