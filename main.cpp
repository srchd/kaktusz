#include "in_file.h"
#include "out_file.h"
#include <iostream>

using namespace std;

bool tallest_mexican(const string& file_name, Cactus& elem);
bool only_mexicans(const string& in_filename, const string& out_filename);
bool write_red(const string& in_filename, const string& out_filename);

int main(){
    try {
        Cactus elem;
        if (tallest_mexican("input.txt", elem)) {
            cout << "A legmagasabb mexikoi kaktusz: \n" << elem << endl;
        }
        else
            cout << "noncs" << endl;
    }
    catch (in_file::Error exc) {
        if (exc == in_file::OPEN_ERROR)
            cout << "Nincs ilyen bemeneti fajl" << endl; exit(1);
    }

    try {
        if (only_mexicans("input.txt", "mexicans.txt")) {
            cout << "Mexikoiak kiirva a 'mexicans.txt' fajlba!" << endl;

        }
        else
            cout << "Nincs egy mexikoi se!" << endl;
    }
    catch (in_file::Error exc) {
        if(exc == in_file::OPEN_ERROR)
            cout << "Nincs ilyen bemeneti fajl" << endl; exit(1);
    }
    catch (out_file::Error exc) {
        if (exc == out_file::OPEN_ERROR)
            cout << "Nincs ilyen kimeneti fajl" << endl; exit(1);
    }

    try {
        if (write_red("input.txt", "red.txt")) {
            cout << "Pirosak kiirva a 'red.txt' fajlba!" << endl;

        }
        else
            cout << "Nincs egy piros viragu se!" << endl;
    }
    catch (in_file::Error exc) {
        if (exc == in_file::OPEN_ERROR)
            cout << "Nincs ilyen bemeneti fajl" << endl; exit(1);
    }
    catch (out_file::Error exc) {
        if (exc == out_file::OPEN_ERROR)
            cout << "Nincs ilyen kimeneti fajl" << endl; exit(1);
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

bool only_mexicans(const string& in_filename, const string& out_filename){
    in_file f(in_filename);
    out_file of(out_filename);
    bool _l = false;

    for (f.first(); !f.is_end(); f.next()) {
        if (_l && f.current().home == "Mexiko") {
            of.write(f.current());
        }
        else if (!_l && f.current().home == "Mexiko") {
            _l = true;
            of.write(f.current());
        }
    }
    return _l;
}
bool write_red(const string& in_filename, const string& out_filename) {
    in_file f(in_filename);
    out_file of(out_filename);
    bool _l = false;

    for (f.first(); !f.is_end(); f.next()) {
        if (_l && f.current().color == "piros") {
            of.write(f.current());
        }
        else if (!_l && f.current().color == "piros") {
            _l = true;
            of.write(f.current());
        }
    }
    return _l;
}