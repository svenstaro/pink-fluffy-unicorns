#local title = union {
    text {
        ttf "timrom.ttf" "Test" 5, 0
        texture{ Polished_Chrome
            normal { bumps 0.5 scale 0.005}
            finish{specular 1 reflection 0.55}
        }
        translate<-0.9, 0, 0>
    }
    text {
        ttf "timrom.ttf", "WiSe 2014/2015", 5, 0
        texture{ Polished_Chrome
            normal { bumps 0.5 scale 0.005}
            finish{specular 1 reflection 0.55}
        }
        scale 0.5
        translate<-1.8, -1, 0>
    }
}

#local authors = union {
    text {
        ttf "timrom.ttf", "Authors: ", 5, 0
        texture{ Polished_Chrome
            normal { bumps 0.5 scale 0.005}
            finish{specular 1 reflection 0.55}
        }
        translate<-5, 1, 0>
        scale 0.4
    }
    text {
        ttf "timrom.ttf", "Arne Beer", 5, 0
        texture{ Polished_Chrome
            normal { bumps 0.5 scale 0.005}
            finish{specular 1 reflection 0.55}
        }
        translate<-2, 0, 0>
        scale 0.4
    }
    text {
        ttf "timrom.ttf", "Rafael Epplee", 5, 0
        texture{ Polished_Chrome
            normal { bumps 0.5 scale 0.005}
            finish{specular 1 reflection 0.55}
        }
        translate<-2.7, -1, 0>
        scale 0.4
    }
    text {
        ttf "timrom.ttf", "Sven-Hendrik Haase", 5, 0
        texture{ Polished_Chrome
            normal { bumps 0.5 scale 0.005}
            finish{specular 1 reflection 0.55}
        }
        translate<-4, -2, 0>
        scale 0.4
    }
}

#switch (clock)
    #range (800, 919)
        #local Fadein = 1-(1/120)*mod(clock+40, 120);
        object { title
            translate<0,0,clock+40*Fadein>
        }
        #break
    #range (920, 1039)
        object { title
            translate<0,0,clock>
        }
        #break
    #range (1040, 1280)
        #local Fadeout = (1/240)*mod((clock+160), 240);
        object { title
            translate<0,0,clock-20*Fadeout>
        }
#end

#switch (clock)
    #range (1160, 1280)
        #local Fadein = 1-(1/120)*mod(clock+40, 120);
        object { authors
            translate<0,0,clock+40*Fadein>
        }
        #break
    #range (1280, 1400)
        object { authors
            translate<0,0,clock>
        }
        #break
    #range (1400, 1640)
        #local Fadeout = (1/240)*mod(clock+40, 240);
        object { authors
            translate<0,0,clock-20*Fadeout>
        }
        #break
#end
