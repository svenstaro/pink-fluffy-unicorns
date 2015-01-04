.PHONY: default clean render movie watch play

MODE ?= fast
POVSETTINGS = +KFI1 +KFF12724 +KF12724.0 -GR +GF -GD -GS -GW
START_FRAME = 1800
END_FRAME = 2500
OUTDIR = output

# Don't change this
PREFIX = scene
FRAMES = $(shell echo "{$(START_FRAME)..$(END_FRAME)}")
FRAME_TARGETS = $(shell printf "$(OUTDIR)/$(PREFIX)%05d.png " $(FRAMES))

ifeq ($(MODE),high)
	POVQUALITY = +W1920 +H1080 +Q9 +A +R2 
else ifeq ($(MODE),fast)
	POVQUALITY = +W320 +H180 +Q9 -A
else ifeq ($(MODE),superfast)
	POVQUALITY = +W320 +H180 +Q5 -A
endif

default: $(FRAME_TARGETS) movie

movie:
	ffmpeg -i media/strobe.ogg -framerate 60 -i $(OUTDIR)/$(PREFIX)%05d.png -y -r 60 -vcodec libx264 -acodec copy -threads 0 $(OUTDIR)/scene.mkv

$(OUTDIR)/$(PREFIX)%.png: scene/*
	mkdir -p $(OUTDIR)
	povray  +O$(OUTDIR)/$(PREFIX).png +SF$* +EF$* $(POVSETTINGS) $(POVQUALITY) scene/main.pov

clean:
	rm -rf $(OUTDIR)/*

play:
	mpv --osd-level 3 --osd-fractions $(OUTDIR)/$(PREFIX).mkv

watch:
	while true ; do inotifywait -e close_write,moved_to,create ./scene; make -j10; done;
