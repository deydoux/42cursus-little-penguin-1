// SPDX-License-Identifier: GPL-2.0+
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int fd = open("/dev/fortytwo", O_WRONLY);
	char *ft_login = "deydoux";

	for (int i = 0; ft_login[i]; i++) {
		ssize_t bytes = write(fd, &ft_login[i], 1);

		printf("bytes: %zu errno: %d\n", bytes, errno);
	}

	close(fd);
}
