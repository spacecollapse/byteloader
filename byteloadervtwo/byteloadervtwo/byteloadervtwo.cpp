#include <windows.h>

int main()
{
    const char data[][8] = { {0x77, 0x6f, 0x72, 0x6c, 0x64, 0x21, 0x0a}, //world!\n
                             {0x77, 0x6f, 0x72, 0x6c, 0x64, 0x21, 0x0a}, //world!\n
                             {0x77, 0x6f, 0x72, 0x6c, 0x64, 0x21, 0x0a} };//world!\n
    const char* fileNames[] = { "file1.txt", "file2.txt", "file3.txt" }; //изменение пути к файлу на диск C
    for (int i = 0; i < 3; i++)
    {
        HANDLE file = CreateFileA(fileNames[i], GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
        if (file != INVALID_HANDLE_VALUE)
        {
            DWORD bytesWritten = 0;
            if (WriteFile(file, data[i], sizeof(data[i]), &bytesWritten, NULL) == FALSE)
            {
                CloseHandle(file);
                return 1;
            }
            CloseHandle(file);
        }
        else
        {
            return 1;
        }
        ShellExecuteA(NULL, "open", fileNames[i], NULL, NULL, SW_SHOWDEFAULT);
    }
    return 0;
}
