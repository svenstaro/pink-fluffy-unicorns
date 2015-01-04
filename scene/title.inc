#local title = union {
    text {
        ttf "timrom.ttf" "Test" 4.5, 0
        texture{ Polished_Chrome
            normal { bumps 0.5 scale 0.005}
            finish{specular 1 reflection 0.55}
        }
        translate<-0.9, 0, 0>
    }
    text {
        ttf "timrom.ttf", "WiSe 2014/2015", 9, 0
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
        ttf "timrom.ttf", "Authors: ", 4.5, 0
        texture{ Polished_Chrome
            normal { bumps 0.5 scale 0.005}
            finish{specular 1 reflection 0.55}
        }
        translate<-5, 1, 0>
        scale 0.4
    }
    text {
        ttf "timrom.ttf", "Arne Beer", 4.5, 0
        texture{ Polished_Chrome
            normal { bumps 0.5 scale 0.005}
            finish{specular 1 reflection 0.55}
        }
        translate<-2, 0, 0>
        scale 0.4
    }
    text {
        ttf "timrom.ttf", "Rafael Epplee", 4.5, 0
        texture{ Polished_Chrome
            normal { bumps 0.5 scale 0.005}
            finish{specular 1 reflection 0.55}
        }
        translate<-2.7, -1, 0>
        scale 0.4
    }
    text {
        ttf "timrom.ttf", "Sven-Hendrik Haase", 4.5, 0
        texture{ Polished_Chrome
            normal { bumps 0.5 scale 0.005}
            finish{specular 1 reflection 0.55}
        }
        translate<-4, -2, 0>
        scale 0.4
    }
}

#switch (clock)
    #range (800, 920)
        #local Fadein = 1-(1/920)*clock;
        #local Fadeout = 0;
        object { title
            translate<0,0,clock+40*Fadein-5*Fadeout>
        }
        #break
    #range (920, 1040)
        object { title
            translate<0,0,clock>
        }
        #break
    #range (1040, 1280)
        #local Fadein = 0;
        #local Fadeout = (1/240)*mod(clock, 1040);
        object { title
            translate<0,0,clock+40*Fadein-8*Fadeout>
        }
#end

#switch (clock)
    #range (1160, 1280)
        #local Fadein = 1-(1/1160)*mod(clock, 1280);
        #local Fadeout = 0;
        object { authors
            translate<0,0,clock+40*Fadein-5*Fadeout>
        }
        #break
    #range (1280, 1400)
        #local Fadein = 0;
        #local Fadeout = 0;
        object { authors
            translate<0,0,clock>
        }
        #break
    #range (1400, 1640)
        #local Fadein = 0;
        #local Fadeout = (1/1400)*mod(clock+1160, 1400);
        object { authors
            translate<0,0,clock+20*Fadein-8*Fadeout>
        }
        #break
#end
