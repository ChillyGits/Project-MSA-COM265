#include "RecordManager.h"
#include <iostream>
using namespace std;
int record_amount, record;
RecordManager* r;

RecordManager::RecordManager()
{
	task_duration = ""; name = ""; address = ""; date_time = "";
}
void RecordManager::add_record()
{

	cout << "\nHow many records do you want to save : ?"; cin >> record_amount;
	cin.ignore();
	r = new RecordManager[record_amount];
	for (int i(0); i < record_amount; i++)
	{
		
		cout << "\nEnter the data for records no." << i + 1;
	
		cout << "\nName : "; getline(cin,r[i].name);
		
		cout << "\nTask Duration : "; getline(cin, r[i].task_duration); 
		
		cout << "\nAddress : "; getline(cin, r[i].address);
		
		cout << "\nDate and Time : "; getline(cin, r[i].date_time);
		
	}
}
void RecordManager::view_record()
	{
	cout << "\n--------------------------------------------\nHere is all the saved records : ";
	for (int i(0); i < record_amount; i++)
	{
		cout << "\nThe data for records no." << record_amount + 1;
		cout << "\nName : "<<r[i].name;
		cout << "\nTask Duration : "<< r[i].task_duration;
		cout << "\nAddress : "<<r[i].address;
		cout << "\nDate and Time : " <<r[i].date_time;
	}
	}
void RecordManager::edit_record()
{
	cin.ignore();
	cout << "\n--------------------------------------------\nWhich record would you like to modify? :  "; 
	do
	{
		cin >> record;
		if ((record - 1) > record_amount)
		{
			cout << "\nInvalid Record - out of bounds \nPlease enter a valid record within bounds : ";
		}
	} while (record - 1 > record_amount);

	cout << "\nEnter the new data for records no." << record;
	
	cout << "\nName : "; getline(cin,r[record-1].name);
	
	cout << "\nTask Duration : "; getline(cin, r[record-1].task_duration);
	
	cout << "\nAddress : "; getline(cin, r[record-1].address);
	
	cout << "\nDate and Time : "; getline(cin, r[record-1].date_time);
	view_record();

	
}
void RecordManager::delete_record()
{

}