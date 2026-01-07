#include "ft_dev.h"

ssize_t ft_dev_write(struct file *filp, const char *buf, size_t len,
	loff_t *off)
{
	printk(KERN_DEBUG PRINT_PREFIX "Write\n");
	return 0;
}
