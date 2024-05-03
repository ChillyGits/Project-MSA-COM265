#include "Menu.h"
#include "RecordManager.h"
#include <iostream>
using namespace std;
RecordManager x;
int user_choice;
bool repeat;
void Menu::display_main_menu()
{
	system("cls");
	cout << "Welcome To Chilly's and Mashhour's Diary Manager!"
		<< "\nHere are th available options: "
		<<"\n[1] - Record Manager \n\n[2] - Password Potected Record Manager\n\n[3] - Use the File Handler\n\n[4] - Quit" << "\nPlease enter your choice: ";
	get_user_choice();
}
void Menu::get_user_choice()
{
	
	cin >> user_choice;
	switch (user_choice)
	{
	case 1:
	{
		record_manager_choice();
		break;
	}
	case 2:

	case 3:

	case 4:

	default:
		cout << "Invalid input";
		break;
	}
}

void Menu::record_manager_choice()
{
	do {
		system("cls");
	cout << "What would you like to do ? : "
		<< "\n\n[1] - Add New Record/s\n\n[2] - View Record\n\n[3] - Edit Existing Record\n\n[4] - Delete An Existing Record\n\n[5] - Main Menu \nPlease enter your choice: ";
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
		case 5:
		{

			display_main_menu();
			break;
		}
		default:
		{
			cout << "Invalid input";

			break;
		}
		
		}
		cout << "\n\nDo you want to do another operation? : \n[0] - No \n[1] - Yes\n";
		cin >> repeat;
		
	} while (repeat == 1);
	
}
