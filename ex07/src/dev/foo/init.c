// SPDX-License-Identifier: GPL-2.0+
#include "dev/foo.h"

static const struct file_operations fops = {
	.open = dev_foo_open,
	.release = dev_foo_release,
	.read = dev_foo_read,
	.write = dev_foo_write,
};

int dev_foo_init(struct dentry *parent)
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
