#pragma once
#ifndef OUT_FILE_H
#define OUT_FILE_H
#include "in_file.h"

class out_file {
public:
	out_file(const std::string& file_name);//open
	~out_file();//close
	void write();
	enum Status { norm, abnorm };
	enum Error { OPEN_ERROR };

protected:

private:
	Status _st = norm;
	//Cactus _e;
	std::ofstream _f;
};

#endif // OUT_FILE_H
