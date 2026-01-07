#ifndef __FT_DEV_H__
# define __FT_DEV_H__

# ifndef FT_LOGIN
#  define FT_LOGIN "deydoux\n"
# endif

# define DEV_NAME "fortytwo"
# define FT_LOGIN_LEN ((sizeof FT_LOGIN) - 1)
# define PRINTK_PREFIX "ft_dev: "

typedef enum e_ft_dev_state
{
	FT_DEV_INIT,
	FT_DEV_ALLOC_CHRDEV_REGION,
	FT_DEV_CDEV_INIT,
	FT_DEV_CDEV_ADD,
	FT_DEV_CLASS_CREATE,
	FT_DEV_DEVICE_CREATE
}	t_ft_dev_state;

#endif /* __FT_DEV_H__ */
