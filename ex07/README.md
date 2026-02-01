# Assignment 07
## To Do
- Modify the module from Assignment 01 to create a `debugfs` subdirectory named `fortytwo`.
- In this directory, create three virtual files: `id`, `jiffies`, and `foo`.
- `id`: Behaves exactly as in Assignment 05. It must be readable and writable by all users.
- `jiffies`: Read-only by any user. When read, it should return the current value of the kernel jiffies timer.
- `foo`: Writable only by root; readable by everyone. Data written should be stored (up to one page). Reading should return the stored data. Implement proper locking to handle concurrent read/write operations.
- When the module is unloaded, all `debugfs` files must be cleaned up and any allocated memory freed.
- Note: The debug directory must be globally readable. Since there’s no option for
that, use good old chown.

## Turn In
- Your code.
- Proof that the module works as expected.
