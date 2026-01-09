// SPDX-License-Identifier: GPL-2.0+
#include "dev/foo.h"

ssize_t dev_foo_write(struct file *filp, const char *buf, size_t len,
		      loff_t *off)
{
	pr_info(PR_PREFIX "Write\n");
	return 0;
}
