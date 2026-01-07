// SPDX-License-Identifier: GPL-2.0+
#include "ft_dev.h"

int ft_dev_release(struct inode *inode, struct file *filp)
{
	kfree(filp->private_data);
	pr_info(PR_PREFIX "Released\n");
	return 0;
}
