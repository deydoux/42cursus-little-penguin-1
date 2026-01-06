#include <linux/cdev.h>
#include <linux/module.h>

#ifndef FT_LOGIN
# define FT_LOGIN "deydoux\n"
#endif

#define DEVICE_NAME "fortytwo"
#define FT_LOGIN_LEN ((sizeof FT_LOGIN) - 1)

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("An Hello World kernel module");

static int ft_dev_open(struct inode *inode, struct file *file)
{
	printk(KERN_DEBUG DEVICE_NAME ": Opened\n");
	return 0;
}

static int ft_dev_release(struct inode *inode, struct file *file)
{
	printk(KERN_DEBUG DEVICE_NAME ": Released\n");
	return 0;
}

static ssize_t ft_dev_read(struct file *filp, char *buf, size_t len,
	loff_t *off)
{
	ssize_t bytes_read = min(FT_LOGIN_LEN - *off, len);
	printk(KERN_DEBUG DEVICE_NAME ": Read %zd with offset %lld\n",
		bytes_read, *off);
	if (bytes_read <= 0)
		return 0;

	if (copy_to_user(buf, FT_LOGIN + *off, bytes_read))
		return -EFAULT;

	*off += bytes_read;
	return bytes_read;
}

static ssize_t ft_dev_write(struct file *filp, const char *buf, size_t len,
	loff_t *off)
{
	printk(KERN_DEBUG DEVICE_NAME ": Write\n");
	return 0;
}

typedef enum e_ft_dev_state
{
	FT_DEV_INIT = 0,
	FT_DEV_ALLOC_CHRDEV_REGION,
	FT_DEV_CDEV_INIT,
	FT_DEV_CDEV_ADD,
	FT_DEV_CLASS_CREATE,
	FT_DEV_DEVICE_CREATE
}	t_ft_dev_state;

static dev_t dev;
static struct cdev cdev;
static struct class *class;
static t_ft_dev_state state = FT_DEV_INIT;

static struct file_operations fops = {
	.open = ft_dev_open,
	.release = ft_dev_release,
	.read = ft_dev_read,
	.write = ft_dev_write
};

static void ft_dev_clean(t_ft_dev_state state)
{
	switch (state) {
		case FT_DEV_DEVICE_CREATE:
			device_destroy(class, dev);
		case FT_DEV_CLASS_CREATE:
			class_destroy(class);
		case FT_DEV_CDEV_ADD:
		case FT_DEV_CDEV_INIT:
			cdev_del(&cdev);
		case FT_DEV_ALLOC_CHRDEV_REGION:
			unregister_chrdev_region(dev, 1);
		case FT_DEV_INIT:
			break;
	}
}

static int __init ft_dev_init(void)
{
	int ret;

	ret = alloc_chrdev_region(&dev, 0, 1, DEVICE_NAME);
	if (ret < 0) {
		printk(KERN_ALERT DEVICE_NAME \
			": Failed to allocate char device region\n");
		ft_dev_clean(state);
		return ret;
	}
	state = FT_DEV_DEVICE_CREATE;

	cdev_init(&cdev, &fops);
	state = FT_DEV_CDEV_INIT;

	ret = cdev_add(&cdev, dev, 1);
	if (ret < 0) {
		printk(KERN_ALERT DEVICE_NAME ": Failed to add cdev\n");
		ft_dev_clean(state);
		return ret;
	}
	state = FT_DEV_CDEV_ADD;

	class = class_create(DEVICE_NAME);
	if (IS_ERR(class)) {
		printk(KERN_ALERT DEVICE_NAME ": Failed to create class\n");
		ft_dev_clean(state);
		return PTR_ERR(class);
	}
	state = FT_DEV_CLASS_CREATE;

	if (IS_ERR(device_create(class, NULL, dev, NULL, DEVICE_NAME))) {
		printk(KERN_ALERT DEVICE_NAME ": Failed to create device\n");
		ft_dev_clean(state);
		return ret;
	}
	state = FT_DEV_DEVICE_CREATE;

	printk(KERN_INFO DEVICE_NAME ": Registered\n");
	return 0;
}

static void __exit ft_dev_exit(void)
{
	ft_dev_clean(state);
	printk(KERN_INFO DEVICE_NAME ": Unregistered\n");
}

module_init(ft_dev_init);
module_exit(ft_dev_exit);
