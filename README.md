# little-penguin-1
The start of a series of challenges inspired by Eudyptula. You will get acquainted with many points of Kernel development.

## About the project
This project is a collection of assignments that focus on Linux Kernel Module programming. Gradually introducing more complex concepts and techniques in kernel development. Each assignment includes a README with requirements and instructions.

All assignments requirements are detailed in their respective README files. (for example, [ex07/README.md](ex07/README.md)).

### Key Requirements
- Build and boot custom kernels (mainline and `linux-next`).
- Write and load kernel modules, then evolve them across exercises.
- Produce kernel-standard deliverables: boot logs, `.config`, and a submission-style patch.
- Implement kernel interfaces: misc char device in `/dev`, `debugfs` and `/proc` entries.
- Apply Linux kernel coding style and fix broken starter code.

### Skills Learned
- Reading and navigating kernel source/documentation to locate the right subsystem and patterns.
- Using common kernel APIs safely (memory, file ops helpers, basic concurrency).
- Integrating kernel work with userspace mechanisms (udev/hotplug, permissions).
- Writing clean, maintainable kernel code that adheres to community standards.
- Gaining familiarity with kernel subsystems like procfs, debugfs, and character devices.


## References
### Linux Kernel Documentation
- [Coding Style](https://docs.kernel.org/process/coding-style.html)
- [Submitting Patches](https://docs.kernel.org/process/submitting-patches.html)
- [Character device drivers](https://linux-kernel-labs.github.io/refs/heads/master/labs/device_drivers.html)
- [Miscellaneous Devices](https://docs.kernel.org/driver-api/misc_devices.html)
- [DebugFS](https://docs.kernel.org/filesystems/debugfs.html)
- [Linux Device Model](https://linux-kernel-labs.github.io/refs/heads/master/labs/device_model.html)
- [Generic Mutex Subsystem](https://docs.kernel.org/locking/mutex-design.html)
- [Red-black Trees](https://www.kernel.org/doc/Documentation/rbtree.txt)

### Additional Resources
- [The Linux Kernel Module Programming Guide](https://tldp.org/LDP/lkmpg/2.6/html/)
- [Linux Device Drivers, 3rd Edition](https://lwn.net/Kernel/LDD3/)
- [User space memory access from the Linux kernel](https://developer.ibm.com/articles/l-kernel-memory-access/)
- [Procfs in Linux](https://embetronicx.com/tutorials/linux/device-drivers/procfs-in-linux)
