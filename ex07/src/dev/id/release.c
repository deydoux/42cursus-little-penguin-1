// SPDX-License-Identifier: GPL-2.0+
#include "dev/id.h"

int dev_id_release(struct inode *inode, struct file *filp)
{
	kfree(filp->private_data);
	pr_info(PR_PREFIX "Released\n");
	return 0;
}
