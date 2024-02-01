build:
	@echo "Building ..."
	@for i in *.c ; do cc $$i -o $${i%.c}.bin -lm ; done
	@echo "Build Done"

clean:
	@echo "Removing compiled, pdf, iso, archive files ..."
	@rm -rf *.bin doc/tmp doc/_minted* doc/*.pdf *.pdf *.iso *.tgz

doc:	clean
	@latexmk -pdf -auxdir=tmp/ -shell-escape -cd doc/*.tex
	@gs -dNOPAUSE -sDEVICE=pdfwrite -sOUTPUTFILE=DSA-LAB.pdf -dBATCH doc/{2..7}.pdf

ark:	clean
	@tar -zcvf archive.tgz *.c makefile doc/

cdrom:	clean ark
	@mkisofs archive.tgz > DSA-CD.iso
