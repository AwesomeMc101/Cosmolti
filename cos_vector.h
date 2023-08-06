/*

cos_vector.h

Written by AwesomeMc101

*/

/*Hopeful syntax:

vector: x 5 7 9 10 2
print: x 0 -> 5
*/


#include <map>
#include <vector>
#include <string>
#include <string.h>

#include <iostream>

namespace C_Vector {
	bool isCVector(std::string arg, std::map<std::string, std::vector<std::string>> vecMap) //is arg a vector name
	{
		if (vecMap.count(arg))
		{
			return true;
		}
		return false;
	}
	std::string returnVectorVal(std::string argone, std::string argtwo, std::map<std::string, std::vector<std::string>> vecMap) //argone is key, argetwo is vec num
	{
		return vecMap[(argone)][std::stoi(argtwo)]; //hoping this works ngl
	}

	std::vector<std::string> implementVectors(std::vector<std::string> args,
		std::map<std::string, std::vector<std::string>> vecMap)
	{
		for (int i = 0; i < args.size(); i++)
		{
			std::string arg = args[i];
			if (!isCVector(arg, vecMap)) { continue; }

			if (i == args.size() - 1)
			{
				printf("sizecall");
				continue; //assume that its a vecsize call or something else (there is no key provided next)
			}

			//arg is a vector
			size_t size = vecMap[arg].size();
			size_t caller_size = std::stoi(args[i + 1]);
			if (caller_size >= size) {
				//example: vector has 5 values and you attempt to call 6th
				std::cout << "err: attempt to call a vector value greater than vector size" << std::endl;
				continue;
			}


			std::string trueValue = returnVectorVal(arg, args[i + 1], vecMap); //value of call
			if (!Math::MathLex::isDouble(trueValue))
			{
				trueValue = "'" + trueValue + "'";
			}
			
			args[i] = trueValue;
			args.erase(args.begin() + i + 1);

		}
		return args;
	}
}