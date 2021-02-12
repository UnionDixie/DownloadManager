#include "iocontoler.h"

IO::IO()
{
	//Init
	//print(text[TextEnum::Hello] + text[TextEnum::Transfer]
	for (const auto& it : text)
		print(it);
}

void IO::run()
{
	int n = 0;
	while (n!=3)
	{
		std::cin >> n;
		if ( n == 1 || n == 2)
			func[n]();
	}
}

IO::~IO()
{

}


