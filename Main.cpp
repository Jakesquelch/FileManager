#include "FileManager.hpp"

int main()
{
    int choice;
    do {
        std::cout << "1. List files\n2. Create file\n3. Delete a file\n4. Rename a file\n5. Exit\nChoice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {//list files
            std::string output = listFiles(".");
            std::cout << "\n(1) Here are the listed files:\n";
            std::cout << output << "\n";
            break;
        }
        case 2: {//create files
            std::string filename;
            std::cout << "\n(2) Enter filename here: ";
            std::cin >> filename;

            if (createFile(filename)) {
                std::cout << "File created successfully!\n\n";
            }
            else {
                std::cout << "Error occured creating file\n\n";
            }
            break;
        }
        case 3: {//delete a file
            std::string filename;
            std::cout << "\n(3) Enter filename here: ";
            std::cin >> filename;

            if (deleteFile(filename)) {
                std::cout << "File deleted successfully!\n\n";
            }
            else {
                std::cout << "Error occured deleting file\n\n";
            }
            break;
        }
        case 4: { //rename a file
            std::string oldName;
            std::string newName;
            std::cout << "\n(4)Enter old filename here: ";
            std::cin >> oldName;
            std::cout << "Enter new fileName here: ";
            std::cin >> newName;
            if (renameFile(oldName, newName)) {
                std::cout << "\nFile renamed successfully!\n\n";
            }
            else {
                std::cout << "Error occured renaming file\n\n";
            }
            break;
        }
            case 5:
            std::cout << "Goodbye mate!\n";
            break;
            default:
            std::cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}