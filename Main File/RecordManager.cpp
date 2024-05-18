#include "RecordManager.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int record_choice;
string saved_records;
vector <RecordManager> record;	//vector that holds all records	
string RecordManager::get_record_saved()
{
	return saved_records;
}


void RecordManager::add_record()
{
	int record_amount;

	cout << "\nHow many records do you want to add? : "; cin >> record_amount;
	cin.ignore();
	for (int i(0); i < record_amount; i++)
	{
		RecordManager temp;
		cout << "\nEnter the data for records no." << i + 1;
	
		cout << "\nName : "; getline(cin, temp.name);
		
		cout << "\nTask Duration : "; getline(cin, temp.task_duration); 
		
		cout << "\nAddress : "; getline(cin, temp.address);
		
		cout << "\nDate and Time : "; getline(cin, temp.date_time);
		record.push_back(temp);
	}
	save_record();
}
void RecordManager::save_record()
{
	string tempo;
	for (int i(0); i < record.size(); i++)
	{
		tempo += "\nRecords No [" + to_string(i + 1) + "]"
			+ "\n-------------\n->Name : " + record[i].name
			+ "\n\n->Task Duration : " + record[i].task_duration
			+ "\n\n->Address : " + record[i].address
			+ "\n\n->Date and Time : " + record[i].date_time;
	}
	saved_records = tempo;
}
void RecordManager::view_record()
	{
	cout << "    - {Saved Records} - " << "\n----------------------------------";
	cout << saved_records;
	}
void RecordManager::edit_record()
{
	cin.ignore();
	cout << "\n--------------------------------------------\nWhich record would you like to modify? :  "; 
	do
	{
		cin >> record_choice;
		if ((record_choice - 1) > record.size())
		{
			cout << "\nInvalid Record - out of bounds \nPlease enter a valid record within bounds : ";
		}
	} while (record_choice - 1 > record.size());

	cout << "\nEnter the new data for records no." << record_choice;


	cin.ignore();
	
	cout << "\nName : "; getline(cin,record[record_choice -1].name);
	
	cout << "\nTask Duration : "; getline(cin, record[record_choice -1].task_duration);
	
	cout << "\nAddress : "; getline(cin, record[record_choice -1].address);
	
	cout << "\nDate and Time : "; getline(cin, record[record_choice -1].date_time);
	save_record();
	view_record();

	
}
void RecordManager::delete_record()
{
	cout << "\nWhich record would you like to delete? : "; cin >> record_choice;

	record.erase(record.begin() + (record_choice-1));
	save_record();
	view_record();
}
void RecordManager::read_file_record()
{
	string file_path, file_name;
	cout << "\n\nPlease enter the directory of the file you will read from: "; cin >> file_path;
	cout << "\n\nPlease enter a name for your text file: "; cin >> file_name;
	ifstream file((file_path + "/" + file_name + ".txt"));
	int i(0);
	if (file.is_open())
	{
		do {
			RecordManager temp;


			getline(file, temp.name);

			getline(file, temp.task_duration);

			getline(file, temp.address);

			getline(file, temp.date_time);
			record.push_back(temp);
		} while (!file.eof());
		file.close();
	}
	else
	{
		cout << "\n\nError reading from file";
	}
	
	save_record();
}
