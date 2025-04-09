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
            std::cout << output;
            break;
        }
            case 2: //create files
            break;
            case 3:
            std::cout << "Goodbye mate!\n";
            break;
            default:
            std::cout << "Invalid choice\n";
        }
    } while (choice != 3);

    return 0;
}