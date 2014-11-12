#include "colors.inc"
#include "shapes.inc"

camera {
    location <0, 2, -3>
    look_at <0, 1, 2>
}

sphere {
    <0, 1, 2>, 2
    texture {
        pigment { color Yellow }
    }
}

light_source { <2, 4, -3> color White }

box {
    <-1, 0, -1>
    <1, 0.5, 3>
    texture {
        pigment { color Red }
    }
    rotate y*20
}
