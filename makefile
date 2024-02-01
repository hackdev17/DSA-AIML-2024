build:
	@echo "Building ..."
	@for i in *.c ; do cc $$i -o $${i%.c}.bin -lm ; done
	@echo "Build Done"

clean:
	@echo "Removing compiled files ..."
	@rm -rf *.bin

cdrom:
	@mkisofs -r *.c makefile > DSA-CD.iso
