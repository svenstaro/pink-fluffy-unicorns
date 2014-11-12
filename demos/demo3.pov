// -----------------------------------------------------------------------CSG-demo3
// Uebungen zur Constructive Solid Geometry (CSG) 
// Beispiel: zwei individuelle durchsichtige Kugeln, ineinander "gesteckt" 
//           individuell animiert  

#include "colors.inc"
background { White }
camera {
  location <0, 1, -10>
  look_at <0, 0, 0> 
  angle 36
}
light_source { <500, 500, -1000> White } 

sphere { 0, 1 
  pigment { Green transmit 0.75 }
  translate -.5*x 
  rotate y*360*clock
} 
sphere { 0, 1 
  pigment { Red transmit 0.75 }
  translate +.5*x 
  rotate y*360*clock
}
