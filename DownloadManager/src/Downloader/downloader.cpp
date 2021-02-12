#include "downloader.h"

#include <iostream>
#include <ostream>

void DownloadFile(const std::string& Host, const std::string& RemoteFile,
    const std::string& LocalFile, unsigned short Port = 0)
{
    sf::Http Http;
    sf::Http::Request Request;
    unsigned int FileSize = 0;

    Http.setHost(Host, Port);
    Request.setMethod(sf::Http::Request::Get);
    Request.setUri(RemoteFile);

    sf::Http::Response Page = Http.sendRequest(Request);//Get the data

    FileSize = Page.getBody().size();//Get the size that was returned

    std::string FileContainer = Page.getBody();
    /*std::ofstream File(LocalFile.c_str(), std::ios::out | std::ios::binary);
    File.write(FileContainer.c_str(), FileSize);//Write the file
    File.close();*/
}


Downloader::Downloader()
{
}

void Downloader::download(std::string_view str1)
{
	std::cout << "Downloader\n";
	std::string str;
	std::cin >> str;

	sf::Http http(str,8000);
	sf::Http::Request request;
	request.setMethod(sf::Http::Request::Get);//http://www.google.ru/
	//request.setUri("/index.html");
	request.setHttpVersion(1, 1); // HTTP 1.1
	//request.setField("From", "me");// gunicorn httpbin:app
	//equest.setField("Content-Type", "application/x-www-form-urlencoded");//http://127.0.0.1:8000
	//request.setBody("para1=value1&param2=value2");
	sf::Http::Response response = http.sendRequest(request);

	std::cout << "status: " << response.getStatus() << std::endl;
	std::cout << "HTTP version: " << response.getMajorHttpVersion() << "." << response.getMinorHttpVersion() << std::endl;
	std::cout << "Content-Type header:" << response.getField("Content-Type") << std::endl;
	std::cout << "body: " << response.getBody() << std::endl;



	{
        //string DownloadHtml(string Url) {
            //Split the url (Why I have to do this??)
        //    unsigned EndBase = Url.find("/", 7); //Jump over the "http://" and search for another "/"
        //    string BaseURL = Url.substr(0, EndBase);
        //    string Page = Url.substr(EndBase);
        //    // Create a new HTTP client
        //    sf::Http http;

        //    http.setHost(BaseURL);

        //    // Prepare a request
        //    sf::Http::Request request(Page);

        //    // Send the request
        //    sf::Http::Response response = http.sendRequest(request);
        //    // Check the status code and display the result
        //    sf::Http::Response::Status status = response.getStatus();
        //    if (status == sf::Http::Response::Ok)
        //    {
        //        return response.getBody();
        //    }
        //    else
        //    {
        //        std::cout << "Error " << status << std::endl;
        //    }
        //}

        ////Load the image from Url into sf::Texture
        //sf::Texture GetCopertina(string Url) {
        //    sf::Texture Txt;
        //    string FileCopertina = DownloadHtml(Url);
        //    long int Dim = FileCopertina.length();
        //    Txt.loadFromMemory(FileCopertina.c_str(), Dim);
        //    return Txt;
        //}
	    
        //DownloadFile("http://www.google.ru/images/branding/googlelogo/2x/googlelogo_color_160x56dp.png",
                      //"","1.png",80);

	}
}

Downloader::~Downloader()
{
}


