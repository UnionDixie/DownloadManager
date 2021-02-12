#include <SFML/Network.hpp>

class Downloader
{
public:
	Downloader();
	void download(std::string_view);
	~Downloader();
private:
	std::vector<std::string> data;
};

//added libcurl or cpp-netlib.