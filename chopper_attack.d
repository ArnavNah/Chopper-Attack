build/chopper_attack.elf: \
    build/asm/header.o \
    build/assets/ipl3.o \
    build/asm/1000.o \
    build/asm/1050.o \
    build/asm/data/639B0.data.o \
    build/asm/data/7C1B0.bss.o \
    build/assets/7C1B0.o
build/asm/header.o:
build/assets/ipl3.o:
build/asm/1000.o:
build/asm/1050.o:
build/asm/data/639B0.data.o:
build/asm/data/7C1B0.bss.o:
build/assets/7C1B0.o:
-include build/asm/header.d build/assets/ipl3.d build/asm/1000.d build/asm/1050.d build/asm/data/639B0.data.d build/asm/data/7C1B0.bss.d build/assets/7C1B0.d
