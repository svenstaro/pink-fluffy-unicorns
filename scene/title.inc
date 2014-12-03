text {
    ttf "timrom.ttf", // Font
    "L", // Text
    40,
    0
    texture{ Polished_Chrome
        normal { bumps 0.5 scale 0.005}
        finish{specular 1 reflection 0.55}
    }
    rotate<45*Fadeup,0,0>
    translate<-0.7,5*Fadeup,clock+15*Fadein-5*Fadeout>
}

text {
    ttf "timrom.ttf", // Font
    "O", // Text
    40,
    0
    texture{ Polished_Chrome
        normal { bumps 0.5 scale 0.005}
        finish{specular 1 reflection 0.55}
    }
    rotate<45*Fadeup,0,0>
    translate<0,5*Fadeup,clock+15*Fadein-5*Fadeout>
}

text {
    ttf "timrom.ttf", // Font
    "L", // Text
    40,
    0
    texture{ Polished_Chrome
        normal { bumps 0.5 scale 0.005}
        finish{specular 1 reflection 0.55}
    }
    rotate<45*Fadeup,0,0>
    translate<0.7,5*Fadeup,clock+15*Fadein-5*Fadeout>
}
