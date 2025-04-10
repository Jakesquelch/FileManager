#include <iostream>
#include <filesystem> //allows working with files and directories
#include "FileManager.hpp"

namespace fs = std::filesystem; //so can write fs instead of std::filesystem 

std::string listFiles(const std::string& directory)
{
	std::ostringstream oss;

	try {
		//iterate over files/directories in the specified directory & append their paths (converted to strings) to result
		for (const auto& entry : fs::directory_iterator(directory)) {
			oss << entry.path().string() << "\n";
		}
	} 
	catch (const fs::filesystem_error& e) {
		return "Error accessing directory: " + std::string(e.what()) + "\n";
	}

	return oss.str();
}
