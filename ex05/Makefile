NAME = ft_dev
KDIR = /lib/modules/$(shell uname -r)/build
obj-m += $(NAME).o

all $(NAME).ko: modules
install: modules_install

clean modules modules_install: FORCE
	$(MAKE) -C $(KDIR) M=$(shell pwd) $@

FORCE:
.PHONY: all clean FORCE install modules modules_install
