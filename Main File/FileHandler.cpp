#include "FileHandler.h"
#include "PasswordManager.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
ofstream file;
string file_name, file_path;

void FileHandler::save_to_file()
{
	cout << "\n\nPlease enter a directory to save your file in: "; cin >> file_path;
	cout << "\n\nPlease enter a name for your text file: "; cin >> file_name;
	
	file.open((file_path + "/" + file_name + ".txt"));
	if(file.is_open())
	{
		file << PasswordManager::get_record_saved();
		file.close();
		cout << "\n\nDone ";
	}
	else
	{
		cout << "\n\nError Opening File";
	}
}
void FileHandler::read_from_file()
{
	PasswordManager::read_file_record();
}
void FileHandler::update_file()
{
	file.trunc;
	file.open(file_path + "/" + file_name + ".txt");
	if (file.is_open())
	{
		file << PasswordManager::get_record_saved();
		file.close();
		cout << "\n\nDone ";
	}
	else
	{
		cout << "\n\nError Opening File";
	}
	
}
