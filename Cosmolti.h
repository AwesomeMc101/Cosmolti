/*

Cosmolti.h

Written by AwesomeMc101

*/

#include <iostream>
#include <string>
#include <string.h>
#include <vector>

#include "cos_file.h"
#include "cos_lex.h"
#include "cos_state.h"
#include "cos_concat.h"


namespace Parse {
	//parse our code
	std::vector<std::string> parse(std::string line)
	{
		std::vector<std::string> parsedItems = {};
		char* str = const_cast<char*>(line.c_str());
		const char s[2] = " ";
		char* token;

		token = strtok(str, s);

		while (token != NULL) {
			std::string x;
			x.assign(token);// safely convert
			parsedItems.push_back(x);

			token = strtok(NULL, s);
		}

		return parsedItems;
	}

	std::vector<std::string> sepArgs(std::vector<std::string> code, CCommand cmd)
	{
		int starter = cmd.vector_Loc; //use vector loc to find code that comes after our command
		std::vector<std::string> args;

		for (int i = 0; i < code.size(); i++)
		{
			if (i > starter)
			{
				args.push_back(code[i]);
			}
		}
		return args;
	}

	std::vector<std::string> mushString(std::vector<std::string> args)
	{
		bool writer = 0;
		std::string writee = "";
		std::vector<std::string> mushedArgs = {};

		for (int i = 0; i < args.size(); i++)
		{
			if (writer)
			{
				writee += ' ' + args[i];
				if(args[i][args[i].length() - 1] == '"' || args[i][args[i].length() - 1] == '\'')
				{
					writer = 0;

					/* Erase the quotations */
					writee.pop_back();
					writee.erase(writee.begin());

					mushedArgs.push_back(writee);
					writee.clear();
				}
				continue;
			}
			if (args[i][0] == '"' || args[i][0] == '\'')
			{
				if (args[i][args[i].length() - 1] == '"' && args[i].length() > 1 || args[i][args[i].length() - 1] == '\'' && args[i].length() > 1)
				{
					
					/*String is opened and closed without a space
					Ex: 'hello'*/

					/*Erase quotations*/
					args[i].pop_back();
					args[i].erase(args[i].begin());

					mushedArgs.push_back(args[i]);
					continue;
				}
				writee = args[i];
				writer = 1;
				continue;
			}
			mushedArgs.push_back(args[i]);
		}
		if (mushedArgs.size() == 0)
		{
			return args;
		}
		return mushedArgs;
	}
	
}

namespace VM {
	void RUN(CCommand cmd, PStack& permStack)
	{
		switch (cmd.cmd_Type)
		{
		case 0: // SINGLE ARG (PRINT)
			std::cout << "PRINTING: " << cmd.args[0];
			break;
		case 1: //DOUBLE ARG (VAR)
			permStack.vMap.emplace(cmd.args[0], cmd.args[1]);
			break;
		default:
			std::cout << "ERROR: NO SUCH COMMAND" << std::endl;
			break;
		}
	}
}

void cosmolt_execute(std::vector<std::string> lines, PStack& permStack)
{
	for (std::string line : lines)
	{
		printf("\n\nNEWLINE\n\n");
		TStack tempStack;
		std::vector<std::string> code = Parse::parse(line);
		
		CCommand cmd = Lexer::LexCommand(code);

		/* Run the code after the command before we run the command (math, etc) */
		std::vector<std::string> args = Parse::sepArgs(code, cmd);
		tempStack.command = cmd.cmd_Type;

		/* Begin work on arguments */
		/* First, artificially implement real values for variable calls. */

		args = Variable::implementVariables(args, permStack.vMap);

		/* Fix strings etc */

		cmd.argType = Lexer::dictateArgType(args);
		if (cmd.argType == 0) //string
		{
			args = Parse::mushString(args);
			args = Concat::concat_args(args); //test for concats
			//std::cout << "FINAL STRING: " << args[0] << std::endl;
		}
		else if (cmd.argType == 1) //num
		{
			args = Math::consultArith(args);
		}
		else if (cmd.argType == 2)
		{
			//variable
			std::string holster = args[0];
			args.erase(args.begin());
			int fakeType = Lexer::dictateArgType(args);
			if (fakeType == 0)
			{
				args = Parse::mushString(args);
				args = Concat::concat_args(args);
			}
			else if (fakeType == 1)
			{
				args = Math::consultArith(args);
			}
			args.insert(args.begin(), holster);
		}

		cmd.args = args;
		VM::RUN(cmd, permStack);
	}
}