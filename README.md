# DSA Lab Programs AIML 2024
---
## Getting Started
The Programs here mentioned are the part of the subject "Data Science and Algorithm".

### Tree Structure
```
.
├── ./doc
│   ├── ./doc/2.tex
│   ├── ./doc/3.tex
│   ├── ./doc/4.tex
│   ├── ./doc/5.tex
│   ├── ./doc/6.tex
│   └── ./doc/7.tex
├── ./LICENSE
├── ./makefile
├── ./Program10.c
├── ./Program11.c
├── ./Program2.c
├── ./Program3.c
├── ./Program4.c
├── ./Program5.H.c
├── ./Program5.P.c
├── ./Program6.c
├── ./Program7.c
├── ./Program8.c
├── ./Program9.c
└── ./README.md
```
---

### Compilation
Compilation of the following problem don't requier advanced tools. <br/>
It will be ran on just on either `cc` , `clang` or `gcc` .

### Makefile
Here we are using makefile to compile the Program(s) in bulk with different names with extension `*.bin` .

#### Building
Compile all files once.
```
make build
```

#### Clean
Remove all compiled binaries `*.bin` , documents `*.pdf` , archives `*.tgz` and cdroms `*.iso` .
```
make clean
```

#### Document
Generates PDF of the C sources as `DSA-Lab.pdf` . <br/>
You need to have `ghostscript` , `latexmk` and `xelatex` utilities installed.
```
make doc
```

#### Archive
Generates compressed Tape archive `archive.tgz` .
```
make ark
```
To extract the archive
```
tar -xvf archive.tgz
```

#### CD-ROM
Make a CD-ROM Storage for copying archived C sources in Virtual Machine(s). <br/>
You need the package `cdr-tools` with the utility `mkisofs` .
```
make cdrom
```
---
## LICENSE
THIS SOFTWARE IS PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION,<br/>
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

