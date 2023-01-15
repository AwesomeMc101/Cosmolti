/*

cos_concat.h

Written by AwesomeMc101

*/

#include <vector>
#include <string>


namespace Concat {
	std::vector<std::string> concat_args(std::vector<std::string> args)
	{
		std::vector<std::string> newArgs = {};
		for (int i = 0; i < args.size(); i++)
		{
			if (args[i] == "+")
			{
				if (i < 1)
				{
					continue;
				}

				std::string tempLoad = args[i - 1] + args[i + 1];
				newArgs.clear();
				newArgs.push_back(tempLoad);
				args[i + 1] = tempLoad; //for further concats, we need an updated string on the arg stack

			}
			if (args[i] == "-")
			{
				printf("Concat - (incomplete)\n");
				if (i < 1)
				{
					continue;
				}

				//newArgs.push_back(args[i - 1] + args[i + 1]);
				//i++;
			}
		}

		if (newArgs.size() == 0)
		{
			return args;
		}
		return newArgs;
	}
}