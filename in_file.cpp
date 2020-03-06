#include "in_file.h"
std::ostream& operator<<(std::ostream& os, const Cactus& c) {
	os << "Nev: " << c.name << "\nOshaza: " << c.home << "\nVirag: " << c.color << "\nMagassag: " << c.height;
	return os;
}
std::istream& operator>>(std::istream& is, Cactus& c) {
	getline(is, c.name, '\n');
	getline(is, c.home, '\n');
	getline(is, c.color, '\n');
	std::string str;
	getline(is, str, '\n');
	c.height = atoi(str.c_str());

	return is;
}