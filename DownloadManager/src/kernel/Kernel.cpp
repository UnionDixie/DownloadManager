#include "Kernel.h"

Kernel::Kernel()
{
	drawMainMenu();
	running = true;
}

void Kernel::run()
{
	enum Input
	{
		OneStr = 1
	};
	while (running)
	{
		auto getlines = ioManager.read(Input::OneStr);
		auto& first = *getlines.begin();
		if (func[first] != nullptr) {
			func[first]();
		}
	}
}

void Kernel::drawMainMenu() {
	system("cls");
	for (const auto& it : textForMenu) {
		ioManager.print(it);
	}
}

std::vector<int> Kernel::stringsToInts(std::vector<std::string>& str)
{
	std::vector<int> res;
	for (const auto& it : str) {
		res.push_back(std::stoi(it));
	}
	return res;
}

Kernel::~Kernel()
{

}
