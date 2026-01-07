#include <linux/miscdevice.h>
#include "ft_dev.h"

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("An Hello World kernel module");

static const struct file_operations fops = {
	.open = ft_dev_open,
	.release = ft_dev_release,
	.read = ft_dev_read,
	.write = ft_dev_write,
};

static struct miscdevice misc = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = DEV_NAME,
	.fops = &fops
};

static int __init ft_dev_init(void)
{
	int ret = misc_register(&misc);
	if (ret) {
		printk(KERN_ALERT PRINT_PREFIX "Failed to register misc device\n");
		return ret;
	}

	printk(KERN_INFO PRINT_PREFIX "Registered\n");
	return 0;
}

static void __exit ft_dev_exit(void)
{
	misc_deregister(&misc);
	printk(KERN_INFO PRINT_PREFIX "Unregistered\n");
}

module_init(ft_dev_init);
module_exit(ft_dev_exit);
