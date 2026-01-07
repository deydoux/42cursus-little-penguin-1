// SPDX-License-Identifier: GPL-2.0+
#include "ft_dev.h"

ssize_t ft_dev_write(struct file *filp, const char *buf, size_t len,
		     loff_t *off)
{
	struct ft_dev_data *data = filp->private_data;

	if (data->invalid_write)
		return -EINVAL;

	ssize_t bytes = min(FT_LOGIN_LEN - *off, len);

	pr_info(PR_PREFIX "Write %zu with offset %lld\n", bytes, *off);
	if (bytes <= 0)
		return 0;

	if (strncmp(buf, FT_LOGIN + *off, bytes) && buf[bytes - 1] != '\n') {
		data->invalid_write = true;
		return -EINVAL;
	}

	*off += bytes;
	return bytes;
}
