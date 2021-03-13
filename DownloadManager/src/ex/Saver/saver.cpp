#include "saver.h"

Saver::Saver()
{
}

bool Saver::save(std::string_view tmp, std::string_view path,int type)
{
	auto size = tmp.size();
	sf::Texture file;
	file.loadFromMemory(tmp.data(), size);
	
	sf::Image image(file.copyToImage());
	//
	dataString.push_back(tmp);
	dataTexture.push_back(file);
	//
	return image.saveToFile(path.data());;
	//return false;
}

std::string Saver::read(std::string_view tmp)
{
	std::filesystem::path path = tmp;

	// Open the stream to 'lock' the file.
	std::ifstream f(path, std::ios::in | std::ios::binary);
	// Obtain the size of the file.
	const auto sz = std::filesystem::file_size(path);
	// Create a buffer.
	std::string result(sz, '\0');
	// Read the whole file into the buffer.
	f.read(result.data(), sz);
	//return "";
	return result;
}

Saver::~Saver()
{

}