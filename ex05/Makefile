NAME = ft_dev

KDIR = /lib/modules/$(shell uname -r)/build

obj-m += $(NAME).o

all: modules

clean modules modules_install:
	$(MAKE) -C $(KDIR) M=$(shell pwd) $@

install: modules_install

.PHONY: all clean modules modules_install install
