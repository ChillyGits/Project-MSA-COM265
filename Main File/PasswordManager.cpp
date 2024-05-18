#include "PasswordManager.h"
#include "RecordManager.h"
#include<iostream>
using namespace std;

string entered_pass;

void PasswordManager::set_password()
{
	cout << "\n\nPlease enter your new password : "; cin >> Password;
}
string PasswordManager::get_password()
{
	return Password;
}

bool PasswordManager::authentication()
{
	int chances = 3;
	if (Password == "UNSET!*()$*")
	{
		cout << "You havent set a password previously, youll be now asked to set a new password";
		set_password();
	}
	while (chances != 0)
	{
		cout << "\n\nPlease enter your current password : "; cin >> entered_pass;
		if (entered_pass == Password)
		{
			chances = 0;
			return 1;
			
		}
		else
		{
			chances--;
			cout << "\nYou have " << chances << " chances left to enter the right password";
		}
	} 
}
void PasswordManager::add_record()
{
	

	if (authentication() == true)
		RecordManager::add_record();
}

void PasswordManager::view_record()
{
	if (authentication() == true)
		RecordManager::view_record();

}

void PasswordManager::edit_record()
{
	if (authentication() == true)
		RecordManager::edit_record();
}

void PasswordManager::delete_record()
{
	if (authentication() == true)
		RecordManager::delete_record();

}
void PasswordManager::read_file_record()
{
	if (authentication() == true)
		RecordManager::read_file_record();
}
string PasswordManager::get_record_saved()
{
	if (authentication() == true)
		return RecordManager::get_record_saved();
}

