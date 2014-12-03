.PHONY: default clean render movie

MODE ?= fast
POVQUALITY =
POVSETTINGS = +KFI1 +KFF12724 +KF12724.0 +EF1 -GR +GF -GD -GS -GW

ifeq ($(MODE),high)
	POVQUALITY = +W1920 +H1080 +Q9 +A +R2 
else
	POVQUALITY = +W640 +H360 +Q9 +A +R2
endif

default: render movie

movie:
	ffmpeg -i media/strobe.ogg -framerate 60 -i output/scene%05d.png -y -r 60 -vcodec libx264 -acodec copy -threads 0 output/scene.mkv

render: clean
	mkdir -p output
	povray  +Ooutput/scene.png $(POVSETTINGS) $(POVQUALITY) scene/main.pov

clean:
	rm -rf output/*

play: default
	mpv output/scene.mkv

watch:
	while true ; do inotifywait -e close_write,moved_to,create ./scene; make render; done;
