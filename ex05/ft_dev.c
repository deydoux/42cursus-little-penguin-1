#include <linux/module.h>

#define DRIVER_MAJOR 42
#define DRIVER_NAME "fortytwo"
#define FT_LOGIN "deydoux"

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("An Hello World kernel module");

static int ft_dev_open(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "Opened ft_dev\n");
	return 0;
}

static int ft_dev_release(struct inode *inode, struct file *file)
{
	printk(KERN_INFO "Released ft_dev\n");
	return 0;
}

static ssize_t ft_dev_read(struct file *filp, char *buf, size_t len,
	loff_t *off)
{
	printk(KERN_INFO "Read ft_dev\n");
	return 0;
}

static ssize_t ft_dev_write(struct file *filp, const char *buf, size_t len,
	loff_t *off)
{
	printk(KERN_INFO "Write ft_dev\n");
	return 0;
}

static struct file_operations fops = {
	.open = ft_dev_open,
	.release = ft_dev_release,
	.read = ft_dev_read,
	.write = ft_dev_write
};

static int major;

static int __init ft_dev_init(void)
{
	major = register_chrdev(DRIVER_MAJOR, DRIVER_NAME, &fops);
	if (major < 0) {
		printk(KERN_ALERT "Registering ft_dev failed: %d\n", major);
		return major;
	}

	printk(KERN_INFO "Create ft_dev file with \
'mkmod /dev/" DEVICE_NAME " c %d 0'", major);
	return 0;
}

static void __exit ft_dev_exit(void)
{
	int ret = unregister_chrdev(major, DRIVER_NAME);
	if (ret < 0)
		printk(KERN_ALERT "Error unregistering ft_dev: %d\n", ret);
	else
		printk(KERN_INFO "ft_dev unregistered!\n");
}

module_init(ft_dev_init);
module_exit(ft_dev_exit);
