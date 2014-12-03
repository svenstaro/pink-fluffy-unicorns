text {
    ttf "timrom.ttf", // Font
    "L", // Text
    40,
    0
    texture{ Polished_Chrome
        normal { bumps 0.5 scale 0.005}
        finish{specular 1 reflection 0.55}
    }
    translate<-0.7,0,clock*Fadein-0.05*Fadeout>
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
    translate<0,0,clock*Fadein-0.05*Fadeout>
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
    translate<0.7,0,clock*Fadein-0.05*Fadeout>
}
