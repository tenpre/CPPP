#include <iostream>
#include "imap.h"


int main()
{
	std::cout << "Hello World!" << std::endl;

	cppp::IMap<std::string, int> mymap;

	mymap["test1"] = 1;
	mymap["test2"] = 2;
	mymap["test3"] = 3;
	mymap["test4"] = 4;
	mymap["test5"] = 5;

	for (auto& it : mymap)
		std::cout << it.first.c_str() << " : " << it.second << std::endl;

	std::cout << mymap.atIndex(2).first.c_str() << std::endl;
	std::cout << mymap.atIndex(7).first.c_str() << std::endl;
	std::cout << mymap.atIndex(-2).first.c_str() << std::endl;

	char i = 0;
	std::fflush(stdout);
	std::cin >> i;

	return 0;
}