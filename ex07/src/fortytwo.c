// SPDX-License-Identifier: GPL-3.0+
#include "fortytwo.h"

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("An Hello World kernel module");

static struct dentry *dir;

static int __init fortytwo_init(void)
{
	int ret;

	dir = debugfs_create_dir(DIR_NAME, NULL);
	if (!dir) {
		pr_alert(PR_PREFIX "Failed to create debugfs dir\n");
		return -ENOMEM;
	}

	ret = dev_foo_init(dir);
	if (ret)
		return ret;

	ret = dev_id_init(dir);
	if (ret)
		return ret;

	ret = dev_jiffies_init(dir);
	if (ret)
		return ret;

	pr_info(PR_PREFIX "Registered\n");
	return 0;
}

static void __exit fortytwo_exit(void)
{
	debugfs_remove_recursive(dir);
	pr_info(PR_PREFIX "Unregistered\n");
}

module_init(fortytwo_init);
module_exit(fortytwo_exit);
