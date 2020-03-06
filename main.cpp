#include "in_file.h"
#include <iostream>

using namespace std;

bool tallest_mexican(const string& file_name, Cactus& elem);

int main(){
    try {
        Cactus elem;
        if (tallest_mexican("input.txt", elem)) {
            cout << "A legmagasabb mexikoi kaktusz: " << elem << endl;
        }
        else
            cout << "noncs" << endl;
    }
    catch (in_file::Error exc) {
        if (exc == in_file::OPEN_ERROR)
            cout << "Nincs ilye fajl, fonok, hozzad letre izibe" << endl; exit(1);
    }
    return 0;
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