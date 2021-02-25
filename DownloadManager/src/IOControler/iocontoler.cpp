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
	while (n!=5)
	{
		std::cin >> n;
		if ( n == 1 || n == 2)
			func[n]();
		if (n == 3) {
			std::string url,name;
			std::cin >> url >> name;
			downloaderCURL.downloadFile(url,name);
		}
		else if (n == 4) {
			std::string url;
			std::cin >> url;
			downloaderCURL.getResponce(url);
		}
	}
}

IO::~IO()
{

}


