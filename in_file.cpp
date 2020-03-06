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

in_file::in_file(const std::string& file_name) {
	_f.open(file_name.c_str());
	if (_f.fail())
		throw OPEN_ERROR;
	else
		_st = norm;

}
in_file::~in_file() {
	_f.close();
}
void in_file::first() {
	next();
}
void in_file::next() {
	_f >> _e;
	if (_f.fail())
		_st = abnorm;
	else
		_st = norm;
}
Cactus in_file::current() const {
	return _e;
}
bool in_file::is_end() const {
	return _st == abnorm;
}