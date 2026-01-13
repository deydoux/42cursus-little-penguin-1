// SPDX-License-Identifier: GPL-3.0+
#include "dev/foo.h"

int dev_foo_open(struct inode *inode, struct file *filp)
{
	pr_info(PR_PREFIX "Opened\n");
	return 0;
}
