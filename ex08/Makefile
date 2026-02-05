NAME = main
KDIR = /lib/modules/$(shell uname -r)/build
obj-m += $(NAME).o

all $(NAME).ko: modules

modules: $(NAME).c
clean modules: FORCE
	$(MAKE) -C $(KDIR) M=$(shell pwd) $@

insmod rmmod: $(NAME).ko
	$@ $<

install: insmod
uninstall: rmmod
reinstall: uninstall install

FORCE:
.PHONY: all clean FORCE insmod install modules reinstall rmmod uninstall
