#include "math.inc"

#local core_width = 1.5;
#local core_length = 8;
#local core_height = 2;
#local head_length = 4;

#local engine = union {
    prism {
        0, 1, 5
        <0, 0>,
        <0, 1.5>,
        <1.8, 1.5>,
        <2, 0>,
        <0, 0>
        translate 0.2*x
    }
    box {
        <0, 0, 0>
        <0.2, 0.8, 1.3>
        translate <0, 0.1, 0.1>
    }
    rotate -90*x
}

#local base = union {
    box {
        <0, 0, 0>
        <core_length, core_height, core_width/2>
    }
}

#local head = union {
    box {
        <0, 0, 0>
        <head_length, 0.2, core_width/2>
        translate <core_length, 0.8, 0>
        pigment { color rgb<0.3, 0.3, 0.7-(Beat1()*0.4)> }
    }
    box {
        <0, 0, 0>
        <head_length, 1, core_width/2>
        translate <core_length, -0.2, 0>
    }
    prism {
        0, core_width/2, 4
        <0, 0>,
        <0, 1>,
        <head_length, 0>,
        <0, 0>
        rotate -90*x
        translate <core_length, 1, core_width/2>
    }
}

#macro init_hand(beat)
    #declare handUnion = union {
        #local hand_size = core_length/10;
        #local half = prism {
            0, hand_size*2/3, 6
            <0, 0>,
            <0, hand_size/4>,
            <hand_size/2, hand_size>
            <hand_size, hand_size*3/4>
            <hand_size, hand_size/2>
            <hand_size/2, hand_size*3/4>
        }
        object { 
            half
            rotate (beat*20)*y
        }
        object {
            half
            scale -1*z
            rotate (-beat*20)*y
        }
    }
#end

#macro init_arm(beat)
    init_hand(beat)
    #declare armUnion = union {
        box {
            <0, 0, 0>
            <core_length/15, core_length/15, core_width>
        }
        box {
            <-core_width*0.2, 0, core_width>
            <core_width, core_length/15, core_width+core_length/12>
            rotate 10*y
        }
        object {
            handUnion
            translate <core_width, 0, core_width+core_length/24>
            rotate 10*y
        }
        rotate -7*y
        rotate 40*x
        translate <core_length*2/3, 0, core_width/4>
    }
#end

#macro init_ship(beat)
    init_arm(beat)
    #declare shipunion = union {
        object { base }
        object { head }
        object { armUnion }

        // Mirror base and head
        object {
            base
            scale -1*z
        }
        object {
            head
            scale -1*z
        }
        object {
            armUnion
            scale -1*z
        }

        #local start_melody = 2700;
        #local end_melody = 4438;
        #local relative_clock = clip(clock - start_melody, 0, end_melody - start_melody);

        // Povray's mod doesn't return positive numbers for negative inputs, duh
        #macro fixed_mod(a, b)
            mod((mod(a, b) + b), b)
        #end

        #macro engine_alpha(duration, period, ox)
            clip(fixed_mod(relative_clock-duration-ox, period)-period+duration, 0, 0.8)
        #end

        #local period1 = 449;
        #local periodRest = 225;

        #local duration1 = 13.8;
        #local durationRest = 21;


        //#warning concat("##### RELATIVE CLOCK: ", Str(relative_clock))
        //#warning concat("##### STUFF: ", Str(fixed_mod(relative_clock-duration1, period)))
        //#warning concat("##### ENGINE ALPHA: ", Str(engine_alpha))

        // engines from left to right

        // cyan
        object {
            engine
            scale 1.5*y
            translate <1, 0.1, 2+core_width/2>
            pigment {
                rgb <0, 0.95, 0.95>
            }
            finish { ambient 0.2 +
                engine_alpha(duration1, period1, periodRest-duration1) +
                engine_alpha(durationRest, periodRest, durationRest*3) }
        }

        // magenta
        object {
            engine
            scale 1.6*x
            translate <1, 0.2, 1+core_width/2>
            pigment {
                rgb <0.95, 0, 0.3>
            }
            finish { ambient 0.2 +
                engine_alpha(durationRest, periodRest, 0) +
                engine_alpha(durationRest, periodRest, durationRest*4)}
        }

        // green
        object {
            engine
            scale 1.6*x
            translate <1, 0.2, -(core_width/2)>
            pigment {
                rgb <0.45, 0.95, 0>
            }
            finish { ambient 0.2 + engine_alpha(durationRest, periodRest, durationRest)}
        }

        // orange
        object {
            engine
            scale 1.5*y
            translate <1, 0.1, -(1+core_width/2)>
            pigment {
                rgb <1, 0.455, 0>
            }
            finish { ambient 0.2 + engine_alpha(durationRest, periodRest, durationRest*2)}
        }

        light_source {
            <core_length+head_length+2, core_height+2, 0>, color <5, 5, 5>
        }

        pigment {
            color rgb<0.1, 0.1, 0.14>
        }

        finish {
            ambient rgb 1
        }

        translate -(core_length/2)*x
        scale 0.3
    }
#end

#switch (clock)
    #range (start_break_down_fade, start_part2_fade)
        init_ship(0) 
        object { shipunion }
    #break
    #range (start_part2_fade, end_song)
        #declare ShipSpline = spline {
            natural_spline
            -0.2, <-2,1,-2>,//control point

            0.1, < 0,0,0>,//start point
            0.2, < 0,-2,0>,
            0.3, < -2,0,-2>,
            0.4, < 0,-2,0>,
            0.5, < 2,0,2>,
            0.6, < 0,1, 0>,
            0.7, < 2,1, 0>,
            0.8, < 0,1, 2>,
            0.9, < 1,1, 2>,
            1.0, < 2,1, 2>,//end point

            1.2, < 4,1, 2>//control point
        }
        init_ship((1-Beat2()))
        object { shipunion
            rotate 90*y
            Spline_Trans(ShipSpline, (clock-start_part2_fade)/60, y, 0.1, 0.5)
            translate <0, 0, start_part2_fade - clock>
        }
    #break
#end
