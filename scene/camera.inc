camera {
    location <0, 0, -10>
    #switch (clock)
        #range (0, start_break_down_fade)
            translate clock*z
        #break
        #range (start_break_down_fade, start_focus_break_down)
            // Turn around ship
            rotate <20, (clock/4)-end_break_down_fade-40, 0>
            translate <0, 0, 4>
        #break
        #range (start_focus_break_down, end_focus_break_down)
            // Zoom in
            #local diff = end_focus_break_down-start_focus_break_down;
            translate <0, 2, (-20+(clock-start_focus_break_down)*26/diff)>
            rotate 30*x
            rotate 90*y
        #break
        #range (end_focus_break_down, start_part2_fade)
            translate 6*z
            rotate 30*x
            rotate 90*y
        #break
        #range (start_part2_fade, end_song)
            translate <0, 0, start_part2_fade - clock>
            rotate 180
        #break
    #end

    look_at <0, 0, 0>
}
