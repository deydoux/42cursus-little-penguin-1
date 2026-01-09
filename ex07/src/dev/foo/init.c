// SPDX-License-Identifier: GPL-2.0+
#include "dev/foo.h"

struct mutex dev_foo_lock;

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

	mutex_init(&dev_foo_lock);

	if (!entry) {
		pr_alert(PR_PREFIX "Failed to create device\n");
		return -ENOMEM;
	}

	pr_info(PR_PREFIX "Registered\n");
	return 0;
}
