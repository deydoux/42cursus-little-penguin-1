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

	ssize_t bytes_read = min(FT_LOGIN_LEN - *off, len);
	printk(KERN_DEBUG "bytes_read: %zd\n", bytes_read);
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
	major = register_chrdev(0, DEVICE_NAME, &fops);
	if (major < 0) {
		printk(KERN_ALERT "Registering ft_dev failed: %d\n", major);
		return major;
	}

	printk(KERN_INFO "Create ft_dev file with \
'mknod /dev/" DEVICE_NAME " c %d 0'\n", major);
	return 0;
}

static void __exit ft_dev_exit(void)
{
	unregister_chrdev(major, DEVICE_NAME);
	printk(KERN_INFO "ft_dev unregistered!\n");
}

module_init(ft_dev_init);
module_exit(ft_dev_exit);
