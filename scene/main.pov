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
global_settings { ambient_light rgb<1, 1, 1> }

camera {
    location <0, 0, -3.5>
    look_at <0, 0, 0>
}


#for (i , -1, 1, 1)
    light_source {  <i*3, 0, -1>
                    rgb <1,1,1>
                    fade_distance 2
                    fade_power 1}
#end 

