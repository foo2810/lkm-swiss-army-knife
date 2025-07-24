#define pr_fmt(fmt) "lkpg-kprobe: " fmt

#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

static int __init lkpg_base_init(void)
{
	pr_info("loading module\n");

	return 0;
}

static void __exit lkpg_base_exit(void)
{
	pr_info("unloading module\n");
}

module_init(lkpg_base_init);
module_exit(lkpg_base_exit);

MODULE_LICENSE("GPL");
