// SPDX-License-Identifier: GPL-2.0+
#include "dev/jiffies.h"

ssize_t dev_jiffies_read(struct file *filp, char *buf, size_t len, loff_t *off)
{
	pr_info(PR_PREFIX "Read");
	return 0;
}
