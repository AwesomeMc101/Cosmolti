/*

cos_file.h

Written by AwesomeMc101

*/

#include <ostream>
#include <istream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>


namespace C_FILE {
	std::vector<std::string> returnLines(std::string filename)
	{
		std::vector<std::string> lines = {};
		std::ifstream openedFile(filename);
		if (!openedFile.is_open())
		{
			printf("file err");
			return lines;
		}
		std::string line;
		while (std::getline(openedFile, line))
		{
			lines.push_back(line);
		}
		return lines;
	}
}