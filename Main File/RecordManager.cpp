#include "RecordManager.h"
#include <iostream>
#include <vector>
using namespace std;
int record_choice;
vector <RecordManager> record;	//vector that holds all records	


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
}
void RecordManager::view_record()
	{
	cout << "    - {Saved Records} - " << "\n----------------------------------";
	for (int i(0); i <record.size(); i++)
	{
		cout << "\nRecords No [" << i + 1<<"]";
		cout << "\n-------------\n->Name : "<<record[i].name;
		cout << "\n\n->Task Duration : "<< record[i].task_duration;
		cout << "\n\n->Address : "<<record[i].address;
		cout << "\n\n->Date and Time : " <<record[i].date_time;
	}
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
	view_record();

	
}
void RecordManager::delete_record()
{
	cout << "\nWhich record would you like to delete? : "; cin >> record_choice;

	record.erase(record.begin() + (record_choice-1));

	view_record();
}