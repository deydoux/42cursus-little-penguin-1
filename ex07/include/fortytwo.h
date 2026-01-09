/* SPDX-License-Identifier: GPL-2.0+ */
#ifndef __FORTYTWO_H__
# define __FORTYTWO_H__

#include <linux/debugfs.h>
#include <linux/module.h>

# define DIR_NAME "fortytwo"
# define PR_PREFIX DIR_NAME ": "

int ft_dev_init(struct dentry *parent);

#endif /* __FORTYTWO_H__ */
