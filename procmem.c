#include "procmem.h"
#include <linux/kernel.h>
#include <sys/syscall.h>

long procmem(pid_t pid, struct proc_segs *info)
{
    long sysvalue;
    sysvalue = syscall(377, pid, info);
    return sysvalue;
}
