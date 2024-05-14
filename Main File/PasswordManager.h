#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H
#include <string>
#include "RecordManager.h"
using namespace std;
class PasswordManager:public RecordManager
{
	string Password="UNSET!*()$*";
public:
	string get_password();
	void set_password();
	void add_record();
	void view_record();
	void edit_record();
	void delete_record();
protected:
	bool authentication();
};
#endif