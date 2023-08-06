
/*

cos_func.h

Written by AwesomeMc101

*/
#include <map>
#include <vector>
#include <string>
#include <string.h>

#include <iostream>

typedef enum {
	GETTYPE,
	STRLEN,
	RAND,
	VECSIZE,
} CFunction_T;

std::vector<std::string> CFunctions = { "gettype", "strlen", "rand", "vecsize"};

class CFunction {
public:
	int arg_Count;
	CFunction_T cmd_Type;
};

namespace CFunction_Area {
	bool isCFunction(std::string arg)
	{
		for (std::string func : CFunctions)
		{
			if (func == arg)
			{
				return true;
			}
		}
		return false;
	}
	
	CFunction createCFunction(int identifier)
	{
		CFunction c;
		switch (identifier)
		{
		case 0:
			c.arg_Count = 1;
			c.cmd_Type = GETTYPE;
			break;
		case 1:
			c.arg_Count = 1;
			c.cmd_Type = STRLEN;
			break;
		case 2:
			c.arg_Count = 1;
			c.cmd_Type = RAND;
			break;
		case 3:
			c.arg_Count = 1;
			c.cmd_Type = VECSIZE;
			break;
		}
		return c;
	}

	CFunction getCFunctionFromString(std::string arg)
	{
		for (int i = 0; i < CFunctions.size(); i++)
		{
			if (CFunctions[i] == arg)
			{
				//std::cout << "CFunc Returner: " << CFunctions[i] << std::endl;
				return createCFunction(i);
			}
		}
	}
}



