#define CURL_STATICLIB
#pragma warning(disable:4996)

#include <curl/curl.h>
#include <string_view>

#include <memory>
#include <functional>
#include <stdexcept>
#include <algorithm>

#include "../ver 2.0/curlGuard.h"

class DownloaderCURL
{
public:
	DownloaderCURL();
	~DownloaderCURL();
	void getResponce(std::string_view);
	bool downloadFile(std::string_view, std::string_view);
private:
	void testDownload();

	static curlGuard guardCurl;
	//static constexpr std::array<std::string_view, 1> efs 
	//= {"dsf"};
	//size_t sizeFile(void*, size_t, size_t, FILE*);
};
