// SPDX-License-Identifier: GPL-2.0+
#include "dev/id.h"

int dev_id_open(struct inode *inode, struct file *filp)
{
	struct dev_id_data *data = kzalloc(sizeof(*data), GFP_KERNEL);

	if (!data)
		return -ENOMEM;

	filp->private_data = data;
	pr_info(PR_PREFIX "Opened\n");
	return 0;
}
