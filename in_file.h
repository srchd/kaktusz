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

#endif // IN_FILE_H
