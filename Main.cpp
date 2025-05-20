#include "FileManager.hpp"
#include <string>

void displayMenu()
{
	system("cls");
	std::cout << "\nWelcome to FileManager!\n\n";
	std::cout << "1. List files\n";
	std::cout << "2. Create file\n";
	std::cout << "3. Delete a file\n";
	std::cout << "4. Advanced options\n";
	std::cout << "5. Exit\n";
	std::cout << "\nEnter your choice: ";
}

void additionalMenu()
{
	system("cls"); // clears the console window, adds a refresh affect kinda
	std::cout << "\n -- Advanced Options Menu --\n";
	std::cout << "1. Rename file\n";
	std::cout << "2. Move file\n";
	std::cout << "3. Back to main menu\n\n";
	std::cout << "Enter your choice: ";
}

void pauseForUser()
{
	std::cout << "Press enter to continue...";
	std::cin.get(); // waits for user to press enter
					// the above is added in a few times, this is because the app has to be paused in certain places
					// it waits for an enter press before continuing, so the user can see error messages
					// this is becase of system("cls"); (which resets the page before you can see the error message)
}

void wrongUserInput()
{
	std::cin.clear();													// clear the error flags
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
	std::cout << "Invalid input, please enter a number next time!\n\n";
	pauseForUser();
}

int main()
{
	int choice;
	do
	{
		displayMenu();
		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // this clears the input buffer of \n

		// below sorts errors where the user inputs letters instead of numbers as their choice
		if (std::cin.fail())
		{
			wrongUserInput();
			continue; // Go back to the top of the submenu loop
		}

		// Check if choice is in the valid range
		if (choice < 1 || choice > 5)
		{
			std::cout << "\nInvalid choice in Main Menu, please enter a number between 1 and 5!\n\n";
			pauseForUser();
			continue;
		}

		switch (choice)
		{
		case 1:
		{ // list files
			std::string output = listFiles(".");
			std::cout << "\n(1) Here are the listed files:\n";
			std::cout << output << "\n";
			pauseForUser();
			break;
		}
		case 2:
		{ // create files
			std::string filename;
			std::cout << "\n(2) Enter filename here: ";
			std::getline(std::cin, filename);
			// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear leftover input otherwise messes up my pauseforuser

			createFile(filename);
			pauseForUser();
			break;
		}
		case 3:
		{ // delete a file
			std::string filename;
			std::cout << "\n(3) Enter filename here: ";
			std::getline(std::cin, filename);
			// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear leftover input otherwise messes up my pauseforuser

			deleteFile(filename);
			pauseForUser();
			break;
		}
		case 4:
		{ // additional options
			int subChoice;
			do
			{
				additionalMenu();
				std::cin >> subChoice;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // this clears the input buffer of \n

				// below sorts errors where the user inputs letters instead of numbers as their choice
				if (std::cin.fail())
				{
					wrongUserInput();
					continue; // Go back to the top of the submenu loop
				}

				if (subChoice < 1 || subChoice > 3)
				{
					std::cout << "\nInvalid choice in Additional Options Menu, please enter a number between 1 and 3!\n\n";
					pauseForUser();
					continue;
				}

				switch (subChoice)
				{
				case 1:
				{ // sub-rename a file
					std::string oldName, newName;
					std::cout << "\n(1) Enter old file name here: ";
					std::cin >> oldName;
					std::cout << "Enter new file name here: ";
					std::cin >> newName;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

					renameFile(oldName, newName);
					pauseForUser();
					break;
				}
				case 2:
				{ // sub-move
					std::string source, destination;
					std::cout << "(2) Enter source file path: ";
					std::cin >> source;
					std::cout << "Enter destination file path: ";
					std::cin >> destination;

					moveFile(source, destination);
					pauseForUser();
					break;
				}
				case 3:
				{ // sub-return to main menu
					std::cout << "Returning to main menu...\n";
					break;
				}
				default:
					std::cout << "Invalid choice in Additional Options menu\n";
					break;
				}
			} while (subChoice != 3);
			break;
		}
		case 5: // exit programme
			std::cout << "\nGoodbye!\nExiting...";
			break;
		default:
			std::cout << "\nInvalid choice in Main Menu, try again!\n\n";
		}
	} while (choice != 5);

	return 0;
}