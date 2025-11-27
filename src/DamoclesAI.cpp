#include "DamoclesAI.h"
#include "FileLoader.h"
#include "Vocabulary.h"

int main() {
	std::cout << "Damocles AI\n";
	// File Path 
	std::cout << "CWD: " << std::filesystem::current_path() << "\n";
	
	//  Load Shakespeare text
	Damocles::FileLoader loader("../../../Data/shakesphere.txt");
	
	// This will  Build vocabulary
	Damocles::Vocabulary vocab;
	vocab.buildFromText(loader.getFullText());
	
	// To  Save vocabulary
	vocab.save("../../../Data/shakesphere_vocab.txt");
	std::cout << "\n=== Testing Encoding ===\n";
	
	// Test 1: Simple sentence
	std::string test1 = "To be or not to be";
	auto ids1 = vocab.encode(test1);
	
	std::cout << "\nTest 1: \"" << test1 << "\"\n";
	std::cout << "Token IDs: ";
	for (size_t id : ids1) {
		std::cout << id << " ";
	}
	std::cout << "\n";
	
	// Test 2: Shakespeare quote
	std::string test2 = "What is the name?";
	auto ids2 = vocab.encode(test2);
	
	std::cout << "\nTest 2: \"" << test2 << "\"\n";
	std::cout << "Token IDs: ";
	for (size_t id : ids2) {
		std::cout << id << " ";
	}
	std::cout << "\n";
	
	// Test 3: Unknown word (not in vocabulary)
	std::string test3 = "Hello xyzabc unknown";
	auto ids3 = vocab.encode(test3);
	
	std::cout << "\nTest 3: \"" << test3 << "\" (contains unknown word)\n";
	std::cout << "Token IDs: ";
	for (size_t id : ids3) {
		std::cout << id << " ";
		if (id == 1) {
			std::cout << "(UNK) ";
		}
	}
	std::cout << "\n";
	
	// Test 4: Show vocabulary size
	std::cout << "\n=== Vocabulary Statistics ===\n";
	std::cout << "Total unique words: " << vocab.size() << "\n";
	
	return 0;
}