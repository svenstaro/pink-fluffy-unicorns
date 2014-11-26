#local num_stars = 1000;
#for (i, 0, num_stars, 1)
    sphere {
        VRand_In_Box(<-50, -50, 0>, <50, 50, 1000>, RandomSeed), 1
        pigment { color White }
        finish { ambient 0.7 }
        no_shadow
    }
#end
