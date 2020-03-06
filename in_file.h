#pragma once
#ifndef IN_FILE_H
#define IN_FILE_H

#include <iostream>
#include <string>
#include <fstream>

struct Cactus {
	std::string name;
	std::string home;
	std::string color;
	int height;

	friend std::ostream& operator<<(std::ostream& os, const Cactus& c);
	friend std::istream& operator>>(std::istream& is, Cactus& c);
};

class in_file {
public:
	in_file(const std::string& file_name);//open
	~in_file();//close
	void first();
	void next();
	Cactus current() const;
	bool is_end() const;
	enum Status{norm, abnorm};
	enum Error{OPEN_ERROR};

protected:

private:
	Status _st = norm;
	Cactus _e;
	std::ifstream _f;
};

#endif // IN_FILE_H
