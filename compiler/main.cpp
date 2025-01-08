#include <iostream>
#include "../syntax/scanner.h"

int main()
{
    scanner sc;
    sc.nextToken();
    std::cout << "hello LoxCompiler" << std::endl;
    return 0;
}