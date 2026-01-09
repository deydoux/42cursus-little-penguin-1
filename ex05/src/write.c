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

	if (strncmp(str, FT_LOGIN + *off, bytes) && str[bytes - 1] != '\n') {
		data->invalid_write = true;
		return -EINVAL;
	}

	char buf_copy[FT_LOGIN_LEN];
	char *login_off = FT_LOGIN;

	copy_from_user(buf_copy, buf, bytes);
	login_off += *off;

	for (size_t i = 0; i < bytes; i++) {
		if (buf_copy[i] != login_off[i] &&
		    !(buf_copy[i] == 0 && login_off[i] == '\n')) {
			data->invalid_write = true;
			return -EINVAL;
		}
	}

	*off += bytes;
	return bytes;
}
