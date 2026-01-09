// SPDX-License-Identifier: GPL-2.0+
#include "dev/jiffies.h"

static const struct file_operations fops = {
	.open = dev_jiffies_open,
	.release = dev_jiffies_release,
	.read = dev_jiffies_read
};

int dev_jiffies_init(struct dentry *parent)
{
	struct dentry *entry = debugfs_create_file(DEV_NAME, DEV_MODE, parent,
		NULL, &fops);

	if (!entry) {
		pr_alert(PR_PREFIX "Failed to create device\n");
		return -ENOMEM;
	}

	pr_info(PR_PREFIX "Registered\n");
	return 0;
}
