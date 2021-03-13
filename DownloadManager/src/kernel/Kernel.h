#pragma once

#include <vector>
#include <string>
#include <string_view>
#include <map>
#include <functional>

#include "io/io.h"
#include "saver/Saver.h"
#include "socket/Socket.h"
#include "../kernel/downloader/curl/curlDownloader.h"
#include "../kernel/downloader/sfmlNet/sfmlDownloader.h"

class Kernel
{
public:
	Kernel();
	void run();
	~Kernel();
private:
	IO ioManager;
	SocketManager soketManager;
	SaverManager saverManager;
	DownloaderCurl curlManager;
	SfmlDownloader sfmlManager;
	
	const std::vector<std::string_view> textForMenu = {
		"Hello! I am starting...\n",
		"1 - Chat\n",
		"2 - Sfml_download\n",
		"3 - Download file(cURL,name)\n",
		"4 - getResponce(cuRL)\n",
		"5 - Exit\n"
	};

	bool running = false;
	void drawMainMenu();

	std::map<std::string, std::function<void()>> func = {
			{"1",[=]() { soketManager.open(); }},
			{"2",[=]() { auto tmp = ioManager.read(2); sfmlManager.downloadFile(tmp[0],tmp[1]); }},
			{"3",[=]() { auto tmp = ioManager.read(2);curlManager.downloadFile(tmp[0],tmp[1]); }},
			{"4",[=]() { curlManager.getResponce(ioManager.read(1).front()); }},
			{"5",[=]() { running = false; ioManager.print("Bye\n"); } },
			{"cls",[=]() { drawMainMenu(); } },
	};

	//tryParse string
	std::vector<int> stringsToInts(std::vector<std::string>&);
};

