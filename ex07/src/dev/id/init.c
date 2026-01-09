// SPDX-License-Identifier: GPL-2.0+
#include "dev/id.h"

static const struct file_operations fops = {
	.open = dev_id_open,
	.release = dev_id_release,
	.read = dev_id_read,
	.write = dev_id_write,
};

int dev_id_init(struct dentry *parent)
{
	struct dentry *entry = debugfs_create_file(DEV_NAME, DEV_MODE, parent,
		NULL, &fops);

	if (!entry) {
		pr_alert(PR_PREFIX "Failed to create id device\n");
		return -ENOMEM;
	}

	return 0;
}
