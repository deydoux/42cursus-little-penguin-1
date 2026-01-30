// SPDX-License-Identifier: GPL-3.0+
#include "mymounts.h"

int mymounts_release(struct inode *inode, struct file *filp)
{
	struct mymounts_data *data = filp->private_data;

	kfree(data->buf);
	kfree(data);
	pr_info(PR_PREFIX "Released\n");
	return 0;
}
