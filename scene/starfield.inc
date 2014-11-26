#local num_stars = 1000;
#for (i, 0, num_stars, 1)
    sphere {
        <0, 0>, 1
        pigment {
            color White
        }
        finish { ambient 0.7 }
        no_shadow
        rotate <0, 0, 10*clock>
        scale Beat1()+0.5
        translate VRand_In_Box(<-50, -50, 0>, <50, 50, 1000>, RandomSeed)
    }
#end
