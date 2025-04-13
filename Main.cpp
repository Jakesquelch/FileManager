#include "FileManager.hpp"

int main()
{
	int choice;
	do {
		std::cout << "1. List files\n";
		std::cout << "2. Create file\n";
		std::cout << "3. Delete a file\n";
		std::cout << "4. Advanced options\n";
		std::cout << "5. Exit\n";
		std::cout << "Choice: ";
		std::cin >> choice;

		//below sorts errors where the user inputs letters instead of numbers as their choice
		if (std::cin.fail()) {
			std::cin.clear(); // clear the error flags
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
			std::cout << "Invalid input, please enter a number next time.\n";
			std::cout << "Press Enter to continue...";
			std::cin.get(); 
			//the above is added in a few times, this is because the app has to be paused in certain places
			//it waits for an enter press before continuing, so the user can see error messages
			//this is becase of system("cls"); (which resets the page before you can see the error message)
			continue; // Go back to the top of the submenu loop
		}

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
				std::cout << "Error occurred creating file\n\n";
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
				std::cout << "Error occurred deleting file, please make sure the file is present!\n\n";
			}
			break;
		}
		case 4: { //additional options
			int subChoice;
			do {
				system("cls"); //clears the console window, adds a refresh affect kinda
				std::cout << "\n -- Advanced Options Menu --\n";
				std::cout << "1. Rename file\n";
				std::cout << "2. Move file\n";
				std::cout << "3. Back to main menu\n\n";
				std::cout << "Choice: ";
				std::cin >> subChoice;

				//below sorts errors where the user inputs letters instead of numbers as their choice
				if (std::cin.fail()) {
					std::cin.clear(); // clear the error flags
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
					std::cout << "Invalid input, please enter a number next time.\n";
					std::cout << "Press Enter to continue...";
					std::cin.get(); 
					continue; // Go back to the top of the submenu loop
				}

				switch (subChoice) {
				case 1: { //sub-rename a file
					std::string oldName, newName;
					std::cout << "\n(1) Enter old filename here: ";
					std::cin >> oldName;
					std::cout << "Enter new fileName here: ";
					std::cin >> newName;

					if (renameFile(oldName, newName)) {
						std::cout << "\nFile renamed successfully!\n\n";
					}
					else {
						std::cout << "Error occurred renaming file\n\n";
						std::cout << "Press Enter to continue...";
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::cin.get(); 
					}
					break;
				}
				case 2: { //sub-move
					std::string source, destination;
					std::cout << "(2) Enter source file path: ";
					std::cin >> source;
					std::cout << "Enter destination file path: ";
					std::cin >> destination;

					if (moveFile(source, destination)) {
						std::cout << "File moved successfully!\n";
					}
					else {
						std::cout << "Failed to move file\n";
					}
					break;
				}
				case 3: { //sub-return to main menu
					std::cout << "Returning to main menu...\n\n";
					break;
				}
				default:
					std::cout << "Invalid choice in Additional Options menu\n";
					break;
				}
			} while (subChoice != 3);
			break;
		}
		case 5:  //exit programme
			std::cout << "Goodbye mate!\n";
			break;
		default:
			std::cout << "\nInvalid choice in Main Menu, try again!\n\n";
		}
	} while (choice != 5);

	return 0;
}