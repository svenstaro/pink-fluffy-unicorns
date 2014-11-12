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
// -----------------------------------------------------------------------CSG-demo1
// Uebungen zur Constructive Solid Geometry (CSG) 
// Beispiel: eine individuelle Kugel (rechts angeordnet) 

#include "colors.inc"
background { Cyan }
camera {
  location <0, 1, -10>
  look_at <0, 0, 0> 
  angle 36
}
light_source { <500, 500, -1000> White } 

sphere { 0, 1 
  pigment { Red } 
  translate +.5*x 
} 
// -----------------------------------------------------------------------CSG-demo2
// Uebungen zur Constructive Solid Geometry (CSG) 
// Beispiel: zwei individuelle Kugeln, ineinander "gesteckt"
//           individuell animiert 

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
  rotate y*360*clock
}
sphere { 0, 1
  pigment { Red }
  translate +.5*x
  rotate y*360*clock 
}
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
// -----------------------------------------------------------------------CSG-demo4
// Uebungen zur Constructive Solid Geometry (CSG) 
// Beispiel: zwei durchsichtige Kugeln,                Vereinigung (union) 
//           gemeinsam animiert                        ~~~~~~~~~~~~~~~~~~~ 

#include "colors.inc"
background { White }
camera {
  location <0, 1, -10>
  look_at <0, 0, 0> 
  angle 36
}
light_source { <500, 500, -1000> White } 

union {
  sphere { 0, 1 
    pigment { Green transmit 0.75 }
    translate -.5*x 
  } 
  sphere { 0, 1 
    pigment { Red transmit 0.75 }
    translate +.5*x 
  }
  rotate y*360*clock
} 
// -----------------------------------------------------------------------CSG-demo5
// Uebungen zur Constructive Solid Geometry (CSG) 
// Beispiel: zwei durchsichtige Kugeln,                Vereinigung (merge) 
//           gemeinsam animiert                        ~~~~~~~~~~~~~~~~~~~ 

#include "colors.inc"
background { White }
camera {
  location <0, 1, -10>
  look_at <0, 0, 0> 
  angle 36
}
light_source { <500, 500, -1000> White } 

merge {
  sphere { 0, 1 
    pigment { Green transmit 0.75 }
    translate -.5*x 
  } 
  sphere { 0, 1 
    pigment { Red transmit 0.75 }
    translate +.5*x 
  }
  rotate y*360*clock
} 
// -----------------------------------------------------------------------CSG-demo6
// Uebungen zur Constructive Solid Geometry (CSG) 
// Beispiel: zwei Kugeln,                      Durchschnitt (intersection) 
//           gemeinsam animiert                ~~~~~~~~~~~~~~~~~~~~~~~~~~~ 

#include "colors.inc"
background { Cyan }
camera {
  location <0, 1, -10>
  look_at <0, 0, 0> 
  angle 36
}
light_source { <500, 500, -1000> White } 

intersection {
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

