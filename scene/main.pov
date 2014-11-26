#version 3.7;

#macro Beat_Location()
    mod((clock+33.96)*10000, 28.14*10000)/(28.14*10000)
#end

#include "colors.inc"
#include "shapes.inc"
#include "textures.inc"
#include "glass.inc"
#include "metals.inc"
#include "golds.inc"

#include "rad_def.inc"

#include "scene/ship.inc"
#include "scene/title.inc"

global_settings { assumed_gamma 2.2 }

camera {
    location <0, 0, -3.5>
    look_at <0, 0, 0>
}
light_source { <0, 0, -3> color White }

