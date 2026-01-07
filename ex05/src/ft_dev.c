#include "ft_dev.h"

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("An Hello World kernel module");

dev_t dev;
struct cdev cdev;
struct class *class;
ft_dev_state_t state = FT_DEV_INIT;

static int __init ft_dev_init(void)
{
	int ret;

	ret = alloc_chrdev_region(&dev, 0, 1, DEV_NAME);
	if (ret < 0) {
		printk(KERN_ALERT PRINTK_PREFIX \
			"Failed to allocate char device region\n");
		ft_dev_clean(state);
		return ret;
	}
	state = FT_DEV_DEVICE_CREATE;

	static struct file_operations fops = {
		.open = ft_dev_open,
		.release = ft_dev_release,
		.read = ft_dev_read,
		.write = ft_dev_write
	};

	cdev_init(&cdev, &fops);
	state = FT_DEV_CDEV_INIT;

	ret = cdev_add(&cdev, dev, 1);
	if (ret < 0) {
		printk(KERN_ALERT PRINTK_PREFIX "Failed to add cdev\n");
		ft_dev_clean(state);
		return ret;
	}
	state = FT_DEV_CDEV_ADD;

	class = class_create(DEV_NAME);
	if (IS_ERR(class)) {
		printk(KERN_ALERT PRINTK_PREFIX "Failed to create class\n");
		ft_dev_clean(state);
		return PTR_ERR(class);
	}
	state = FT_DEV_CLASS_CREATE;

	struct device *dev_node;
	dev_node = device_create(class, NULL, dev, NULL, DEV_NAME);
	if (IS_ERR(dev_node)) {
		printk(KERN_ALERT PRINTK_PREFIX "Failed to create device\n");
		ft_dev_clean(state);
		return PTR_ERR(dev_node);
	}
	state = FT_DEV_DEVICE_CREATE;

	printk(KERN_INFO PRINTK_PREFIX "Registered\n");
	return 0;
}

static void __exit ft_dev_exit(void)
{
	ft_dev_clean(state);
	printk(KERN_INFO PRINTK_PREFIX "Unregistered\n");
}

module_init(ft_dev_init);
module_exit(ft_dev_exit);
