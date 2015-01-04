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

#include "scene/title.inc"

global_settings { assumed_gamma 2.2 }
global_settings { ambient_light rgb<1, 1, 1> }

camera {
    location <0, 0, -10>
    look_at 0
    #switch (clock)
        #range (2000, 3000)
            rotate mod(clock, 360)*y
        #break
    #end
    translate <0, 0, clock>
}

#switch (clock)
    #range (0, 1800)
        #include "scene/starfield.inc"
    #break
#end

#switch (clock)
    #range (800, 1680)
        #include "scene/title.inc"
    #break
#end

// Break down
#switch (clock)
    #range (1800, 2500)
        #include "scene/funky-sky.inc"
        #include "scene/ship.inc"
    #break
#end

light_source {
    <0, 0, -5*clock>, color White
}

fog {
    #switch (clock)
        // Scene fade-in
        #range (0, 800)
            distance Interpolate(clock, 0, 800, 0.01, 100, 1)
        #break
        #range (800, 1800)
            distance 100
        #break
        // Break down
        #range (1800, 2400)
            distance Interpolate(clock, 1800, 2400, 0.01, 100, 1)
            #local shade = Interpolate(clock, 1800, 2400, White, Black, 1);
            #local trans = Interpolate(clock, 1800, 2400, 0, 1, 1);
            color rgbt<shade.red, shade.blue, shade.green, trans>
        #break
    #end
}
