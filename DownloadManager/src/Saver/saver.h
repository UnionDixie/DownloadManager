#include <vector>
#include <string>
#include <string_view>
#include <filesystem>
#include <sstream>
#include <fstream>
#include <SFML/Graphics.hpp>

class Saver
{
public:
	Saver();
	bool save(std::string_view,std::string_view,int);
	std::string read(std::string_view);
	~Saver();
private:
	std::vector<std::string_view> dataString;
	std::vector<sf::Texture> dataTexture;
};

