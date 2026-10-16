#include <fcntl.h>
#include <unistd.h>

int main() {
    char ch;
    int fd = open("output.txt", O_RDONLY);
    if (fd < 0) {
        write(2, "Error\n", 6);
        return 1;
    }
    while (read(fd, &ch, 1) > 0) {
        write(1, &ch, 1);
    }
    close(fd);
    return 0;
}

