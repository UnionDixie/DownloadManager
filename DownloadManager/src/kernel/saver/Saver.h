#pragma once

#include <vector>
#include <string>
#include <string_view>
#include <filesystem>
//#include <sstream>
#include <fstream>
#include <SFML/Graphics.hpp>

typedef long long ll;

class SaverManager
{
public:
	SaverManager();
	bool save(std::string_view, std::string_view, int);
	std::string read(std::string_view);
	ll sizeData() const;
	~SaverManager();
private:
	std::vector<std::string_view> dataString;
	std::vector<std::pair<sf::Image, sf::Texture>> dataImageAndTexture;
};

