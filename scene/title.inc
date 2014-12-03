text {
    ttf "timrom.ttf", // Font
    "L", // Text
    40,
    0
    texture{ Polished_Chrome
        normal { bumps 0.5 scale 0.005}
        finish{specular 1 reflection 0.55}
    }
    translate<-0.7+clock*10/(28.14*10*20),0.8*sin(1/4*pi-clock*10/(28.14*10*3)),clock>
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
    translate<-1.5+clock*10/(28.14*10*20),0.8*sin(2/4*pi-clock*10/(28.14*10*3)),clock>
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
    translate<-2.3+clock*10/(28.14*10*20),0.8*sin(3/4*pi-clock*10/(28.14*10*3)),clock>
}
