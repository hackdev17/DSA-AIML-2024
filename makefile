CC=cc
TMP=pdf iso tgz

build:
	@echo "Building ..."
	@for i in *.c ; do $(CC) $$i -Wall -o $${i%.c}.bin -lm ; done
	@echo "Build Done"

clean:
	@echo "Removing compiled files ..."
	@rm -rf *.bin

doc:
	@latexmk -pdf -auxdir=tmp/ -shell-escape -cd doc/*.tex
	@gs -dNOPAUSE -sDEVICE=pdfwrite -sOUTPUTFILE=DSA-LAB.pdf -dBATCH doc/{1..12}.pdf

ark:
	@tar -zcvf archive.tgz *.c makefile doc/*.tex

cdrom:	ark
	@mkisofs archive.tgz > DSA-CD.iso

mclean:
	@echo "Removing misc files *.pdf *.iso *.tgz ..."
	@for i in $(TMP) ; do find . -name "*$$i*" -delete ; done
	@rm -rf doc/tmp doc/_minted*
	@echo "Removed misc files ..."

.PHONY:	doc
