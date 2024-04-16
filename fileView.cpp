#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "fileView.h"
#include "fileWork.h"
using namespace std;
void fileView() {
    ifstream fin;
    string filename;

    cout << "Enter filename: ";
    cin >> filename;

    try {
        fin.open(filename);
        if (!(fin.is_open())) {
            throw runtime_error("The file does not exist.");
        }
        else {
            string file_contents;
            stringstream buffer;
            buffer << fin.rdbuf();
            file_contents = buffer.str();
            cout << "File contents:\n" << file_contents << endl;
        }
        fin.close();
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
        fin.close();
    }
}
