// SPDX-License-Identifier: GPL-3.0+
#include "mymounts.h"
#include <../fs/mount.h>
#include <linux/nsproxy.h>
#include <linux/mount.h>

static char *mymounts_strjoin(const char *src, const char *dev, char *path)
{
	if (!src)
		return kasprintf(GFP_KERNEL, "%s %s\n", dev, path);

	char *ret = kasprintf(GFP_KERNEL, "%s%s %s\n", src, dev, path);
	kfree(src);

	return ret;
}

static int mymounts_format(char **data)
{
	struct mnt_namespace *ns = current->nsproxy->mnt_ns;
	if (!ns)
		return -EAGAIN;

	struct rb_root mounts = ns->mounts;
	for (struct rb_node *node = rb_first(&mounts); node; node = rb_next(node)) {
		struct mount *mnt = rb_entry(node, struct mount, mnt_node);
		if (mnt->mnt_parent == mnt)
			continue;

		const char *dev = mnt->mnt_devname;
		struct path path = {
			.mnt = &mnt->mnt,
			.dentry = mnt->mnt.mnt_root,
		};

		char *buf = kmalloc(PATH_MAX, GFP_KERNEL);
		if (!buf)
			return -ENOMEM;

		char *mnt_path = d_path(&path, buf, PATH_MAX);
		if (IS_ERR(mnt_path)) {
			kfree(buf);
			return PTR_ERR(mnt_path);
		}

		*data = mymounts_strjoin(*data, dev, mnt_path);
		kfree(buf);

		if (!*data)
			return -ENOMEM;
	}

	return 0;
}

int mymounts_open(struct inode *inode, struct file *filp)
{
	struct mymounts_data *data = kmalloc(sizeof(struct mymounts_data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->buf = NULL;

	int ret = mymounts_format(&data->buf);
	if (ret < 0) {
		kfree(data->buf);
		kfree(data);
		return ret;
	}

	data->len = strlen(data->buf);

	filp->private_data = data;
	pr_info(PR_PREFIX "Opened\n");
	return 0;
}
