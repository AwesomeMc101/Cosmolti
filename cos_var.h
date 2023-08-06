/*

cos_var.h

Written by AwesomeMc101

*/

#include <vector>
#include <string>
#include <map>


#include "cos_math.h"


namespace Variable
{



	std::vector<std::string> implementVariables(std::vector<std::string> args,
		std::map<std::string, std::string> vars)
	{
		for (int i = 0; i < args.size(); i++)
		{
			auto narg = vars.find(args[i]);
			if (narg == vars.end()) { continue; }

			if (Math::MathLex::isDouble(narg->second))
			{
				args[i] = narg->second;
			}
			else
			{
				args[i] = "'" + narg->second + "'";
			}
			
		}

		return args;
	}
}