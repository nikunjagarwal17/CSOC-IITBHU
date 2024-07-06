# Project 2
### Hacking a game

In this project I have used the technique of **Memory Corruption** to hack a game and get the desired in games value.

Detailed Video of the Project [Click Here](https://www.youtube.com/watch?v=Tpp-M2htnfs).

I have used the following C++ code to do the same:
```c++
#include <windows.h>
#include <tlhelp32.h>
#include <iostream>

DWORD GetProcessID(const char* windowTitle) {
    HWND hWnd = FindWindowA(0, windowTitle);
    if (hWnd == NULL) {
        std::cerr << "Could not find the window." << std::endl;
        return 0;
    }

    DWORD pid;
    GetWindowThreadProcessId(hWnd, &pid);
    return pid;
}

uintptr_t GetModuleBaseAddress(DWORD pid, const char* moduleName) {
    uintptr_t baseAddress = 0;
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pid);
    if (hSnapshot != INVALID_HANDLE_VALUE) {
        MODULEENTRY32 moduleEntry;
        moduleEntry.dwSize = sizeof(MODULEENTRY32);
        if (Module32First(hSnapshot, &moduleEntry)) {
            do {
                if (!_stricmp(moduleEntry.szModule, moduleName)) {
                    baseAddress = (uintptr_t)moduleEntry.modBaseAddr;
                    break;
                }
            } while (Module32Next(hSnapshot, &moduleEntry));
        }
        CloseHandle(hSnapshot);
    }
    return baseAddress;
}

void printOptions(){
    std::cout<<"Choose the options:\n";
    std::cout<<"1. Change Money Value:\n";
    std::cout<<"2. Change Health Value:\n";
    std::cout<<"3. Change Maximum health value:\n";
    std::cout<<"4. Change Distance Travelled on Foot:\n";
    std::cout<<"5. Change Distance Travelled by Car:\n";
    std::cout<<"6. Change Distance Travelled by bicycle:\n";
    std::cout<<"7. Print Stats:\n";
    std::cout<<"8. Exit:\n";
}
int takeInput(int min, int max){
    int input = 0;
    while (input==0){
        std::cin>>input;
        if (input < min || input > max){
            input=0;
        }
    }
    return input;
}
void printstats(HANDLE pHandle,uintptr_t moneyAddress,uintptr_t healthAddress,uintptr_t maxHealthAddress,uintptr_t footDistAddress,uintptr_t carDistAddress,uintptr_t bicycleDistAddress){
    int money;
    float health;
    float maxHealth;
    float footDist;
    float carDist;
    float bicycleDist;
    SIZE_T bytesRead;

    // Money
    
    if (ReadProcessMemory(pHandle, (LPCVOID)moneyAddress, &money, sizeof(money), &bytesRead)) {
        std::cout << "Money: " << money << std::endl;

    } else {
        std::cerr << "Failed to read memory." << std::endl;
    }

    // Max health

    if (ReadProcessMemory(pHandle, (LPCVOID)maxHealthAddress, &maxHealth, sizeof(maxHealth), &bytesRead)) {
        std::cout << "Max health: " << maxHealth << std::endl;

    } else {
        std::cerr << "Failed to read memory." << std::endl;
    }

    // Health

    if (ReadProcessMemory(pHandle, (LPCVOID)healthAddress, &health, sizeof(health), &bytesRead)) {
        std::cout << "Health: " << health*100/maxHealth <<" %"<< std::endl;

    } else {
        std::cerr << "Failed to read memory." << std::endl;
    }

    // Distance Covered by foot

    if (ReadProcessMemory(pHandle, (LPCVOID)footDistAddress, &footDist, sizeof(footDist), &bytesRead)) {
        std::cout << "Distance Covered by foot: " << footDist/3*10 <<" feets"<< std::endl;

    } else {
        std::cerr << "Failed to read memory." << std::endl;
    }

    // Distance Covered by car

    if (ReadProcessMemory(pHandle, (LPCVOID)carDistAddress, &carDist, sizeof(carDist), &bytesRead)) {
        std::cout << "Distance Covered by car: " << carDist/3*10 <<" feets"<< std::endl;

    } else {
        std::cerr << "Failed to read memory." << std::endl;
    }

    // Distance Covered by bicycle

    if (ReadProcessMemory(pHandle, (LPCVOID)bicycleDistAddress, &bicycleDist, sizeof(bicycleDist), &bytesRead)) {
        std::cout << "Distance Covered by bicycle: " << bicycleDist/3*10 <<" feets"<< std::endl;

    } else {
        std::cerr << "Failed to read memory." << std::endl;
    }

    std::cout<<"\n\n\n";
}

bool WriteMemory1(HANDLE pHandle, uintptr_t address, int value) {
    SIZE_T bytesWritten;
    return WriteProcessMemory(pHandle, (LPVOID)address, &value, sizeof(value), &bytesWritten);
}
bool WriteMemory(HANDLE pHandle, uintptr_t address, float value) {
    SIZE_T bytesWritten;
    return WriteProcessMemory(pHandle, (LPVOID)address, &value, sizeof(value), &bytesWritten);
}

int main() {
    const char* windowTitle = "GTA: San Andreas";
    DWORD pid = GetProcessID(windowTitle);
    if (pid == 0) {
        return 1;
    }
    uintptr_t baseAddress = GetModuleBaseAddress(pid, "gta_sa.exe");
    if (baseAddress == 0) {
        std::cerr << "Could not find the base address." << std::endl;
        return 1;
    }
    // Open the process with all access rights
    HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (pHandle == NULL) {
        std::cerr << "Could not open the process." << std::endl;
        return 1;
    }

    uintptr_t moneyAddress = baseAddress + 0x77CE50;
    uintptr_t healthAddress = 0x07FDBDB0;
    uintptr_t maxHealthAddress = baseAddress + 0x7793E0;
    uintptr_t footDistAddress = baseAddress + 0x77938C;
    uintptr_t carDistAddress = baseAddress + 0x779390;
    uintptr_t bicycleDistAddress = baseAddress + 0x7793EC;

    while (true)
    {
        printOptions();
        int input=takeInput(1,7);
        if(input==7){
            printstats(pHandle, moneyAddress,healthAddress,maxHealthAddress,footDistAddress,carDistAddress,bicycleDistAddress);
        }
        else if (input==1)
        {   
            int value;
            std::cout<<"Enter Value: ";
            std::cin>>value;
            WriteMemory1(pHandle, moneyAddress, value);
        }
        else if (input==2)
        {   
            float value;
            std::cout<<"Enter Value: ";
            float maxHealth;
            SIZE_T bytesRead;
            ReadProcessMemory(pHandle, (LPCVOID)maxHealthAddress, &maxHealth, sizeof(maxHealth), &bytesRead);
            std::cin>>value;
            WriteMemory(pHandle, healthAddress, value);
        }
        else if (input==3)
        {   
            float value;
            std::cout<<"Enter Value: ";
            std::cin>>value;
            WriteMemory(pHandle, maxHealthAddress, value);
        }
        else if (input==4)
        {   
            float value;
            std::cout<<"Enter Value: ";
            std::cin>>value;
            WriteMemory(pHandle, footDistAddress, value*3/10);
        }
        else if (input==5)
        {   
            float value;
            std::cout<<"Enter Value: ";
            std::cin>>value;
            WriteMemory(pHandle, carDistAddress, value*3/10);
        }
        else if (input==6)
        {   
            float value;
            std::cout<<"Enter Value: ";
            std::cin>>value;
            WriteMemory(pHandle, bicycleDistAddress, value*3/10);
        }
        else if (input==8)
        {   
            std::cout<<"Exiting...";
            // Close the handle to the process
            CloseHandle(pHandle);
            exit(0);
        }
    }
    return 0;
}
```

Here is the Sample Output:

![image](https://github.com/nikunjagarwal17/CSOC-IITBHU/assets/144536875/6da290a2-cd32-4450-90b2-4d2ce99227c6)

- Used the Cheat Engine to get the address where the value is stored in the memory.
- Then in the Code firstlty get the base pointer and then added the required offset to get to the desired values.
- Then used functions to read and write the memory and thus hacking into the game :)

References:
CheatCode: [This Playlist](https://www.youtube.com/watch?v=ku6AtIY-Lu0&list=PLmqenIp2RQcg0x2mDAyL2MC23DAGcCR9b).







