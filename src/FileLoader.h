#pragma once

#include <string>
#include <filesystem>
#include <fstream>
#include <iostream> 
#include <regex>


namespace Damocles {
	class FileLoader {
	public:
		FileLoader(const std::string& filePath);
		//void listContent(const std::string &stringh);
		std::string getFullText();
		std::string m_fullText;

		std::string line;
	};
}