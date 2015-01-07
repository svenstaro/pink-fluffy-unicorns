camera {
    location <0, 0, -10>
    #switch (clock)
        #range (0, start_break_down_fade)
            translate clock*z
        #break
        #range (start_break_down_fade, end_break_down_fade)
            translate 0
        #break
        #range (end_break_down_fade, start_focus_break_down)
            // Turn around ship
            rotate <0, clock-end_break_down_fade, 0>
        #break
        #range (start_focus_break_down, end_focus_break_down)
            #local diff = end_focus_break_down-start_focus_break_down;
            translate (-20+(clock-start_focus_break_down)*25/diff)*z
            rotate 10*x
            rotate -91*y
        #break
        #range (end_focus_break_down, start_part2_fade)
            translate 5*z
            rotate -90*y
        #break
        #range (start_part2_fade, end_song)
            translate <0, 0, start_part2_fade - clock>
            rotate 180
        #break
    #end

    look_at <0, 0, 0>
}
