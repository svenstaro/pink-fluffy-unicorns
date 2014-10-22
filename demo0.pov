// -----------------------------------------------------------------------CSG-demo0
// Uebungen zur Constructive Solid Geometry (CSG) 
// Beispiel: eine individuelle Kugel (links angeordnet) 

#include "colors.inc"
background { Cyan }
camera {
  location <0, 1, -10>
  look_at <0, 0, 0> 
  angle 36
}
light_source { <500, 500, -1000> White } 

sphere { 0, 1 
  pigment { Green } 
  translate -.5*x 
}
