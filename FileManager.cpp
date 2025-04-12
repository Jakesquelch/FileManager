#include <iostream>
#include <filesystem> //allows working with files and directories
#include <fstream> //so we can use std::ofstream
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

bool createFile(const std::string& path) 
{
	std::ofstream file(path);
	if (file) {
		//file created successfully
		file.close();
		return true;
	}
	return false;
}

bool deleteFile(const std::string& file)
{
	try {
		return fs::remove(file); //return true if file deleted 
	}
	catch (const fs::filesystem_error& e) {
		std::cerr << "Error deleting file: " << e.what() << "\n";
		return false;
	}
}

bool renameFile(const std::string& oldName, const std::string& newName) 
{
	try {
		fs::rename(oldName, newName);
		return true;
	}
	catch (const fs::filesystem_error& e) {
		std::cerr << "Error renaming file: " << e.what() << "\n";
		return false;
	}
}
