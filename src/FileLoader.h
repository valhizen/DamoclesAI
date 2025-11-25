#pragma once

#include <string>
#include <filesystem>
#include <fstream>
#include <iostream> 


namespace Damocles {
	class FileLoader{
	public:
		FileLoader(const std::string& filePath);
		void listContent(const std::string &stringh);

	std::string line;
	};
}