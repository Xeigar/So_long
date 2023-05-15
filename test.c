#include <fcntl.h>

int main()
{
	char buf[100];
	int fd = open("./maps/invalid_map.ber", O_RDONLY);
	printf("%d", read(fd, buf, 5));
	return (0);
}