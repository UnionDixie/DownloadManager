#include <SFML/Network.hpp>
#include <iostream>
#include <ostream>
#include <SFML/Graphics.hpp>

#include "..//Saver/saver.h"

typedef long long ll;

class Downloader
{
public:
	Downloader();
	void download(std::string_view);//seek info
	~Downloader();
private:
	Saver saver;
	void downloadFile(std::string_view,std::string_view,
					  std::string_view,unsigned short);
	std::vector<std::string> data;
};

//added libcurl or cpp-netlib.