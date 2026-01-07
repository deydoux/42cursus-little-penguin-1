NAME = ft_usb_keyboard
RULES = 42-usb-keyboard.rules

KDIR = /lib/modules/$(shell uname -r)/build
RULESDIR = /etc/udev/rules.d

obj-m += $(NAME).o

all $(NAME).ko: modules

modules: $(NAME).c
modules_install: $(NAME).ko
clean modules modules_install:
	$(MAKE) -C $(KDIR) M=$(shell pwd) $@

$(RULESDIR)/$(RULES): $(RULES)
	cp $< $@

install: modules_install $(RULESDIR)/$(RULES)

.PHONY: all clean install modules modules_install
