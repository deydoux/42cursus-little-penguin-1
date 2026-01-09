// SPDX-License-Identifier: GPL-2.0+
#include "dev/jiffies.h"

int dev_jiffies_open(struct inode *inode, struct file *filp)
{
	struct dev_jiffies_data *data = kmalloc(sizeof(*data), GFP_KERNEL);

	if (!data)
		return -ENOMEM;

	snprintf(data->jiffies_str, sizeof(data->jiffies_str), "%lu\n",
		 jiffies);
	filp->private_data = data;
	pr_info(PR_PREFIX "Opened\n");
	return 0;
}
