#include "Vocabulary.h"

Damocles::Vocabulary::Vocabulary() {
	// Initialize special tokens
	id_to_token_.push_back("<PAD>");
	id_to_token_.push_back("<UNK>");
	id_to_token_.push_back("<BOS>");
	id_to_token_.push_back("<EOS>");

	token_to_id_["<PAD>"] = PAD_TOKEN_ID;
	token_to_id_["<UNK>"] = UNK_TOKEN_ID;
	token_to_id_["<BOS>"] = BOS_TOKEN_ID;
	token_to_id_["<EOS>"] = EOS_TOKEN_ID;
}

std::string Damocles::Vocabulary::normalizeWord(const std::string& word) const {
	std::string normalized;
	normalized.reserve(word.size());
	// Convert to lowercase and remove punctuations
	for (char c : word) {
		if (std::isalnum(static_cast<unsigned char>(c)) || c == '\'' || c == '-')
			normalized += std::tolower(static_cast<unsigned char>(c));
	}
	return normalized.empty() ? word : normalized;
}

std::vector<std::string> Damocles::Vocabulary::extractWord(const std::string& text) const {

	// this is a vector to store all the words
	std::vector<std::string> words;
	// isjkastringstream will divide the words with whitceassas
	std::istringstream stream(text);

	std::string word;

	while (stream >> word) {
		std::string normalized = normalizeWord(word);
		if (!normalized.empty()) {
			words.push_back(normalized);
		}
	}
	return words;
}

void Damocles::Vocabulary::buildFromText(const std::string& text) {
	std::unordered_map<std::string, size_t> word_freq;

	auto words = extractWord(text);
	for (const auto& word : words) {
		word_freq[word]++;
	}


	// sort by frequency
	std::vector<std::pair<std::string, size_t>> sorted_words(word_freq.begin(), word_freq.end());
	std::sort(sorted_words.begin(), sorted_words.end(),
		[](const auto& a, const auto& b) { return a.second > b.second; });

	// Add to vocab

	for (const auto& [word, freq] : sorted_words) {
		if (token_to_id_.find(word) == token_to_id_.end()) {
			size_t id = id_to_token_.size();
			token_to_id_[word] = id;
			id_to_token_.push_back(word);
		}
	}
	std::cout << " Vocab built with " << id_to_token_.size();
	std::cout << "Most frequent tokens:\n";
	for (size_t i = 4; i < std::min(size_t(14), id_to_token_.size()); ++i) {
		std::cout << "  " << id_to_token_[i] << " (ID: " << i << ")\n";
	}
}

void Damocles::Vocabulary::save(const std::string& filename) const {
	std::ofstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Failed to save vocabulary to " << filename << "\n";
		return;
	}

	// Save vocabulary size
	file << id_to_token_.size() << "\n";

	// Save each token
	for (const auto& token : id_to_token_) {
		file << token << "\n";
	}


	std::cout << "Vocabulary saved to " << filename << "\n";
}


std::vector<size_t> Damocles::Vocabulary::encode(const std::string& text) const {
	std::vector<size_t> token_ids;
	auto words = extractWord(text);

	for (const auto& word : words) {
		token_ids.push_back(getTokenId(word));
	}
	return token_ids;
}

size_t Damocles::Vocabulary::getTokenId(const std::string& word) const {
	auto it = token_to_id_.find(word);
	return (it != token_to_id_.end()) ? it->second : UNK_TOKEN_ID;
}

void Damocles::Vocabulary::printFullText(std::string text) {
	std::cout << text;
}