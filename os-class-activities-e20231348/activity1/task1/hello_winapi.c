#include <windows.h>

int main() {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) {
        return 1;
    }

    const char *msg = "Hello World via direct Windows Win32 API!\r\n";
    DWORD bytesWritten;

    // Direct Windows API core output function call
    WriteFile(hStdOut, msg, 43, &bytesWritten, NULL);

    return 0;
}
