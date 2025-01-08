#include "source.h"
#include <iostream>
#include <iomanip>

void error(int line, int col, std::string msg)
{
    std::cout << msg << std::endl;
}

bool isLetter(char ch) {
    if (ch > 'a' && ch < 'z' || (ch >'A' && ch < 'Z' || ch > '0' && ch <'9' || ch == '_')) {
        return true;
    }
    return false;
}

int main()
{
    std::string fileName = "/tmp/source.txt";
    Source s(fileName, &error);

    while (!s.is_end) {
        for (int i = 0; i < 10; i++) {            
            char a = s.nextch();
            if (a == EOF) {
                return -1;
            }
            std::cout << "0x" << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(a) << ":" << a << " ";
        }
        std::cout <<"\n------------------------\n";
    }
    return 0;
}