// SPDX-License-Identifier: GPL-2.0+
#include "dev/foo.h"

ssize_t dev_foo_write(struct file *filp, const char *buf, size_t len,
		      loff_t *off)
{
	mutex_lock(&dev_foo_lock);
	ssize_t bytes = min(sizeof(dev_foo_data) - *off, len);

	pr_info(PR_PREFIX "Write %zu with offset %lld\n", len, *off);
	if (bytes <= 0) {
		mutex_unlock(&dev_foo_lock);
		return 0;
	}

	if (copy_from_user(dev_foo_data + *off, buf, bytes))
		return -EFAULT;

	dev_foo_len = bytes + *off;
	mutex_unlock(&dev_foo_lock);

	*off += bytes;
	return bytes;
}
