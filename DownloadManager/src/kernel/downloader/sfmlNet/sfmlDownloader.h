#pragma once

#include <SFML/Network.hpp>
//#include <iostream>
//#include <ostream>
#include <SFML/Graphics.hpp>

#include "../Downloader.h"
#include "../../saver/Saver.h"
#include "../../io/io.h"

class SfmlDownloader : public DownloaderManager
{
public:
	SfmlDownloader();
	bool downloadFile(std::string_view, std::string_view) override;
	void getResponce(std::string_view) override;
	~SfmlDownloader();

private:
	SaverManager saver;
	IO ioManager;
	//void downloadFile(std::string_view, std::string_view,
	//	std::string_view, unsigned short);
	//std::vector<std::string> data;
};

