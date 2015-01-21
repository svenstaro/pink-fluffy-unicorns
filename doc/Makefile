.PHONY: default tex2dvi dvi2ps ps2pdf


default: tex2dvi dvi2ps ps2pdf clean open

tex2dvi:
	latex *.tex

dvi2ps:
	dvips *.dvi

ps2pdf:
	ps2pdf *.ps

clean:
	rm -rf *.dvi *.ps *.log *.aux *.out

open:
	evince *.pdf

