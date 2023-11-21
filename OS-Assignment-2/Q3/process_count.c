#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched/signal.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Anushka-Vikranth");
MODULE_DESCRIPTION("Kernel");

static int __init processes_init(void) {

    struct task_struct *task;
    int running_processes = 0;

    for_each_process(task) {
        if (task->__state == TASK_RUNNING) {
            running_processes++;
        }
    }

    printk(KERN_INFO "Number of currently running processes: %d\n", running_processes);
    return 0;
}

static void __exit processes_exit(void) {
    printk(KERN_INFO "Module unloaded\n");
}

module_init(processes_init);
module_exit(processes_exit);