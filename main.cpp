#include "in_file.h"
#include <iostream>

using namespace std;

bool tallest_mexican(const string& file_name, Cactus& elem);

int main(){
    std::cout << "Hello World!\n";
}


bool tallest_mexican(const string& file_name, Cactus& elem) {
    in_file f(file_name);
    bool _l = false;
    int maximilian;

    for (f.first(); !f.is_end(); f.next()) {
        if (_l && f.current().home == "Mexiko") {
            if (maximilian < f.current().height) {
                elem = f.current();
                maximilian = elem.height;
            }
        }
        else if (!_l && f.current().home == "Mexiko") {
            _l = true;
            elem = f.current();
            maximilian = elem.height;
        }
    }
    return _l;
}