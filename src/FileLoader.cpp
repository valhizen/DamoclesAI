#include "FileLoader.h"

Damocles::FileLoader::FileLoader(const std::string &filePath) {
	std::ifstream inputFile(filePath);
	line;
	if (!inputFile.is_open()) {
		std::cout << "Input File Didn't open : ";
		std::cout << filePath << "\n";
	}
	while (std::getline(inputFile, line)) {
		listContent(line);
	}
}


void Damocles::FileLoader::listContent(const std::string &line) {

	std::cout << " This is the full text : " << line << "\n";
	std::istringstream stream(line);
	std::string word;
	int i = 0;
	while (stream >> word)
	{
		i++;
		std::cout << " Word  " << i << " : " << word << "\n";
	}
}

