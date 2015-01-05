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

#local start_part1_fade = 0;
#local end_part1_fade = 800;
#local start_break_down_fade = 1800;
#local end_break_down_fade = 2400;
#local start_part2_fade = 4920;
#local end_part2_fade = 5100;
#local end_song = 12724;

camera {
    location <0, 0, -10>
    look_at 0
    #switch (clock)
        #range (2500, 5000)
            rotate mod(clock/2, 360)*y
        #break
    #end
    translate <0, 0, clock>
}

#switch (clock)
    #range (0, start_break_down_fade)
        #include "scene/starfield.inc"
    #break
    #range (start_part2_fade, end_song)
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
    #range (1800, 5000)
        #include "scene/funky-sky.inc"
        #include "scene/ship.inc"
    #break
#end

light_source {
    <0, 0, -5*clock>, color <2, 2, 2>
}

fog {
    #switch (clock)
        // Part1 fade-in
        #range (start_part1_fade, end_part1_fade)
            distance Interpolate(clock, start_part1_fade, end_part1_fade, 0.01, 100, 1)
        #break

        #range (end_part1_fade, start_break_down_fade)
            distance 100
        #break

        // Break down
        #range (start_break_down_fade, end_break_down_fade)
            distance Interpolate(clock, start_break_down_fade, end_break_down_fade, 0.01, 100, 1)
            #local shade = Interpolate(clock, start_break_down_fade, end_break_down_fade, White, Black, 1);
            #local trans = Interpolate(clock, start_break_down_fade, end_break_down_fade, 0, 1, 1);
            color rgbt<shade.red, shade.blue, shade.green, trans>
        #break

        // Part2 fade-in
        #range (start_part2_fade, end_part2_fade)
            distance Interpolate(clock, start_part1_fade, end_part2_fade, 0.01, 100, 1)
        #break

        #range (end_part2_fade, start_break_down_fade)
            distance 100
        #break
    #end
}
