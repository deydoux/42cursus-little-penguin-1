NAME = ft_dev
KDIR = /lib/modules/$(shell uname -r)/build
obj-m += $(NAME).o

all $(NAME).ko: modules
modules: $(NAME).c
modules_install: $(NAME).ko
reinstall: uninstall install

clean modules modules_install:
	$(MAKE) -C $(KDIR) M=$(shell pwd) $@

install: modules_install
	modprobe $(NAME)

uninstall:
	modprobe -r $(NAME)

.PHONY: all clean install modules modules_install reinstall uninstall
