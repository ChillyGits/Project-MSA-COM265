#include "Menu.h"
#include "PasswordManager.h"
#include <iostream>
using namespace std;
PasswordManager x;

int user_choice; char repeat_choice;

bool main_menu = false , record_manager = false , pass_manager = false;
void Menu::display_main_menu()
{
	main_menu = false;
	cout << R"(           __________                                 
         .'----------`.                              
         | .--------. |                             
         | |########| |       __________              
         | |########| |      /__________\             
.--------| `--------' |------|    --=-- |-------------.
|        `----,-.-----'      |o ======  |             | 
|       ______|_|_______     |__________|             | 
|      /  %%%%%%%%%%%%  \                             | 
|     /  %%%%%%%%%%%%%%  \                            | 
|     ^^^^^^^^^^^^^^^^^^^^                            | 
+-----------------------------------------------------+
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ )";
	cout << "\nWelcome To Chilly's and Mashhour's Diary Manager!\n";
	get_user_choice();
}
void Menu::get_user_choice()
{
	do
	{
		main_menu = false;
		cout << "     - {Main Menu} - " << "\n----------------------------";
		cout << "\n[1] - Record Manager \n\n[2] - Password Options\n\n[3] - Use the File Handler\n\n[4] - Quit" << "\nPlease enter your choice: ";
		cin >> user_choice;
		switch (user_choice)
		{
		case 1:
		{
			system("cls");
			record_manager_choice();
			break;
		}
		case 2:
		{
			system("cls");
			pass_manager_choice();
			break;
		}

		case 3:
		{
			break;
		}
		case 4:
			main_menu = false;
			break;
		default:
			cout << "Invalid input";
			break;
		}
	} while (main_menu == true); 
}

void Menu::record_manager_choice()
{
	do {
		record_manager = false;
		cout << "    - {Record Manager} - " << "\n-------------------------------";
		cout << "\nWhat would you like to do ? : "
			<< "\n\n[1] - Add New Record/s\n\n[2] - View Record\n\n[3] - Edit Existing Record\n\n[4] - Delete An Existing Record\n\nPlease enter your choice: ";
		cin >> user_choice;
		switch (user_choice)
		{
		case 1:
		{
			x.add_record();
			break;

		}
		case 2:
		{
			x.view_record();
			break;
		}
		case 3:
		{
			x.edit_record();
			break;
		}
		case 4:
		{
			x.delete_record();
			break;
		}
		default:
		{
			cout << "Invalid input";
			break;
		}

		}
		cout << "\n\ndo you want to do another operation? : \n[y] - yes \n[n] - no, go back to main menu\n";
		cin >> repeat_choice;
		if (repeat_choice == 'y' || repeat_choice == 'Y')
		{
			record_manager = true;
			system("cls");
		}
		else
		{
			record_manager = false;
			main_menu = true;
			system("cls");
		}
	} while (record_manager == true);
}
void Menu::pass_manager_choice()
{
	do {
		cout << "     - {Password Manager} - " << "\n----------------------------";
		pass_manager = false;
		cout << "\nWhat would you like to do ? : "
			<< "\n\n[1] - Get current password\n\n[2] - Change current password\nPlease enter your choice: ";
		cin >> user_choice;
		switch (user_choice)
		{
		case 1:
		{
			cout << "\nYour current password is: " << x.get_password();
			break;
		}
		case 2:
		{
			x.set_password();
			break;
		}
		default:
		{
			cout << "Invalid input";
			break;
		}
		}
		cout << "\n\ndo you want to do another operation? : \n[y] - yes \n[n] - no, go back to main menu\n";
		cin >> repeat_choice;
		if (repeat_choice == 'y' || repeat_choice == 'Y')
		{
			pass_manager = true;
			system("cls");
		}
		else
		{
			pass_manager = false;
			main_menu = true;
			system("cls");
		}
	} while (pass_manager == true);
}
