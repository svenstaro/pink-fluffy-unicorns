.PHONY: default tex2dvi dvi2ps ps2pdf


default: compile clean open

compile:
	rubber -d main.tex

clean:
	rm *.log *.aux

open:
	evince main.pdf

