/*

cos_math.h

Written by AwesomeMc101

*/

#include <string>
#include <vector>

#include <iostream>

namespace Math
{
	namespace MathLex {
		bool isNum(std::string x) /* no longer used; refer to isDouble() */
		{
			for (char c : x)
			{
				if (c != '1' && c != '2' && c != '3' && c != '4' && c != '5' &&
					c != '6' && c != '7' && c != '8' && c != '9' && c != '0')
				{
					return false;
				}
			}
			return true;
		}
		bool isDouble(std::string x)
		{
			for (int i = 0; i < x.length(); i++)
			{
				char c = x[i];

				if (c != '1' && c != '2' && c != '3' && c != '4' && c != '5' &&
					c != '6' && c != '7' && c != '8' && c != '9' && c != '0')
				{
					if (i > 0)
					{
						if (c == '.')
						{
							continue;
						}
					}
					return false;
				}
			}
			return true;
		}
		bool isOp(std::string x)
		{
			char c = x[0]; // operators should only be 1-char
			if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%')
			{
				return true;
			}
			return false;
		}
	}
	std::vector<std::string> consultArith(std::vector<std::string> args)
	{
		/*
		1
		+
		2*/
		std::vector<std::string> nargs = {};
		for (int i = 0; i < args.size(); i++)
		{
			if (MathLex::isOp(args[i]))
			{
				if (i == 0)
				{
					printf("err: mathop called before int (abort op)\n");
					continue;
				}

				if (args[i] == "+")
				{
					if (MathLex::isDouble(args[i - 1]) && MathLex::isDouble(args[i + 1]))
					{
						double a = std::stod(args[i - 1]);
						double b = std::stod(args[i + 1]);

						double solution = a + b;

						nargs.clear();
						nargs.push_back(std::to_string(solution));
						args[i + 1] = std::to_string(solution);
					}
					else
					{
						printf("err: ADD?CONCAT? INT<->STRING FAILED CONVERT (NoFloat)\n");
					}
				}
				if (args[i] == "-")
				{
					if (MathLex::isDouble(args[i - 1]) && MathLex::isDouble(args[i + 1]))
					{
						double a = std::stod(args[i - 1]);
						double b = std::stod(args[i + 1]);

						double solution = a - b;

						nargs.clear();
						nargs.push_back(std::to_string(solution));
						args[i + 1] = std::to_string(solution);;
					}
					else
					{
						printf("err: SUBERROR");
					}
				}
				if (args[i] == "*")
				{
					if (MathLex::isDouble(args[i - 1]) && MathLex::isDouble(args[i + 1]))
					{
						double a = std::stod(args[i - 1]);
						double b = std::stod(args[i + 1]);

						double solution = a * b;

						nargs.clear();
						nargs.push_back(std::to_string(solution));
						args[i + 1] = std::to_string(solution);;
					}
					else
					{
						printf("err: MULTERROR\n");
						
					}
				}
				if (args[i] == "/")
				{
					if (MathLex::isDouble(args[i - 1]) && MathLex::isDouble(args[i + 1]))
					{
						double a = std::stod(args[i - 1]);
						double b = std::stod(args[i + 1]);

						double solution = a / b;

						nargs.clear();
						nargs.push_back(std::to_string(solution));
						args[i + 1] = std::to_string(solution);;
					}
					else
					{
						printf("err: DIVERROR\n");
					}
				}
				if (args[i] == "^")
				{
					if (MathLex::isDouble(args[i - 1]) && MathLex::isDouble(args[i + 1]))
					{
						double a = std::stod(args[i - 1]);
						double b = std::stod(args[i + 1]);

						double solution = pow(a,b);

						nargs.clear();
						nargs.push_back(std::to_string(solution));
						args[i + 1] = std::to_string(solution);;
					}
					else
					{
						printf("err: DIVERROR\n");
					}
				}
			}
		}
		
		if (nargs.size() == 0)
		{
			return args;
		}
		return nargs;
	}
}
