#include "io.h"

IO::IO()
{
}

void IO::print(std::string_view str)
{
	std::cout << str;
}

std::vector<std::string> IO::read(int N)
{
	print(std::to_string(N) + " arg\n");
	std::vector<std::string> input(N);
	for (auto& it : input) {
		std::cin >> it;
	}
	return input;
}

IO::~IO()
{
}