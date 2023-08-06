/*

cos_state.h

Written by AwesomeMc101

*/

#include <vector>
#include <string>
#include <map>

class Cosmo {
public:
	int top;
};

class TStack /*TempStack*/ {
public:
	std::vector<std::string> items;
	int command;
};

class PStack /*PermStack*/ {
	/* we need to hold variables, functions, */
public:
	/*variable sector*/
	std::map<std::string, std::string> vMap;
	std::map<std::string, std::vector<std::string>> vecMap;
};