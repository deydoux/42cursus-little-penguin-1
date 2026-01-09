// SPDX-License-Identifier: GPL-2.0+
#include "ft_dev.h"

static const struct file_operations fops = {
	.open = ft_dev_open,
	.release = ft_dev_release,
	.read = ft_dev_read,
	.write = ft_dev_write,
};

int ft_dev_init(struct dentry *parent)
{
	struct dentry *entry = debugfs_create_file(DEV_NAME, DEV_MODE, parent,
		NULL, &fops);

	if (!entry) {
		pr_alert(PR_PREFIX "Failed to create id device\n");
		return -ENOMEM;
	}

	pr_info(PR_PREFIX "id registered\n");
	return 0;
}
