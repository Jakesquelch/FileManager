#include <iostream>
#include <filesystem>
#include "FileManager.hpp"

namespace fs = std::filesystem; //can write fs instead of std::filesystem everytime

std::string listFiles(std::string directory)
{
	std::string result;

	try {
		for (const auto& entry : fs::directory_iterator(directory)) {
			result += entry.path().string() + "\n";
		}
	}
	catch (const fs::filesystem_error& e) {
		result = "Error accessing directory: " + std::string(e.what()) + "\n";
	}

	return result;
}
