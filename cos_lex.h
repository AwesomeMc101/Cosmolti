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
#include "cos_func.h"
#include "cos_vector.h"

class lexedCode {
public:

};

typedef enum {
	SEND,
	VAR,
	VECTOR,
} CCommand_T; //CosmoltiCommand (RAW) {FINAL ONLY, NO AFTER-COMMAND}

std::vector<std::string> CCommands = { "print", "var", "vector"};

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

	int dictateArgType(std::vector<std::string> args, std::map<std::string, std::vector<std::string>> vecMap)
	{
		//std::cout << "Testing: " << args[0] << std::endl;
		if (args[0][0] == '"' || args[0][0] == '\'') //check if its a string
		{
			//std::cout << "Scanned " << args[0] << " as string." << std::endl;
			//printf("stret");
			return 0;
		}
		if (Math::MathLex::isDouble(args[0]))
		{
			//printf("numret");
			return 1;
		}
		if (CFunction_Area::isCFunction(args[0]))
		{
			//printf("funcret");
			return 3;
		}
		if (C_Vector::isCVector(args[0], vecMap))
		{
			return 4;
		}
		//printf("varret");
		return 2; //assume variable type

	}
	int dictateArgType(std::string arg)
	{
		//std::cout << "Testing: " << arg << std::endl;
		if (arg[0] == '"' || arg[0] == '\'') //check if its a string
		{
			//printf("stret");
			return 0;
		}
		if (Math::MathLex::isDouble(arg))
		{
			//printf("numret");
			return 1;
		}
		if (CFunction_Area::isCFunction(arg))
		{
			//printf("funcret");
			return 3;
		}
		//printf("varret");
		return 2; //assume variable type

	}
}
