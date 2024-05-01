#ifndef RecordManager_h
#define RecordManager_h
#include <string>
using namespace std;
class RecordManager
{
	string task_duration, name, address, date_time;
public : 
	RecordManager();
	void add_record();
	void view_record();
	void edit_record();
	void delete_record();
};

#endif // !RecordManager_h

