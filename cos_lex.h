/*

cos_lex.h

Written by AwesomeMc101

*/

#include <map>
#include <vector>
#include <string>
#include <string.h>

#include <iostream>

#include "cos_var.h"

class lexedCode {
public:

};

typedef enum {
	SEND,
	VAR,
} CCommand_T; //CosmoltiCommand (RAW) {FINAL ONLY, NO AFTER-COMMAND}

std::vector<std::string> CCommands = { "print", "var"};

class CCommand {
public:
	CCommand_T cmd_Type;
	size_t vector_Loc;
	int argType; //0String; 1Int
	std::vector<std::string> args;
};

namespace Lexer {
	CCommand LexCommand(std::vector<std::string> code)
	{
		for (int i = 0; i < code.size(); i++)
		{
			for (int c = 0; c < CCommands.size(); c++)
			{
				if (code[i].find(CCommands[c]) == 0)
				{
					if (code[i][code[i].length()-1] != ':')
					{
						//std::cout << "Command " << code[i] << "locked, no :" << std::endl;
						continue;
					}
					//found successfully
					CCommand ccm;
					ccm.cmd_Type = (CCommand_T)c;
					ccm.vector_Loc = i;
					return ccm; //return CCommand value
				}
			}
		}
	}

	int dictateArgType(std::vector<std::string> args)
	{
		std::cout << "Testing: " << args[0] << std::endl;
		if (args[0][0] == '"' || args[0][0] == '\'') //check if its a string
		{
			printf("stret");
			return 0;
		}
		if (Math::MathLex::isNum(args[0]))
		{
			printf("numret");
			return 1;
		}
		return 2; //assume variable type

	}
}