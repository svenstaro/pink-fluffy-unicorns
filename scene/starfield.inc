#switch (clock)
    #range (0, start_break_down_fade)
        #local num_stars = 1000;
        #for (i, 0, num_stars, 1)
            sphere {
                <0, 0>, 1
                pigment {
                    color White
                }
                finish { ambient 1 }
                no_shadow
                rotate <0, 0, 10*clock>
                scale Beat1()+0.2
                translate VRand_In_Box(<-50, -50, -50>, <50, 50, 2000>, RandomSeed)
            }
        #end
    #break
    #range (start_part2_fade, end_song)
        #local num_stars = 2000;
        #for (i, 0, num_stars, 1)
            sphere {
                <0, 0>, 1
                pigment {
                    color rgb<rand(RandomSeed), rand(RandomSeed), rand(RandomSeed)>
                }
                finish { ambient Beat2()*10 }
                no_shadow
                rotate <0, 0, 10*clock>
                scale Beat2()+5
                translate VRand_In_Box(<100, 100, start_part2_fade+200>, <-100, -100, -5000>, RandomSeed)
            }
        #end
    #break
#end
