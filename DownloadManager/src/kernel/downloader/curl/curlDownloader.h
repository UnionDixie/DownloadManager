#pragma once

#define CURL_STATICLIB
#pragma warning(disable:4996)

#include <curl/curl.h>
#include <string_view>

#include <memory>
#include <functional>
#include <stdexcept>
#include <algorithm>

#include "../Downloader.h"

class DownloaderCurl : public DownloaderManager
{
public:
	DownloaderCurl();
	bool downloadFile(std::string_view, std::string_view) override;
	void getResponce(std::string_view) override;
	~DownloaderCurl();
private:

};

