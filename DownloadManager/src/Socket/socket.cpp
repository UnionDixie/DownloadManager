#include "socket.h"

net::Soket::Soket()
{

	//sf::TcpSocket socket;
//sf::Socket::Status status = socket.connect("127.0.0.1", 80);
//
//if (status != sf::Socket::Done)
//{
//	print("Error'\n");
//	// error...
//}
//else {
//	print("OK\n");
//}
}

void net::Soket::open()
{
	for (const auto& it : text)
		print(it);//info
	int n;
	std::cin >> n;//1 and 2
	func[n]();
}

void net::Soket::close()
{
	client.disconnect();
	for (auto& it : clients)
		it->disconnect();
}

net::Soket::~Soket()
{
	close();
}

void net::Soket::clientStart()
{
	print("Input address and port\n");
	std::string adr;
	int port;
	std::cin >> adr >> port;
	auto status = client.connect(adr, port);//def 127.0.0.1 80

	if (status != sf::Socket::Done)
	{
		print("Error connect\n");
	}
	else {
		print("Connect is OK!\n");
	}

	char data[20];
	std::size_t received;

	while (true)
	{
		// TCP socket:
		if (client.receive(data, 20, received) != sf::Socket::Done)
		{
			print("Error receive!\n");
			// error...
		}
		std::cout << "Received " << received << " bytes" << std::endl;
		std::cout << "Received " << data << " bytes" << std::endl;
	}

}

void net::Soket::serverStart()
{
	print("Input Port\n");
	int n;
	std::cin >> n;
	if (listener.listen(n) != sf::Socket::Done)
	{
		print("Error listen\n");
	}
	//add new client

	clients.emplace_back(new sf::TcpSocket());

	if (listener.accept(*clients.front()) != sf::Socket::Done)
	{
		print("Error accept\n");
	}

	char data[20] = "Testing..\n";

	// TCP socket:
	int k = 0;
	while (k != 3) {
		std::cin >> k;
		if (clients.front()->send(data, 20) != sf::Socket::Done)
		{
			print("Error send\n");
		}
	}


}



