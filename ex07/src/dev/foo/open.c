// SPDX-License-Identifier: GPL-2.0+
#include "dev/foo.h"

int dev_foo_open(struct inode *inode, struct file *filp)
{
	struct dev_foo_data *data = kmalloc(sizeof(*data), GFP_KERNEL);

	if (!data)
		return -ENOMEM;

	filp->private_data = data;
	pr_info(PR_PREFIX "Opened\n");
	return 0;
}
