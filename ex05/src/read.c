#include "ft_dev.h"

ssize_t ft_dev_read(struct file *filp, char *buf, size_t len, loff_t *off)
{
	ssize_t bytes_read = min(FT_LOGIN_LEN - *off, len);
	printk(KERN_DEBUG PRINT_PREFIX "Read %zd with offset %lld\n",
		bytes_read, *off);
	if (bytes_read <= 0)
		return 0;

	if (copy_to_user(buf, FT_LOGIN + *off, bytes_read))
		return -EFAULT;

	*off += bytes_read;
	return bytes_read;
}
