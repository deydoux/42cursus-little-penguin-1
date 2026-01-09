/* SPDX-License-Identifier: GPL-2.0+ */
#ifndef __DEV__FOO_H__
# define __DEV__FOO_H__

# include "fortytwo.h"

# define DEV_MODE 0644
# define DEV_NAME "foo"

# undef PR_PREFIX
# define PR_PREFIX BASE_PR_PREFIX DEV_NAME ": "

int dev_foo_open(struct inode *inode, struct file *filp);
ssize_t dev_foo_read(struct file *filp, char *buf, size_t len, loff_t *off);
int dev_foo_release(struct inode *inode, struct file *filp);
ssize_t dev_foo_write(struct file *filp, const char *buf, size_t len,
		      loff_t *off);

extern struct mutex dev_foo_lock;

#endif /* __DEV__FOO_H__ */
