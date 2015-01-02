#local title_text = text {
    ttf "timrom.ttf" "Test" 4.5, 0
    texture{ Polished_Chrome
        normal { bumps 0.5 scale 0.005}
        finish{specular 1 reflection 0.55}
    }
}

#local intro_text2 = text {
    ttf "timrom.ttf", // Font
    "WiSe 2014/2015", // Text
    9,
    0
    texture{ Polished_Chrome
        normal { bumps 0.5 scale 0.005}
        finish{specular 1 reflection 0.55}
    }
    scale 0.5
}

#local authors_text = text {
    ttf "timrom.ttf", // Font
    "Authors: ", // Text
    4.5,
    0
    texture{ Polished_Chrome
        normal { bumps 0.5 scale 0.005}
        finish{specular 1 reflection 0.55}
    }
    scale 0.4
}

#local author_arne = text {
    ttf "timrom.ttf", // Font
    "Arne Beer", // Text
    4.5,
    0
    texture{ Polished_Chrome
        normal { bumps 0.5 scale 0.005}
        finish{specular 1 reflection 0.55}
    }
    scale 0.4
}

#local author_rafael = text {
    ttf "timrom.ttf", // Font
    "Rafael Epplee", // Text
    4.5,
    0
    texture{ Polished_Chrome
        normal { bumps 0.5 scale 0.005}
        finish{specular 1 reflection 0.55}
    }
    scale 0.4
}

#local author_sven = text {
    ttf "timrom.ttf", "Sven-Hendrik Haase", 4.5, 0
    texture{ Polished_Chrome
        normal { bumps 0.5 scale 0.005}
        finish{specular 1 reflection 0.55}
    }
    scale 0.4
}

#switch (clock)
    #range (0,120)
        #local Fadein = 1-(1/120)*clock;
        #local Fadeout = 0;
        object { title_text
            translate<-0.9,0,clock+40*Fadein-5*Fadeout>
        }
        object { intro_text2 
            translate<-1.8,-1,clock+40*Fadein-5*Fadeout>
        }
    #break
    #range (120, 240)
        #local Fadein = 0;
        #local Fadeout = 0;
        object { title_text
            translate<-0.9,0,clock+40*Fadein-5*Fadeout>
        }
        object { intro_text2 
            translate<-1.8,-1,clock+40*Fadein-5*Fadeout>
        }
    #break
    #range (240, 480)
        #local Fadein = 0;
        #local Fadeout = (1/240)*mod(clock, 240);
        object { title_text
            translate<-0.9,0,clock+40*Fadein-5*Fadeout>
        }
        object { intro_text2 
            translate<-1.8,-1,clock+40*Fadein-5*Fadeout>
        }
    #range (360, 720)
        #local Fadein = 1-(1/360)*mod(clock, 360);
        #local Fadeout = 0;
        object { authors_text 
            translate<-2,0.6,clock+15*Fadein-5*Fadeout>
        }
        object { author_arne 
            translate<-0.9,0,clock+15*Fadein-5*Fadeout>
        }
        object { author_rafael
            translate<-1.2,-0.6,clock+15*Fadein-5*Fadeout>
        }
        object { author_sven 
            translate<-1.7,-1.2,clock+15*Fadein-5*Fadeout>
        }
    #break
    #range (720,840)
        #local Fadein = 0;
        #local Fadeout = 0;
        object { authors_text 
            translate<-2,0.6,clock+15*Fadein-5*Fadeout>
        }
        object { author_arne 
            translate<-0.9,0,clock+15*Fadein-5*Fadeout>
        }
        object { author_rafael
            translate<-1.2,-0.6,clock+15*Fadein-5*Fadeout>
        }
        object { author_sven 
            translate<-1.7,-1.2,clock+15*Fadein-5*Fadeout>
        }
    #break
    #range (840, 1080)
        #local Fadein = 0;
        #local Fadeout = (1/240)*mod(clock+120, 240);
        object { authors_text 
            translate<-2,0.6,clock+15*Fadein-5*Fadeout>
        }
        object { author_arne 
            translate<-0.9,0,clock+15*Fadein-5*Fadeout>
        }
        object { author_rafael
            translate<-1.2,-0.6,clock+15*Fadein-5*Fadeout>
        }
        object { author_sven 
            translate<-1.7,-1.2,clock+15*Fadein-5*Fadeout>
        }
    #break
#end


