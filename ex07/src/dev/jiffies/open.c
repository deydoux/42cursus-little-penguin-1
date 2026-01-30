// SPDX-License-Identifier: GPL-3.0+
#include "dev/jiffies.h"

int dev_jiffies_open(struct inode *inode, struct file *filp)
{
	dev_jiffies_data data = kasprintf(GFP_KERNEL, "%lu\n", jiffies);

	if (!data)
		return -ENOMEM;

	filp->private_data = data;
	pr_info(PR_PREFIX "Opened\n");
	return 0;
}
