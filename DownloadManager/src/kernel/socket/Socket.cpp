#include "../socket/Socket.h"

SocketManager::SocketManager()
{
}

void SocketManager::open()
{
	DrawMenu();
	auto f = *ioManager.read(1).begin();
	if (func[f] != nullptr) {
		func[f]();
	}
}

void SocketManager::close()
{
	client.disconnect();
	for (auto& it : clients)
		it->disconnect();
	//clients.clear();
}

SocketManager::~SocketManager()
{
	close();
}

void SocketManager::clientStart()
{
	ioManager.print("Input address and port\n");
	std::string adr;
	int port;
	std::cin >> adr >> port;
	auto status = client.connect(adr, port);//def 127.0.0.1 80

	if (status != sf::Socket::Done)
	{
		ioManager.print("Error connect\n");
	}
	else {
		ioManager.print("Connect is OK!\n");
	}

	//char data[20];
	std::string data;
	std::size_t received;

	std::string n = "1";
	while (n != "3")
	{
		n = *ioManager.read(1).begin();
		// TCP socket:
		if (client.receive(&data, 20, received) != sf::Socket::Done)
		{
			ioManager.print("Error receive!\n");
		}
		else {
			ioManager.print("Received " + received);
			ioManager.print("\nData -  " + data + "\n");
		}
	}
}

void SocketManager::serverStart()
{
	ioManager.print("Input Port\n");
	int port = std::stoi(*ioManager.read(1).begin());
	if (listener.listen(port) != sf::Socket::Done)
	{
		ioManager.print("Error listen\n");
	}
	//add new client
	clients.emplace_back(new sf::TcpSocket());

	if (listener.accept(*clients.front()) != sf::Socket::Done)
	{
		ioManager.print("Error accept\n");
	}
	// TCP socket
	std::vector<std::string> inputs = { "0","Testting...\n" };

	while (inputs.front() != "exit") {
		ioManager.print("Coomand and str\n");
		inputs = ioManager.read(2);
		std::string& msg = inputs[1];
		size_t size = msg.size();
		if (clients.front()->send(msg.c_str(), size) != sf::Socket::Done)
		{
			ioManager.print("Error send\n");
		}
		else {
			ioManager.print("Msg send\n");
		}
		
	}

}

void SocketManager::DrawMenu()
{
	system("cls");
	for (const auto& it : textSocket)
		ioManager.print(it);
}





