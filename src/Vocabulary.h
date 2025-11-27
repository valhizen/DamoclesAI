#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <fstream>

namespace Damocles {

	class Vocabulary {
	public:
		Vocabulary();
		void printFullText(std::string text);

		// First normailze the whole text

		std::string normalizeWord(const std::string& word) const;

		// Then Extract Words From text

		std::vector<std::string> extractWord(const std::string& text) const;

		// This will build vocab from the extractWord
		void buildFromText(const std::string& text);

		// This will save vocab
		void save(const std::string& filename) const;

		std::vector<size_t> encode(const std::string& text) const;

		size_t getTokenId(const std::string& word) const;
		// Helper to get size
		size_t size() const { return id_to_token_.size(); }


	private:
		std::unordered_map<std::string, size_t> token_to_id_;
		std::vector < std::string> id_to_token_;

		static constexpr size_t PAD_TOKEN_ID = 0;
		static constexpr size_t UNK_TOKEN_ID = 1;
		static constexpr size_t BOS_TOKEN_ID = 2;
		static constexpr size_t EOS_TOKEN_ID = 3;

	};
}