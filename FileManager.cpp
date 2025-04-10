#include <iostream>
#include <filesystem> //allows working with files and directories
#include "FileManager.hpp"

namespace fs = std::filesystem; //so can write fs instead of std::filesystem 

std::string listFiles(std::string directory)
{
	std::string result;

	try {
		//iterate over files/directories in the specified directory & append their paths (converted to strings) to result
		for (const auto& entry : fs::directory_iterator(directory)) {
			result += entry.path().string() + "\n";
		}
	} 
	catch (const fs::filesystem_error& e) {
		result = "Error accessing directory: " + std::string(e.what()) + "\n";
	}

	return result;
}
