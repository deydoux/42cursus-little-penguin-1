// SPDX-License-Identifier: GPL-2.0+
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("/dev/fortytwo", O_RDONLY);

	char c;
	ssize_t bytes = read(fd, &c, 1);

	while (bytes) {
		printf("bytes: %zd, c: %d '%c'\n", bytes, c, c);
		sleep(1);
		bytes = read(fd, &c, 1);
	}

	close(fd);
}
