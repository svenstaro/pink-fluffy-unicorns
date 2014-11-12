// -----------------------------------------------------------------------CSG-demo8
// Uebungen zur Constructive Solid Geometry (CSG) 
// Beispiel: L-Profil mit Bohrung  
//           (unterschiedliche Generierungsvarianten) 
//           (wie sehen die jeweiligen CSG-Baeume aus?)

global_settings { assumed_gamma 2.2 } 
global_settings { ambient_light rgb 1 } 
#include "colors.inc"
background { Cyan }
camera {
  location <6, 8, -10>
  look_at <0, 0, 0> 
  angle 36
}
light_source { <0, 600, -500> White } 

difference {          // Generierungsvariante 1
  union {
    box { 
      -.5, <.5 0 .5>
      pigment { Green } 
    } 
    box { 
      -.5*z, <-.5, .5, .5>  
      pigment { Green } 
    } 
  } 
  cylinder { 
    <.25, .5, 0> <.25, -.5, 0> .15 open 
    pigment { Yellow } 
  } 
  translate -1.5*x 
}

difference {          // Generierungsvariante 2
  difference {
    box { 
      -.5, .5 
      pigment { Green } 
    } 
    cylinder { 
      <.25, .5, 0> <.25, -.5, 0> .15 open 
      pigment { Yellow } 
    } 
  }
  box { 
    -.6, .6 
    translate <.6, .6, 0>
    pigment { Green } 
  } 
  translate 1.5*x 
}

union {               // Generierungsvariante 3 
  difference {
    box { 
      -.5, <.5 0 .5>
      pigment { Green } 
    } 
    cylinder { 
      <.25, .5, 0> <.25, -.5, 0> .15 open 
      pigment { Yellow } 
    } 
  } 
  box { 
    -.5*z, <-.5, .5, .5>  
    pigment { Green } 
  } 
  translate <0, -.5 -1.5> 
}

difference {          // Generierungsvariante 4 
  box { 
    -.5, .5 
    pigment { Green } 
  } 
  union {
    cylinder { 
      <.25, .5, 0> <.25, -.5, 0> .15 open 
      pigment { Yellow } 
    } 
    box { 
      -.6, .6 
      translate <.6, .6, 0>
      pigment { Green } 
    }
  } 
  translate <0, .5 1.5> 
}

