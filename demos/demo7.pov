// -----------------------------------------------------------------------CSG-demo7
// Uebungen zur Constructive Solid Geometry (CSG) 
// Beispiel: zwei Kugeln,                           Differenz (difference) 
//           gemeinsam animiert                     ~~~~~~~~~~~~~~~~~~~~~~ 

#include "colors.inc"
background { Cyan }
camera {
  location <0, 1, -10>
  look_at <0, 0, 0> 
  angle 36
}
light_source { <500, 500, -1000> White } 

difference {
  sphere { 0, 1 
    pigment { Green }
    translate -.5*x 
  } 
  sphere { 0, 1 
    pigment { Red }
    translate +.5*x 
  }
  rotate y*360*clock
}
