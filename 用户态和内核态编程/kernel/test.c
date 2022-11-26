#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("test");
MODULE_DESCRIPTION("A simple example Linux module.");
MODULE_VERSION("0.1");

static int __init test_init(void) {
  printk(KERN_INFO "Hello, World!\n");
  return 0;
}
static void __exit test_exit(void) {
  printk(KERN_INFO "Goodbye, World!\n");
}

module_init(test_init);
module_exit(test_exit);