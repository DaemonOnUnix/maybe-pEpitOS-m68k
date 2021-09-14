KERNEL := pEpitOS

FREESTANDING_INCLUDES := ../toolchain/lib/gcc/m68k-elf/10.2.0/include/

AS := m68k-elf-as
CC := m68k-elf-gcc
LD := m68k-elf-ld

ARCH = x86_64
ARCH_FOLDER = arch

KERNEL_DIR = pEpitOS-kernel

CFLAGS = -Wall -Wextra -O0 -Iinclude/ -I$(FREESTANDING_INCLUDES)

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
QEMU_PARAMS_NODEBUG = -no-reboot -D ./log.txt -d int,guest_errors -serial mon:stdio 
QEMU_PARAMS_DEBUG = -S -gdb tcp::9000

$(shell mkdir -p $(addprefix $(BUILD)/,$(SRCDIRS)))

all: NODEBUG
	@echo $(PATH)

.PHONY: all clean NODEBUG DEBUG clean_deps

NODEBUG: $(KERNEL).elf
	@$(QEMU) $(QEMU_PARAMS_NODEBUG) -kernel $< 

DEBUG: $(KERNEL).elf
	@$(QEMU) $(QEMU_PARAMS_DEBUG) $(QEMU_PARAMS_NODEBUG) $<

$(KERNEL).elf: $(OBJ)
	@$(LD) $(INTERNALLDFLAGS) $(OBJ) -o $@

$(BUILD)/%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS) $(INTERNALCFLAGS) 

$(BUILD)/%.o: %.s
	@$(AS) -o $@ $<

clean:
	@rm -rf $(KERNEL).elf $(OBJ) image.hdd $(KERNEL).iso $(BUILD) log.txt iso_root

clean_deps: clean
	@rm -rf limine
