#include "sfmlDownloader.h"

SfmlDownloader::SfmlDownloader() { }

bool SfmlDownloader::downloadFile(std::string_view url, std::string_view name)
{
    ioManager.print("host and port pls\n");
    auto settings = ioManager.read(2);
    std::string_view Host = settings.front();
    unsigned short Port = std::stoi(settings[1]);
    //downloadFile("http://homepages.cae.wisc.edu",
    //             "/~ece533/images/airplane.png", "airplane.png", 80);

    sf::Http Http;
    sf::Http::Request Request;
    std::string_view LocalFile;
    
    Http.setHost(Host.data(), Port);
    Request.setMethod(sf::Http::Request::Get);
    Request.setUri(url.data());

   auto Page = Http.sendRequest(Request);//Get the data
   auto status = Page.getStatus();

    if (status == sf::Http::Response::Ok)
    {
        ll FileSize = Page.getBody().size();//Get the size that was returned
        if (saver.save(Page.getBody(), LocalFile, 0)) {
            ioManager.print("Save ok\n");
        }
    }
    else
    {
        ioManager.print("Error " + std::to_string(status) + "\n");
    }

    return true;
}

void SfmlDownloader::getResponce(std::string_view)
{
    ioManager.print("No have getResponce by sfmlDownloader\n");
    ioManager.print("Downloader Get\n");
    std::string str = ioManager.read(1).front();
    
    sf::Http http(str, 8000);
    sf::Http::Request request;
    request.setMethod(sf::Http::Request::Get);//http://www.google.ru/
    request.setUri("/ip");//http://127.0.0.1:8000
    sf::Http::Response response = http.sendRequest(request);

    ioManager.print("status: " + std::to_string(response.getStatus()) +
                    "\nHTTP version:: " + std::to_string(response.getMajorHttpVersion()) +
                    "." + std::to_string(response.getMinorHttpVersion()) + "\n" +
                    "Content-Type header:" + response.getField("Content-Type") + "\n" +
                    "body: " + response.getBody() + "\n");
}

SfmlDownloader::~SfmlDownloader()
{
}

