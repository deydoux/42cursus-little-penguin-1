// SPDX-License-Identifier: GPL-3.0+
#include "dev/id.h"

ssize_t dev_id_write(struct file *filp, const char *buf, size_t len,
		     loff_t *off)
{
	struct dev_id_data *data = filp->private_data;

	if (data->invalid_write)
		return -EINVAL;

	ssize_t bytes = min(FT_LOGIN_LEN - *off, len);

	pr_info(PR_PREFIX "Write %zu with offset %lld\n", bytes, *off);
	if (bytes <= 0)
		return 0;

	char buf_copy[FT_LOGIN_LEN];
	char *login_off = FT_LOGIN;

	if (copy_from_user(buf_copy, buf, bytes))
		return -EFAULT;
	login_off += *off;

	for (size_t i = 0; i < bytes; i++) {
		if (buf_copy[i] != login_off[i] &&
		    !(buf_copy[i] == '\n' && login_off[i] == 0)) {
			data->invalid_write = true;
			return -EINVAL;
		}
	}

	*off += bytes;
	return bytes;
}
