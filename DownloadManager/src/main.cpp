#include "IOControler/iocontoler.h"

#define CURL_STATICLIB
#pragma warning(disable:4996)
#include <curl/curl.h>

//size_t downloadfile(void* ptr,size_t size,size_t nmeb,FILE* stream) {
//	return fwrite(ptr, size, nmeb, stream);
//}

int main () {
	//IO io;
	//io.run();

	//CURL* curl;
	//CURLcode responce;
	//curl = curl_easy_init();
	//curl_easy_setopt(curl,CURLOPT_URL,"https://yandex.ru");
	//responce = curl_easy_perform(curl);
	//curl_easy_cleanup(curl);

	/*CURL* curl = curl_easy_init();
	FILE* file = fopen("file.png", "wb");
	curl_easy_setopt(curl, CURLOPT_URL, "https://yt3.ggpht.com/ytc/AAUvwniKD1_1tlhfun6u-jIlqNXbYURruCAS88clJb4d=s88-c-k-c0x00ffffff-no-rj");
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, downloadfile);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

	CURLcode responce = curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	fclose(file);*/


	return 0;
}