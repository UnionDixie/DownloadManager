#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <string_view>

class IO
{
public:
	IO();
	void print(std::string_view);
	std::vector<std::string> read(int);//length input
	~IO();


private:

};

