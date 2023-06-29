#include <Windows.h>

int main(){

    HANDLE hand = GetStdHandle(STD_INPUT_HANDLE);
    LPCSTR file = "file.txt";
    HANDLE file_h = CreateFileA(file, GENERIC_READ | GENERIC_WRITE, 0,
    NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    
    char buf[250];
    DWORD readed;
    
    while(TRUE){    
        ReadConsole(hand, buf, sizeof(buf), &readed, NULL);

        WriteFile(file_h, buf, readed, NULL, NULL);
    };

    return 0;
}