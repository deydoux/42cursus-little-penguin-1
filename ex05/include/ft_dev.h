#ifndef __FT_DEV_H__
# define __FT_DEV_H__

#include <linux/cdev.h>
#include <linux/module.h>

# ifndef FT_LOGIN
#  define FT_LOGIN "deydoux\n"
# endif

# define DEV_NAME "fortytwo"
# define FT_LOGIN_LEN ((sizeof FT_LOGIN) - 1)
# define PRINT_PREFIX "ft_dev: "

typedef enum ft_dev_state_e
{
	FT_DEV_INIT,
	FT_DEV_ALLOC_CHRDEV_REGION,
	FT_DEV_CDEV_INIT,
	FT_DEV_CDEV_ADD,
	FT_DEV_CLASS_CREATE,
	FT_DEV_DEVICE_CREATE
}	ft_dev_state_t;

void ft_dev_clean(ft_dev_state_t state);
int ft_dev_open(struct inode *inode, struct file *file);
ssize_t ft_dev_read(struct file *filp, char *buf, size_t len, loff_t *off);
int ft_dev_release(struct inode *inode, struct file *file);
ssize_t ft_dev_write(struct file *filp, const char *buf, size_t len,
	loff_t *off);

extern dev_t dev;
extern struct cdev cdev;
extern struct class *class;
extern ft_dev_state_t state;

#endif /* __FT_DEV_H__ */
