/*

Cosmolti.cpp

Written by AwesomeMc101

*/
#include <iostream>

#include "Cosmolti.h"

int main()
{
    PStack pStack;
    std::vector<std::string> lines = {"print: 'hello world'"};
    
    std::cout << "Running Cosmolti 0.1\n\n";

    cosmolt_execute(lines, pStack);
}

