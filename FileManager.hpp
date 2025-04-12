#include <iostream>

std::string listFiles(const std::string& directory);

bool createFile(const std::string& path);

bool deleteFile(const std::string& file);

bool renameFile(const std::string& oldName, const std::string& newName);