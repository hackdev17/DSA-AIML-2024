build:
	@echo "Building ..."
	@for i in *.c ; do cc $$i -o $${i%.c}.bin -lm ; done
	@echo "Build Done"

run:
	@read no && echo $$no

clean:
	@echo "Removing compiled files ..."
	@rm -rf *.bin

doc:
	@latexmk -pdf -xelatex -shell-escape -auxdir=tmp doc.tex
	@rm -rf tmp/ _minted*/

cdrom:
	@mkisofs -r *.c makefile > DSA-CD.iso
