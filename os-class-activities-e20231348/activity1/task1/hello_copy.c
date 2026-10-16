#include <fcntl.h>
#include <unistd.h>

int main() {
    char buffer[1024];
    ssize_t bytes;

    // 1. Open a source file for reading
    int src = open("output.txt", O_RDONLY);
    if (src < 0) {
        write(2, "Error opening source file\n", 26);
        return 1;
    }

    // 2. Open/create a destination file for writing
    int dest = open("copy_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest < 0) {
        close(src);
        write(2, "Error creating destination file\n", 32);
        return 1;
    }

    // 3. Read from source and write to destination in blocks
    while ((bytes = read(src, buffer, sizeof(buffer))) > 0) {
        write(dest, buffer, bytes);
    }

    // 4. Close both file descriptors cleanly
    close(src);
    close(dest);

    write(1, "File copied successfully!\n", 26);
    return 0;
}
