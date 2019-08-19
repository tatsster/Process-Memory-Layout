# Process Memory Layout
[Class Project] Add a new Linux system call

Since it's a class project so I don't want to spoil any part of it in README. But overall, to make this system call works, just follow steps as every other system calls:
- Install required packages.
- Download concrete kernel source (a old stable kernel for developing new system calls).
- Research and write some system call code.
- Add new system call ID in syscall tables.
- Add new lines of code in **syscalls.h**.
- Add a new line in **Makefile**.
- Compile & Validate system call
