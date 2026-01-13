// SPDX-License-Identifier: GPL-3.0+
#include "mymounts.h"

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("An procfs kernel module");

static int __init mymounts_init(void)
{
	static const struct proc_ops pops = {
		.proc_open = mymounts_open,
		.proc_release = mymounts_release,
		.proc_read = mymounts_read,
	};
	struct proc_dir_entry *entry;

	entry = proc_create(PROC_NAME, PROC_MODE, NULL, &pops);
	if (!entry) {
		pr_alert(PR_PREFIX "Failed to create proc entry\n");
		return -ENOMEM;
	}

	pr_info(PR_PREFIX "Registered\n");
	return 0;
}

static void __exit mymounts_exit(void)
{
	pr_info(PR_PREFIX "Unregistered\n");
}

module_init(mymounts_init);
module_exit(mymounts_exit);
