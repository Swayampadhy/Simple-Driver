#include <Windows.h>
#include <stdio.h>
#include "..\FirstDriver\ioctl.h"
#include "..\FirstDriver\Common.h"

int main()
{
    // open handle
    printf("[+] Opening handle to driver...");
    HANDLE hDriver = CreateFile(
        L"\\\\.\\FirstDriver",
        GENERIC_WRITE,
        FILE_SHARE_WRITE,
        nullptr,
        OPEN_EXISTING,
        0,
        nullptr);

    if (hDriver == INVALID_HANDLE_VALUE)
    {
        printf("[!] %s (%d)\n", "Failed to open device", GetLastError());
        return 1;
    }
    else
    {
        printf("success!\n");
    }

    // call FIRST_DRIVER_IOCTL_TEST
    TheQuestion data;
    data.FirstNumber = 3;
    data.SecondNumber = 9;

    printf("[+] Calling FIRST_DRIVER_IOCTL_TEST...");

    TheAnswer answer;
    DWORD bytesReturned;

    BOOL success = DeviceIoControl(
        hDriver,
        FIRST_DRIVER_IOCTL_TEST,
        &data,              // pointer to the data
        sizeof(data),       // the size of the data
        &answer,            // pointer to "answer"
        sizeof(answer),     // size of "answer"
        &bytesReturned,
        nullptr);

    if (success)
    {
        printf("success!\n");
        printf("[+] Bytes returned: %d\n", bytesReturned);
        printf("[+] Result: %d\n", answer.Answer);

    }
    else
    {
        printf("failed!\n");
    }

    // close handle
    printf("[+] Closing handle\n");
    CloseHandle(hDriver);
}