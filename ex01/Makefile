NAME = main
KDIR = /lib/modules/$(shell uname -r)/build
obj-m += $(NAME).o

all $(NAME).ko: modules
install: insmod
uninstall: rmmod

clean modules: FORCE
	$(MAKE) -C $(KDIR) M=$(shell pwd) $@

insmod rmmod: $(NAME).ko
	$@ $<

FORCE:
.PHONY: all clean FORCE insmod install modules rmmod uninstall
