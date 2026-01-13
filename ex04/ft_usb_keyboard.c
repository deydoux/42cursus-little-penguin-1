// SPDX-License-Identifier: GPL-3.0+
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("An Hello World kernel module");

static int __init hello_start(void)
{
	pr_info("little-penguin-1's USB keyboard plugged in!\n");
	return 0;
}

static void __exit hello_end(void)
{
	pr_info("Cleaning up ft_usb_keyboard module.\n");
}

module_init(hello_start);
module_exit(hello_end);
