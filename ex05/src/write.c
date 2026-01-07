// SPDX-License-Identifier: GPL-2.0+
#include "ft_dev.h"

ssize_t ft_dev_write(struct file *filp, const char *buf, size_t len,
		     loff_t *off)
{
	pr_debug(PRINT_PREFIX "Write\n");
	return 0;
}
