#include "ft_dev.h"

int ft_dev_open(struct inode *inode, struct file *file)
{
	printk(KERN_DEBUG PRINT_PREFIX "Opened\n");
	return 0;
}
