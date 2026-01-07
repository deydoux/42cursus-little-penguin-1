// SPDX-License-Identifier: GPL-2.0+
#include "ft_dev.h"

int ft_dev_open(struct inode *inode, struct file *file)
{
	pr_info(PR_PREFIX "Opened\n");
	return 0;
}
