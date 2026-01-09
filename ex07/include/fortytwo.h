/* SPDX-License-Identifier: GPL-2.0+ */
#ifndef __FORTYTWO_H__
# define __FORTYTWO_H__

#include <linux/debugfs.h>
#include <linux/module.h>

# define DIR_NAME "fortytwo"
# define BASE_PR_PREFIX DIR_NAME ": "
# define PR_PREFIX BASE_PR_PREFIX

int dev_foo_init(struct dentry *parent);
int dev_id_init(struct dentry *parent);
int dev_jiffies_init(struct dentry *parent);

#endif /* __FORTYTWO_H__ */
