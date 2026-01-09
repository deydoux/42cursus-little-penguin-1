/* SPDX-License-Identifier: GPL-2.0+ */
#ifndef __DEV__ID_H__
# define __DEV__ID_H__

# include "fortytwo.h"

# ifndef FT_LOGIN
#  define FT_LOGIN "deydoux"
# endif

# define DEV_MODE 0666
# define DEV_NAME "id"
# define FT_LOGIN_LEN sizeof(FT_LOGIN)

struct dev_id_data {
	bool invalid_write;
};

int dev_id_open(struct inode *inode, struct file *filp);
ssize_t dev_id_read(struct file *filp, char *buf, size_t len, loff_t *off);
int dev_id_release(struct inode *inode, struct file *filp);
ssize_t dev_id_write(struct file *filp, const char *buf, size_t len,
		     loff_t *off);

#endif /* __DEV__ID_H__ */
