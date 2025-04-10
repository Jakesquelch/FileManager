#include "FileManager.hpp"

int main()
{
    int choice;
    do {
        std::cout << "1. List files\n2. Create file\n3. Exit\nChoice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {//list files
            std::string output = listFiles(".");
            std::cout << "\n(1) Here are the listed files:\n";
            std::cout << output <<"\n";
            break;
        }
        case 2: {//create files
            std::string filename;
            std::cout << "\n(2) Enter filename here: ";
            std::cin >> filename;

            if (createFile(filename)) {
                std::cout << "File created successfully: " << filename << "\n\n";
            }
            else {
                std::cout << "Error occured creating file\n\n";
            }
            break;
        }
            case 3:
            std::cout << "Goodbye mate!\n";
            break;
            default:
            std::cout << "Invalid choice\n";
        }
    } while (choice != 3);

    return 0;
}