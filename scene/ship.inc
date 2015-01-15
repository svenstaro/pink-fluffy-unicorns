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

#local hand = union {
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
    object { half }
    object {
        half
        scale -1*z
    }
}

#local arm = union {
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
        hand
        translate <core_width, 0, core_width+core_length/24>
        rotate 10*y
    }
    rotate -7*y
    rotate 40*x
    translate <core_length*2/3, 0, core_width/4>
}

#local ship = union {
    object { base }
    object { head }
    object { arm }

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
        arm
        scale -1*z
    }

    object {
        engine
        scale 1.5*y
        translate <1, 0.1, 2+core_width/2>
        pigment {
            rgb <0, 0.95, 0.95>
        }
        finish { ambient 0.5 }
    }

    object {
        engine
        scale 1.6*x
        translate <1, 0.2, 1+core_width/2>
        pigment {
            rgb <0.95, 0, 0.3>
        }
        finish { ambient 0.5 }
    }

    object {
        engine
        scale 1.6*x
        translate <1, 0.2, -(core_width/2)>
        pigment {
            rgb <0.45, 0.95, 0>
        }
        finish { ambient 0.5 }
    }

    object {
        engine
        scale 1.5*y
        translate <1, 0.1, -(1+core_width/2)>
        pigment {
            rgb <1, 0.455, 0>
        }
        finish { ambient 0.6 }
    }

    object {
        engine
        scale 1.6*x
        //scale -1*z
        translate <1, 0.2, 1+core_width/2>
    }

    object {
        engine
        scale 1.5*y
        //scale -1*z
        translate <1, 0.1, 2+core_width/2>
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

#switch (clock)
    #range (start_break_down_fade, start_part2_fade)
        object { ship }
    #break
    #range (start_part2_fade, end_song)
        object { ship
            rotate 90*y
            translate <0, 0, start_part2_fade - clock>
        }
    #break
#end
