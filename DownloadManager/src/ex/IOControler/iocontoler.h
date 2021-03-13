#include <iostream>
#include <vector>
#include <string>
#include <string_view>
//#include <SFML/Network.hpp>

#include "../Socket/socket.h"
#include "../Downloader/downloader.h"

#include "../Utility/utility.h"

#include "../ver 2.0/DownloaderCURL.h"

class IO
{
public:
	IO();
	void run();
	~IO();
private:

	net::Soket soket;//working?but not good!!!
					 //added normal menu and info

	Downloader downloader;//ok but havent https

	DownloaderCURL downloaderCURL;

	enum TextEnum
	{
		Hello,
		Transfer,
		download,
		exit,
	};
	const std::vector<std::string> text = {
		"Hello! I am starting...\n",
		"1 - File Transfer\n",
		"2 - Insert link for download\n",
		"3 - Download file(cURL,name)\n",
		"4 - getResponce(cuRL)\n",
		"5 - Exit\n"
	};


	std::map<int, std::function<void()>> func = {
			{1,[=]() { soket.open(); }},
			{2,[=]() { downloader.download(""); }}
	};
};
