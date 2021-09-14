KERNEL := pEpitOS

FREESTANDING_INCLUDES := ../toolchain/lib/gcc/m68k-elf/10.2.0/include/

AS := m68k-elf-as
CC := m68k-elf-gcc
LD := m68k-elf-ld

ARCH = x86_64
ARCH_FOLDER = arch

KERNEL_DIR = pEpitOS-kernel

CFLAGS = -Wall -Wextra -O0 -Iinclude/ -I$(FREESTANDING_INCLUDES)

ASMPARAM = 

BUILD = build

LINK_SCRIPT = link.ld

INTERNALLDFLAGS :=     \
	-nostdlib      \
	-T$(LINK_SCRIPT)    \
	-z max-page-size=0x1000\
	#-Wl,-static,-pie,--no-dynamic-linker,-ztext -fno-pic -fpie 

INTERNALCFLAGS  :=       \
	-std=gnu17           \
	-ffreestanding       \
	-fno-stack-protector \
	-fno-pic -fno-pie	 \

SRCDIRS := $(shell find . -type d)

CFILES := $(shell find . -type f -name '*.c')
SFILES := $(shell find . -type f -name '*.s')

OBJ    := $(SFILES:%.s=$(BUILD)/%.o)
OBJ    += $(CFILES:%.c=$(BUILD)/%.o)

QEMU = qemu-system-m68k
QEMU_PARAMS_NODEBUG = -no-reboot -vga std -D ./log.txt -d int,guest_errors -m 512M -boot d -M q35  -serial mon:stdio -m 1G -smp $(CORE_NUM) -cdrom
QEMU_PARAMS_DEBUG = -S -gdb tcp::9000

$(shell mkdir -p $(addprefix $(BUILD)/,$(SRCDIRS)))

all: NODEBUG
	@echo $(PATH)

.PHONY: all clean NODEBUG DEBUG clean_deps

NODEBUG: $(KERNEL).iso
	@$(QEMU) $(QEMU_PARAMS_NODEBUG) $<

DEBUG: $(KERNEL).iso
	@$(QEMU) $(QEMU_PARAMS_DEBUG) $(QEMU_PARAMS_NODEBUG) $<

$(KERNEL).iso: $(KERNEL).elf
	@mkdir -p iso_root
	@cp -v $(ISO_FILES) iso_root/
	@xorriso -as mkisofs -b limine-cd.bin \
			-no-emul-boot -boot-load-size 4 -boot-info-table \
			-eltorito-alt-boot -e limine-eltorito-efi.bin \
			-no-emul-boot iso_root -o $(KERNEL).iso
	@rm -rf iso_root

$(KERNEL).elf: $(OBJ)
	@$(LD) $(INTERNALLDFLAGS) $(OBJ) -o $@

$(BUILD)/%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS) $(INTERNALCFLAGS) 

$(BUILD)/%.o: %.s
	@$(AS) $(ASMPARAM) -o $@ $<

clean:
	@rm -rf $(KERNEL).elf $(OBJ) image.hdd $(KERNEL).iso $(BUILD) log.txt iso_root

clean_deps: clean
	@rm -rf limine
