#include "DamoclesAI.h"
#include "FileLoader.h"

int main() {
	std::cout << "Damocles AI\n";
	// File Path 
	std::cout << "CWD: " << std::filesystem::current_path() << "\n";
	Damocles::FileLoader testFile("../../../Data/test.txt");
}