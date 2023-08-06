/*

Cosmolti.cpp

Written by AwesomeMc101

*/
#include <iostream>

#include "Cosmolti.h"
#include "cos_file.h"
int main()
{

    srand(time(0)); //required for random ints

    std::cout << "Type 1 for line-by-line execution, type 2 to import a file." << std::endl;
    int type = 1;
    std::cin >> type;
    system("cls");
    std::cout << "Running Cosmolti 0.3\n\n";

    if (type == 1)
    {
        PStack pStack;
        std::vector<std::string> lines;
        std::cin.ignore();
        while (1) {
            //std::vector<std::string> lines = { "var: x strlen 'future' + 'is' + 'gay'", "print: x" };
            system("cls");
            for (int i = 0; i < lines.size(); i++)
            {
                std::cout << "[" << i << "] " << lines[i] << std::endl;
            }
            std::cout << "\n\nTo execute, leave the line blank." << std::endl;
            
            std::string line = "";
            putchar('>');
            std::getline(std::cin, line);
            if (line == "")
            {
                cosmolt_execute(lines, pStack);
                lines.clear();
                pStack.vecMap.clear();
                pStack.vMap.clear();
                std::cin.get();
            }
            else
            {
                lines.push_back(line);
            }
        }
    }
    else if (type == 2)
    {
        std::cin.sync();
        std::cout << "Enter filename here: " << std::endl;
        std::cin.ignore();
        std::string filename = "";
        std::getline(std::cin, filename);
        std::cout << "File entered: " << filename << std::endl;
        PStack pStack;
        cosmolt_execute(C_FILE::returnLines(filename), pStack);
    }

    
}

