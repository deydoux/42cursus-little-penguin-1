NAME = ft_dev
KDIR = /lib/modules/$(shell uname -r)/build

SRC_DIR = src
INC_DIR = include
SRCS = \
	ft_dev.c \
	open.c \
	read.c \
	release.c \
	write.c

ccflags-y += -I$(INC_DIR)
obj-m += $(NAME).o
$(NAME)-objs += $(addprefix $(SRC_DIR)/,$(SRCS:.c=.o))

all $(NAME).ko: modules

modules: $(SRC_DIR) $(INC_DIR)
modules_install: $(NAME).ko
clean modules modules_install:
	$(MAKE) -C $(KDIR) M=$(shell pwd) $@

install: modules_install
	modprobe $(NAME)

uninstall:
	modprobe -r $(NAME) || true

reinstall: uninstall install

.PHONY: all clean install modules modules_install reinstall uninstall
