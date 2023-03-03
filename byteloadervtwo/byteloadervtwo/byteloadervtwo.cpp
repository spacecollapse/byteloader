#include <windows.h>
#include <iostream>


int main()
{
    const char data1[] = { 0x77, 0x6f, 0x72, 0x6c, 0x64, 0x21, 0x0a }; // world!\n
	const char data2[] = { 0x77, 0x6f, 0x72, 0x6c, 0x64, 0x21, 0x0a }; // world!\n
	const char data3[] = { 0x77, 0x6f, 0x72, 0x6c, 0x64, 0x21, 0x0a }; // world!\n

    const char fileName1[] = "file1.txt"; // изменение пути к файлу 1 на диск C
    const char fileName2[] = "file2.txt"; // изменение пути к файлу 2 на диск C
    const char fileName3[] = "file3.txt"; // изменение пути к файлу 3 на диск C

    // write data to file 1
    HANDLE file1 = CreateFileA(fileName1, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (file1 != INVALID_HANDLE_VALUE)
    {
        DWORD bytesWritten = 0;
        if (WriteFile(file1, data1, sizeof(data1), &bytesWritten, NULL) == FALSE)
        {
            std::cout << "Failed to write to file 1" << std::endl;
            CloseHandle(file1);
            return 1;
        }
        CloseHandle(file1);
    }
    else
    {
        std::cout << "Failed to create file 1" << std::endl;
        return 1;
    }

    // write data to file 2
    HANDLE file2 = CreateFileA(fileName2, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (file2 != INVALID_HANDLE_VALUE)
    {
        DWORD bytesWritten = 0;
        if (WriteFile(file2, data2, sizeof(data2), &bytesWritten, NULL) == FALSE)
        {
            std::cout << "Failed to write to file 2" << std::endl;
            CloseHandle(file2);
            return 1;
        }
        CloseHandle(file2);
    }
    else
    {
        std::cout << "Failed to create file 2" << std::endl;
        return 1;
    }

    // write data to file 3
    HANDLE file3 = CreateFileA(fileName3, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (file3 != INVALID_HANDLE_VALUE)
    {
        DWORD bytesWritten = 0;
        if (WriteFile(file3, data3, sizeof(data3), &bytesWritten, NULL) == FALSE)
        {
            std::cout << "Failed to write to file 3" << std::endl;
            CloseHandle(file3);
            return 1;
        }
        CloseHandle(file3);
    }
    else
    {
        std::cout << "Failed to create file 3" << std::endl;
        return 1;
    }

    // execute files
    ShellExecuteA(NULL, "open", fileName1, NULL, NULL, SW_SHOWDEFAULT);
    ShellExecuteA(NULL, "open", fileName2, NULL, NULL, SW_SHOWDEFAULT);
    ShellExecuteA(NULL, "open", fileName3, NULL, NULL, SW_SHOWDEFAULT);

    return 0;
}
