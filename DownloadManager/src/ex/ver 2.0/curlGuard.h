#pragma once

#include <curl/curl.h>

class curlGuard
{
public:
	curlGuard() {
		curl_global_init(CURL_GLOBAL_DEFAULT);
	}
	~curlGuard() {
		curl_global_cleanup();
	}
private:

};
