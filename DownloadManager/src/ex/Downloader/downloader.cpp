#include "downloader.h"


Downloader::Downloader() { }

void Downloader::download(std::string_view str1)
{
	std::cout << "Downloader Get\n";
	std::string str;
	std::cin >> str;

	sf::Http http(str,8000);
	sf::Http::Request request;
	request.setMethod(sf::Http::Request::Get);//http://www.google.ru/
	request.setUri("/ip");
	//request.setHttpVersion(1, 1); // HTTP 1.1
	//request.setField("From", "me");// gunicorn httpbin:app
	//equest.setField("Content-Type", "application/x-www-form-urlencoded");//http://127.0.0.1:8000
	//request.setBody("para1=value1&param2=value2");
	sf::Http::Response response = http.sendRequest(request);

	std::cout << "status: " << response.getStatus() << std::endl;
	std::cout << "HTTP version: " << response.getMajorHttpVersion() << "." << response.getMinorHttpVersion() << std::endl;
	std::cout << "Content-Type header:" << response.getField("Content-Type") << std::endl;
	std::cout << "body: " << response.getBody() << std::endl;	

    downloadFile("http://homepages.cae.wisc.edu", "/~ece533/images/airplane.png", "airplane.png", 80);
}

void Downloader::downloadFile(std::string_view Host, std::string_view RemoteFile,
                              std::string_view LocalFile, unsigned short Port = 0)
{

    sf::Http Http;
    sf::Http::Request Request;
    ll FileSize = 0;

    Http.setHost(Host.data(), Port);
    Request.setMethod(sf::Http::Request::Get);
    Request.setUri(RemoteFile.data());

    sf::Http::Response Page = Http.sendRequest(Request);//Get the data

    sf::Http::Response::Status status = Page.getStatus();
    if (status == sf::Http::Response::Ok)
    {
        FileSize = Page.getBody().size();//Get the size that was returned

        std::string FileContainer = Page.getBody();
        std::string tmp = LocalFile.data();

        bool ok = saver.save(FileContainer, LocalFile, 0);
        //std::ofstream files();

        //(tmp, std::ios::out | std::ios::binary)
        //File.write(FileContainer.c_str(), FileSize);//Write the file
       // File.close();
    }
    else
    {
        std::cout << "Error " << status << std::endl;
    }

}

Downloader::~Downloader() { }




