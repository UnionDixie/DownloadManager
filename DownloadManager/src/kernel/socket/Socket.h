#pragma once

#include <SFML/Network.hpp>
#include <functional>

#include "../io/io.h"

class SocketManager
{
public:
	SocketManager();
	void open();
	void close();
	~SocketManager();
private:
	void clientStart();
	void serverStart();

	IO ioManager;

	sf::TcpSocket client;
	//sf::TcpSocket socket;//client
	sf::TcpListener listener;//server
	//sf::TcpSocket client;//for new client
	std::vector<sf::TcpSocket*> clients;

	void DrawMenu();


	std::vector<std::string> textSocket = {
		"Choose client or server...\n",
		"1 - Client(address,port)\n",
		"2 - Server(address,port)\n",
		"3 - Exit\n"
	};

	std::map<std::string, std::function<void()>> func = {
		{"1",[=]() { clientStart(); }},
		{"2",[=]() { serverStart(); }},
		{"cls",[=]() { DrawMenu(); }}
	};
};

