/* file_creator_win.c */
#include <windows.h>

int main() {
    // 1. Create/Open file using the native Windows API core function
    HANDLE hFile = CreateFileA(
        "output_win.txt",            // Filename
        GENERIC_WRITE,               // Write access mode
        0,                           // Do not share
        NULL,                        // Default security attributes
        CREATE_ALWAYS,               // Overwrite if exists (mimics O_TRUNC)
        FILE_ATTRIBUTE_NORMAL,       // Normal file flag
        NULL                         // No template file
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        return 1;
    }

    // 2. Write the message block
    const char *text = "Hello from Operating Systems class! (Windows API Version)\r\n";
    DWORD bytesWritten;
    
    WriteFile(hFile, text, 58, &bytesWritten, NULL);

    // 3. Close the file handle cleanly
    CloseHandle(hFile);

    return 0;
}
