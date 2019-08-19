#include <linux/linkage.h>
#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/uaccess.h>

struct proc_segs
{
    unsigned long studentID;
    unsigned long start_code;
    unsigned long end_code;
    unsigned long start_data;
    unsigned long end_data;
    unsigned long start_heap;
    unsigned long end_heap;
    unsigned long start_stack;
};

asmlinkage long sys_procmem(int pid, struct proc_segs *info)
{
    struct task_struct *task;
    for_each_process(task)
    {
        if (task->pid == pid && task->mm != NULL)
        {
            struct proc_segs buffer;
            buffer.studentID = 1752394;
            buffer.start_code = task->mm->start_code;
            buffer.end_code = task->mm->end_code;
            buffer.start_data = task->mm->start_data;
            buffer.end_data = task->mm->end_data;
            buffer.start_heap = task->mm->start_brk;
            buffer.end_heap = task->mm->brk;
            buffer.start_stack = task->mm->start_stack;
            int result = copy_to_user(info, &buffer, sizeof(buffer));
            return 0;
        }
    }
    return -1;
}