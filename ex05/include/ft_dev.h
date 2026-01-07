/* SPDX-License-Identifier: GPL-2.0+ */
#ifndef __FT_DEV_H__
# define __FT_DEV_H__

#include <linux/module.h>

# ifndef FT_LOGIN
#  define FT_LOGIN "deydoux\n"
# endif

# define DEV_NAME "fortytwo"
# define FT_LOGIN_LEN (sizeof(FT_LOGIN) - 1)
# define PR_PREFIX "ft_dev: "

int ft_dev_open(struct inode *inode, struct file *file);
ssize_t ft_dev_read(struct file *filp, char *buf, size_t len, loff_t *off);
int ft_dev_release(struct inode *inode, struct file *file);
ssize_t ft_dev_write(struct file *filp, const char *buf, size_t len,
		     loff_t *off);

#endif /* __FT_DEV_H__ */
