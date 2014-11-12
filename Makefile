.PHONY: default clean render movie

MODE ?= quality
POVQUALITY =
POVSETTINGS = +KFI1 +KFF12724 +KF12724.0 +EF100

ifeq ($(MODE),fast)
	POVQUALITY = +W640 +H360 +Q9 +A +R2
else
	POVQUALITY = +W1920 +H1080 +Q9 +A +R2 
endif

default: render movie

movie:
	ffmpeg -i media/strobe.ogg -i output/scene%05d.png -pix_fmt yuv422p -y -r 60 -vcodec hevc -threads 0 output/scene.mkv

render:
	mkdir -p output
	povray  +Ooutput/scene.png $(POVSETTINGS) $(POVQUALITY) scene/main.pov

clean:
	rm -rf output/
