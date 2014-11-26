#version 3.7;

#declare RandomSeed = seed(1337);

#declare Beat1_Start = 33.96;
#declare Beat1_Period = 28.14;

#macro Beat1()
    mod((clock + Beat1_Start) * 10000, Beat1_Period * 10000) / (Beat1_Period * 10000)
#end

#include "colors.inc"
#include "shapes.inc"
#include "textures.inc"
#include "glass.inc"
#include "metals.inc"
#include "golds.inc"

#include "rad_def.inc"
#include "rand.inc"

#include "scene/ship.inc"
#include "scene/title.inc"
#include "scene/starfield.inc"

global_settings { assumed_gamma 2.2 }

camera {
    location <0, 0, -3.5>
    look_at <0, 0, 0>
}
light_source { <0, 0, -3> color White }

