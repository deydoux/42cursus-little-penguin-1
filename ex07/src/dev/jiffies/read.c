// SPDX-License-Identifier: GPL-2.0+
#include "dev/jiffies.h"

ssize_t dev_jiffies_read(struct file *filp, char *buf, size_t len, loff_t *off)
{
	struct dev_jiffies_data *data = filp->private_data;
	ssize_t bytes = min(sizeof(data->jiffies_str) - *off, len);

	pr_info(PR_PREFIX "Read %zd with offset %lld\n", bytes, *off);
	if (bytes <= 0)
		return 0;

	if (copy_to_user(buf, data->jiffies_str + *off, bytes))
		return -EFAULT;

	*off += bytes;
	return bytes;
}
