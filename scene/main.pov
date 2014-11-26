#version 3.7;

#macro beatLocation()
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

global_settings { assumed_gamma 2.2 }

camera {
    location <0, 0, -3.5>
    look_at <0, 0, 0>
}
light_source { <0, 0, -3> color White }

object{
    Circle_Text(
            "timrom.ttf", // Font
            "ROFL",// Text
            0.75 , // Size
            0.025, // Spacing
            15.00, // Thickness
            1.50,   // Radius
            1,       // Inverted
            Align_Left,// od. Align_Right, Align_Center
            180)     // Angle
        texture{ Polished_Chrome
            normal { bumps 0.5 scale 0.005}
            finish{specular 1 reflection 0.25}
        }
        rotate<0,0,360*clock*10000/(28.14*10000*4)>
        translate<0,0,0>
}// end of Circle_Text object

