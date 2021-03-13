#include <SFML/Network.hpp>

#include "../Utility/utility.h"

#include <functional>

namespace net {
	class Soket
	{
	public:
		Soket();
		void open();
		void close();
		~Soket();
	private:
		
		void clientStart();
		void serverStart();

		sf::TcpSocket client;
		//sf::TcpSocket socket;//client
		sf::TcpListener listener;//server
		//sf::TcpSocket client;//for new client
		std::vector<sf::TcpSocket*> clients;

		enum TextEnum
		{
			Menu,
			Client,
			Server,
			exit,
		};
		std::vector<std::string> text = {
			"Choose client or server...\n",
			"1 - Client(address,port)\n",
			"2 - Server(address,port)\n",
			"3 - Exit\n"
		};

		std::map<int, std::function<void()>> func = {
			{1,[=]() { clientStart(); }},
			{2,[=]() { serverStart(); }}
		};
	};
}


