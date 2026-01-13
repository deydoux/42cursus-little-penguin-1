/* SPDX-License-Identifier: GPL-3.0+ */
#ifndef __MYMOUNTS_H__
# define __MYMOUNTS_H__

#include <linux/proc_fs.h>
#include <linux/module.h>

# define PROC_NAME "mymounts"
# define PROC_MODE 0444
# define PR_PREFIX PROC_NAME ": "

int mymounts_open(struct inode *inode, struct file *filp);
ssize_t mymounts_read(struct file *filp, char *buf, size_t len, loff_t *off);
int mymounts_release(struct inode *inode, struct file *filp);

#endif /* __MYMOUNTS_H__ */
