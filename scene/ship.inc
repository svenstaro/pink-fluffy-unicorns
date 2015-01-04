#local core_width = 1.5;
#local core_length = 8;
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
        pigment {
            color Blue
        }
    }
    rotate -90*x
}

#local base = union {
    box {
        <0, 0, 0>
        <core_length, 2, core_width/2>
    }
    box {
        <0, 0, 0>
        <4, 0.5, core_width/2>
        translate <0.5, 2, 0>
    }
    object {
        engine
        scale 1.6*x
        translate <1, 0.2, 1+core_width/2>
    }
    object {
        engine
        scale 1.5*y
        translate <1, 0.1, 2+core_width/2>
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

union {
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

    pigment {
        color rgb<0.1, 0.1, 0.14>
    }
    scale 0.25
    rotate 30*y
    rotate -10*x
    translate <0, 0, clock>
}


