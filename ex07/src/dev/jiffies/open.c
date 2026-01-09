// SPDX-License-Identifier: GPL-2.0+
#include "dev/jiffies.h"

int dev_jiffies_open(struct inode *inode, struct file *filp)
{
	pr_info(PR_PREFIX "Opened\n");
	return 0;
}
