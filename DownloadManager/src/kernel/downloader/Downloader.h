#pragma once

#include <string_view>

class DownloaderManager
{
public:
	DownloaderManager();
	bool virtual downloadFile(std::string_view,std::string_view) = 0;
	void virtual getResponce(std::string_view) = 0;
	virtual ~DownloaderManager() = 0;
private:

};

