#include <iostream>

char* renew(char* str, size_t size)
{
    
}

char* getline()
{
    char* str = new char[256];
    int i = -1;
    do {
        ++i;
        std::cin >> str[i];
    } while (str[i] != '\n' && str[i] != EOF)
}