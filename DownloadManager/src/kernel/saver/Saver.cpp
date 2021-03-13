#include "../saver/Saver.h"

SaverManager::SaverManager()
{
}

bool SaverManager::save(std::string_view tmp, std::string_view path, int type = 1)
{
	if (type == 1) {
		auto size = tmp.size();
		sf::Texture file;
		file.loadFromMemory(tmp.data(), size);

		sf::Image image(file.copyToImage());
		dataString.push_back(tmp);//logging
		dataImageAndTexture.push_back({ image,file });

		return image.saveToFile(path.data());
	}
	return false;
}

std::string SaverManager::read(std::string_view tmp)
{
	std::filesystem::path path = tmp;
	std::ifstream f(path, std::ios::in | std::ios::binary);
	const auto sz = std::filesystem::file_size(path);
	std::string buffer(sz, '\0');
	f.read(buffer.data(), sz);
	return buffer;
}

ll SaverManager::sizeData() const
{
	return ll(dataString.size()) + ll(dataImageAndTexture.size());
}

SaverManager::~SaverManager()
{
}