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
#include "scene/title.inc"

global_settings { assumed_gamma 2.2 }
global_settings { ambient_light rgb<1, 1, 1> }

camera {
    location <0, 0, -3.5+clock>
    direction <0, 0, 1>
}

#switch (clock)
    #range (800, 1680)
        #include "scene/title.inc"
    #break
#end

light_source {
    <0, 0, -5*clock>, color White
}

fog {
    #switch (clock)
        // Scene fade-in
        #range (0, 800)
            distance Interpolate(clock, 0, 800, 0, 100, 1)
        #break
        #else
            distance 30
        #break
    #end
}

