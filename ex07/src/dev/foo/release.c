// SPDX-License-Identifier: GPL-2.0+
#include "dev/foo.h"

int dev_foo_release(struct inode *inode, struct file *filp)
{
	pr_info(PR_PREFIX "Released\n");
	return 0;
}
