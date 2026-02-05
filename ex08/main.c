// SPDX-License-Identifier: GPL-3.0+
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <linux/fs.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Louis Solofrizzo <louis@ne02ptzero.me>");
MODULE_DESCRIPTION("Useless module");

static ssize_t myfd_read(struct file *fp, char __user *user, size_t size,
			 loff_t *offs);
static ssize_t myfd_write(struct file *fp, const char __user *user, size_t size,
			  loff_t *offs);

static const struct file_operations myfd_fops = {
	.owner = THIS_MODULE,
	.read = &myfd_read,
	.write = &myfd_write
};

static struct miscdevice myfd_device = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "reverse",
	.mode = 0666,
	.fops = &myfd_fops
};

char str[PAGE_SIZE] = "";

static int __init myfd_init(void)
{
	int retval;

	retval = misc_register(&myfd_device);
	return retval;
}

static void __exit myfd_cleanup(void)
{
	misc_deregister(&myfd_device);
}

ssize_t myfd_read(struct file *fp, char __user *user, size_t size, loff_t *offs)
{
	size_t t, i;
	ssize_t res;
	char *tmp;
	size_t len;

	// Malloc like a boss
	len = min(strlen(str), size);
	tmp = kmalloc(len, GFP_KERNEL);
	if (!tmp)
		return -ENOMEM;

	for (t = len - 1, i = 0; t != (size_t)-1; t--, i++)
		tmp[i] = str[t];

	res = simple_read_from_buffer(user, size, offs, tmp, len);
	if (res > 0)
		*offs += res;
	kfree(tmp);

	return res;
}

ssize_t myfd_write(struct file *fp, const char __user *user, size_t size,
		   loff_t *offs)
{
	ssize_t res;
	size_t len;

	len = min(size, PAGE_SIZE - 1);
	res = 0;
	res = simple_write_to_buffer(str, size, offs, user, len);
	// 0x0 = ’\0’
	str[len] = 0x0;
	return res;
}

module_init(myfd_init);
module_exit(myfd_cleanup);
