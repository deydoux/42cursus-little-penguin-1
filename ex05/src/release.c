// SPDX-License-Identifier: GPL-2.0+
#include "ft_dev.h"

int ft_dev_release(struct inode *inode, struct file *file)
{
	pr_debug(PRINT_PREFIX "Released\n");
	return 0;
}
