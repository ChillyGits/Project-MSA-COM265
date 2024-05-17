#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include "PasswordManager.h"
class FileHandler : public PasswordManager
{
public:
	void save_to_file();
	void read_from_file();
	void update_file();
};
#endif