#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("/dev/fortytwo", O_RDONLY);

	char c;
	ssize_t bytes_read = read(fd, &c, 1);

	while (bytes_read) {
		printf("bytes_read: %zd, c: %d '%c'\n", bytes_read, c, c);
		bytes_read = read(fd, &c, 1);
	}

	close(fd);
}
