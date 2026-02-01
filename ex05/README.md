# Assignment 05
## To Do
- Take the kernel module you wrote for Assignment 01, and modify it to become
a misc character device driver. The misc interface is a super simple way to create a character device without getting caught up in the mess of sysfs and device registration. Trust me, it’s way easier this way!
- The misc device should be created with a dynamic minor number—no need to go
crazy trying to reserve a static one for your test module. That would be a hassle for no reason.
- Implement both the read and write operations for the misc device.
- The misc device node should appear in `/dev/fortytwo`.
- When the device is read from, it should return your student login to the caller.
- When written to, the input data should be compared to your student login. If it
matches, return a successful write response. If not, return an "invalid value" error.
- Register the misc device when your module is loaded, and unregister it when it’s unloaded.

## Turn In
- Your updated code.
