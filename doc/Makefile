.PHONY: default tex2dvi dvi2ps ps2pdf


default: compile open

compile:
	rubber -d main.tex

clean:
	rubber --clean

open:
	evince main.pdf

