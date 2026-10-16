/* file_creator_sys.c */
#include <fcntl.h>    // open(), O_WRONLY, O_CREAT, O_TRUNC
#include <unistd.h>   // write(), close()
#include <string.h>   // strlen()

int main() {
    // YOUR CODE HERE
    // 1. Open/create "output.txt" using open()
    // 2. Write "Hello from Operating Systems class!\n" using write()
    // 3. Close the file using close()
    // 4. Print "File created successfully!\n" to the terminal using write()
    return 0;
}
