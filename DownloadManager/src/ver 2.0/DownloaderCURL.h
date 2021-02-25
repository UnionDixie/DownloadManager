#define CURL_STATICLIB
#pragma warning(disable:4996)

#include <curl/curl.h>
#include <string_view>

class DownloaderCURL
{
public:
	DownloaderCURL();
	~DownloaderCURL();
	void getResponce(std::string_view);
	bool downloadFile(std::string_view, std::string_view);
private:
	//size_t sizeFile(void*, size_t, size_t, FILE*);
};
