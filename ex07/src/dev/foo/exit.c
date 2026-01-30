// SPDX-License-Identifier: GPL-3.0+
#include "dev/foo.h"

void dev_foo_exit(void)
{
	mutex_destroy(&dev_foo_lock);
	pr_info(PR_PREFIX "Unregistered\n");
}
