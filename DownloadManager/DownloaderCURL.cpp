#include "../DownloadManager/src/ver 2.0/DownloaderCURL.h"


DownloaderCURL::DownloaderCURL()
{
}

DownloaderCURL::~DownloaderCURL()
{
}

void DownloaderCURL::getResponce(std::string_view url)
{
	CURL* curl;
	CURLcode responce;
	curl = curl_easy_init();
	curl_easy_setopt(curl,CURLOPT_URL,url.data());
	responce = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	//return {};
	//return std::string_view();
}

bool DownloaderCURL::downloadFile(std::string_view url, std::string_view name)
{
	auto sizeFile = [=](void* ptr, size_t size, size_t nmeb, FILE* stream) {
		return fwrite(ptr, size, nmeb, stream);
	};

	CURL* curl = curl_easy_init();
	FILE* file = fopen(name.data(), "wb");
	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, sizeFile);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
	CURLcode responce = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	fclose(file);

	return true;
}

