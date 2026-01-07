#include <linux/cdev.h>
#include "ft_dev.h"

void ft_dev_clean(ft_dev_state_t state)
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
