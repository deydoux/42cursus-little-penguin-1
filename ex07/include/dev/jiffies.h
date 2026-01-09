/* SPDX-License-Identifier: GPL-2.0+ */
#ifndef __DEV__JIFFIES_H__
# define __DEV__JIFFIES_H__

# include "fortytwo.h"

# define DEV_MODE 0444
# define DEV_NAME "jiffies"

# undef PR_PREFIX
# define PR_PREFIX BASE_PR_PREFIX DEV_NAME ": "

int dev_jiffies_open(struct inode *inode, struct file *filp);
ssize_t dev_jiffies_read(struct file *filp, char *buf, size_t len, loff_t *off);
int dev_jiffies_release(struct inode *inode, struct file *filp);

#endif /* __DEV__JIFFIES_H__ */
