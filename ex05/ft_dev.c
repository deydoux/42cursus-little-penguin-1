#include <linux/module.h>

#define DRIVER_MAJOR 42
#define DRIVER_NAME "fortytwo"
#define FT_LOGIN "deydoux"

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("An Hello World kernel module");

static ssize_t driver_read(struct file *File, char *user_buffer, size_t count,
	loff_t *offs)
{
	printk("driver_read %p %zu\n", user_buffer, count);
	// user_buffer[0] = 'A';
	return 1;
}

static ssize_t driver_write(struct file *File, const char *user_buffer,
	size_t count, loff_t *offs)
{
	printk("driver_write %p %zu\n", user_buffer, count);
	return 1;
}

static int driver_open(struct inode *device_file, struct file *instance)
{
	printk("read_write_driver - open was called!\n");
	return 0;
}

static int driver_close(struct inode *device_file, struct file *instance)
{
	printk("read_write_driver - close was called!\n");
	return 0;
}

static int __init ft_dev_start(void)
{
	struct file_operations fops = {
		.open = driver_open,
		.release = driver_close,
		.read = driver_read,
		.write = driver_write
	};

	printk(KERN_INFO "Hello World!\n");
	register_chrdev(DRIVER_MAJOR, DRIVER_NAME, &fops);

	return 0;
}

static void __exit ft_dev_end(void)
{
	printk(KERN_INFO "Cleaning up module.\n");
	unregister_chrdev(DRIVER_MAJOR, DRIVER_NAME);
}

module_init(ft_dev_start);
module_exit(ft_dev_end);
