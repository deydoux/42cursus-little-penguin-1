// SPDX-License-Identifier: GPL-2.0+
#include "dev/id.h"

ssize_t dev_id_read(struct file *filp, char *buf, size_t len, loff_t *off)
{
	ssize_t bytes = min(FT_LOGIN_LEN - *off, len);

	pr_info(PR_PREFIX "Read %zd with offset %lld\n", bytes, *off);
	if (bytes <= 0)
		return 0;

	if (copy_to_user(buf, FT_LOGIN "\n" + *off, bytes))
		return -EFAULT;

	*off += bytes;
	return bytes;
}
