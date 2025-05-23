#include <iostream>
#include <limits>

std::string listFiles(const std::string& directory);

bool createFile(const std::string& path);

bool deleteFile(const std::string& file);

bool renameFile(const std::string& oldName, const std::string& newName);

bool moveFile(const std::string& source, const std::string& destination);