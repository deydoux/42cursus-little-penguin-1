#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("An Hello World kernel module");

static int __init hello_start(void)
{
	printk(KERN_INFO "little-penguin-1's USB keyboard plugged in!\n");
	return 0;
}

static void __exit hello_end(void)
{
	printk(KERN_INFO "Cleaning up ft_usb_keyboard module.\n");
}

module_init(hello_start);
module_exit(hello_end);
