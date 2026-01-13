// SPDX-License-Identifier: GPL-3.0+
#include "ft_dev.h"

int ft_dev_open(struct inode *inode, struct file *filp)
{
	struct ft_dev_data *data = kzalloc(sizeof(*data), GFP_KERNEL);

	if (!data)
		return -ENOMEM;

	filp->private_data = data;
	pr_info(PR_PREFIX "Opened\n");
	return 0;
}
