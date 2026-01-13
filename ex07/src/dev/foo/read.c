// SPDX-License-Identifier: GPL-3.0+
#include "dev/foo.h"

ssize_t dev_foo_read(struct file *filp, char *buf, size_t len, loff_t *off)
{
	mutex_lock(&dev_foo_lock);
	ssize_t bytes = min(dev_foo_len - *off, len);

	pr_info(PR_PREFIX "Read %zd with offset %lld\n", bytes, *off);
	if (bytes <= 0) {
		mutex_unlock(&dev_foo_lock);
		return 0;
	}

	if (copy_to_user(buf, dev_foo_data + *off, bytes))
		return -EFAULT;

	mutex_unlock(&dev_foo_lock);

	*off += bytes;
	return bytes;
}
