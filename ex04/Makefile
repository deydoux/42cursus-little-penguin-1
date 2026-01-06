NAME = ft_usb_keyboard
RULES = 42-usb-keyboard.rules

KDIR = /lib/modules/$(shell uname -r)/build
RULESDIR = /etc/udev/rules.d

obj-m += $(NAME).o

all $(NAME).ko: modules
install: modules_install $(RULESDIR)/$(RULES)
modules_install: $(NAME).ko

clean modules modules_install: FORCE
	$(MAKE) -C $(KDIR) M=$(shell pwd) $@

$(RULESDIR)/$(RULES): $(RULES)
	cp $< $@

FORCE:
.PHONY: all clean FORCE install modules modules_install
