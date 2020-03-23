#include "out_file.h"
out_file::out_file(const std::string& filename) {
	_f.open(filename.c_str());
	if (_f.fail())
		throw OPEN_ERROR;
}
out_file::~out_file() {
	_f.close();
}
void out_file::write(const Cactus& c) {
	_f << c << std::endl;
}