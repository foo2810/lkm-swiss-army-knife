#include "internal.h"
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

#include <linux/printk.h>
#include <linux/debugfs.h>


MODULE_LICENSE("GPL");


const char base_dir_name[32] = "lkpg";
struct dentry *base_dir_dentry = NULL;

u8 data_sample_file_u8 = 0;
static int sample_code(void)
{
	const char *fname = "sample_file_u8";
	umode_t mode = 0644;
	debugfs_create_u8(fname, mode, base_dir_dentry,
		&data_sample_file_u8);
	return 0;
}

static int __init lkpg_init(void)
{
	int err = 0;
	base_dir_dentry = debugfs_create_dir(base_dir_name, NULL);
	if (IS_ERR(base_dir_dentry)) {
		pr_err("Error: failed to create base directory\n");
		return PTR_ERR(base_dir_dentry);
	}

	err = sample_code();
	if (err)
		return err;

	return 0;
}

static void __exit lkpg_exit(void)
{
	debugfs_remove_recursive(base_dir_dentry);
}


module_init(lkpg_init);
module_exit(lkpg_exit);

