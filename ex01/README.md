# Assignment 01
## To Do
- Create a "Hello World" kernel module with the following behavior:
```
% sudo insmod main.ko
% dmesg | tail -1
[Wed May 13 12:59:18 2015] Hello world!
% sudo rmmod main.ko
% dmesg | tail -1
[Wed May 13 12:59:24 2015] Cleaning up module.
%
```

## Turn In
- Makefile and source code.
