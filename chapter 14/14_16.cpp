#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FName2 {
    ifstream file;
    string fileName;
    bool named;
public:
    FName2() : named(false) {}
    FName2(const string& fname)
        : fileName(fname), file(fname.c_str()) {
        named = true;
    }
    string name() const { return fileName; }
    void name(const string& newName) {
        if(named) return; 
        fileName = newName;
        named = true;
    }
    operator ifstream&() { return file; }

    void demonstrate() {
        cout << "File name: " << fileName << endl;
        cout << "is_open(): " << file.is_open() << endl;
        cout << "eof(): " << file.eof() << endl;
        cout << "good(): " << file.good() << endl;
        cout << "fail(): " << file.fail() << endl;
        cout << "bad(): " << file.bad() << endl;
        file.clear(); 
        cout << "seekg(0, ios::end): ";
        file.seekg(0, ios::end);
        cout << "tellg(): " << file.tellg() << endl;
        file.seekg(0, ios::beg); 
        cout << "After seekg(0, ios::beg): " << file.tellg() << endl;
    }
};

int main() {
    FName2 file("FName2.cpp");
    file.demonstrate();
    return 0;
} 