#include "ft_dev.h"

int ft_dev_release(struct inode *inode, struct file *file)
{
	printk(KERN_DEBUG PRINTK_PREFIX "Released\n");
	return 0;
}
