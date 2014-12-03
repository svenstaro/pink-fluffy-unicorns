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
#include "scene/starfield.inc"

global_settings { assumed_gamma 2.2 }
global_settings { ambient_light rgb<1, 1, 1> }

camera {
    location <0, 0, -3.5+clock>
    direction <0, 0, 1>
}

#for (i , -1, 1, 1)
    light_source {  <i*3, 0, -1+clock>
                    rgb <1,1,1>
                    fade_distance 2
                    fade_power 1}
#end

#switch (clock)
    #range (0,99)
        #local Fadein = 1
        #local Fadeout = 0;
        #include "scene/title.inc"
    #break
    #range (100, 199)
        #local Fadein = 1
        #local Fadeout = mod(clock, 100);
        #include "scene/title.inc"
    #break
#end

light_source { <0, 0, -3> color White }

fog {
    distance 100
}
