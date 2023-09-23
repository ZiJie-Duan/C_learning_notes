#include <windows.h>
#include <stdio.h>

#define ERROR_SERIOUS 1
#define ERROR_SIMPLE 0

void printMemoryBasicInformation(MEMORY_BASIC_INFORMATION mbi) {
    printf("=== MEMORY_BASIC_INFORMATION ===\n");

    printf("BaseAddress:        %p\n", mbi.BaseAddress);
    printf("AllocationBase:     %p\n", mbi.AllocationBase);
    printf("AllocationProtect:  0x%X\n", mbi.AllocationProtect);
    printf("RegionSize:         %zu bytes\n", mbi.RegionSize);

    // 解析 State 字段
    printf("State:              0x%X (", mbi.State);
    if (mbi.State == MEM_COMMIT)  printf("MEM_COMMIT");
    if (mbi.State == MEM_FREE)    printf("MEM_FREE");
    if (mbi.State == MEM_RESERVE) printf("MEM_RESERVE");
    printf(")\n");

    // 解析 Protect 字段
    printf("Protect:            0x%X (", mbi.Protect);
    if (mbi.Protect & PAGE_READONLY)  printf("PAGE_READONLY ");
    if (mbi.Protect & PAGE_READWRITE) printf("PAGE_READWRITE ");
    if (mbi.Protect & PAGE_EXECUTE)   printf("PAGE_EXECUTE ");
    printf(")\n");

    // 解析 Type 字段
    printf("Type:               0x%X (", mbi.Type);
    if (mbi.Type == MEM_IMAGE)   printf("MEM_IMAGE");
    if (mbi.Type == MEM_MAPPED)  printf("MEM_MAPPED");
    if (mbi.Type == MEM_PRIVATE) printf("MEM_PRIVATE");
    printf(")\n");

    printf("================================\n");
}

int error(int mode, char *msg) {
    int err = GetLastError();
    if (mode == ERROR_SIMPLE) {
        printf("Error: %s\n", msg);
        printf("ERROR CODE: %d\n", err);
        return err;
    } else {
        printf("SERIOUS Error: %s\n", msg);
        printf("ERROR CODE: %d\n", GetLastError());
        getchar();
        getchar();
        exit(1);
    }
}

int main() {
    DWORD processId = 24884;  // 替换为目标进程ID
    DWORD desiredAccess = PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION | PROCESS_QUERY_INFORMATION ;
    //DWORD desiredAccess = PROCESS_QUERY_INFORMATION ;
    
    HANDLE hProcess = OpenProcess(desiredAccess, FALSE, processId);
    if (hProcess == NULL) {
        error(ERROR_SERIOUS, "OpenProcess");
    } else {
        printf("OpenProcess success\n");
    }

    MEMORY_BASIC_INFORMATION mbi;
    LPCVOID lpAddress = 0;

    LPCVOID lpAddress_memo = 0;
    BYTE buffer[128];
    SIZE_T bytesRead;

    while (VirtualQueryEx(hProcess, (LPCVOID)lpAddress, &mbi, sizeof(mbi)) != 0) {
        printMemoryBasicInformation(mbi);

        lpAddress_memo = lpAddress;

        if (mbi.State == MEM_COMMIT && mbi.Protect == PAGE_READWRITE) {
            printf("Found a writable memory region\n");

            if (ReadProcessMemory(hProcess, lpAddress_memo, buffer, sizeof(buffer), &bytesRead)){
                printf("ReadProcessMemory success\n");
                
                for (int i = 0; i < bytesRead; i++) {
                    printf("%02X ", buffer[i]);
                }

            } else {
                error(ERROR_SERIOUS, "ReadProcessMemory");
            }

        }

        getchar();
        lpAddress += mbi.RegionSize;
    }

    error(ERROR_SERIOUS, "VirtualQueryEx");
    // if (VirtualQueryEx(hProcess, (LPCVOID)0, &mbi, sizeof(mbi)) == 0){
    //     error(ERROR_SERIOUS, "VirtualQueryEx");
    // }

    //printMemoryBasicInformation(mbi);

    CloseHandle(hProcess);
    getchar();
    getchar();
    return 0;
}
