#include <iostream>
#include "encryption.h"
#include "menu.h"
#include "consoleWork.h"
#include "fileWork.h"
#include "fileView.h"
using namespace std;

int main() {
    const string PASS = "0410";
    string text;
    string pass;
    string key;
    string encrypted_text, decrypted_text;
    int x, y;
    int command;
    while (pass != PASS) {
        cout << "Enter password: ";
        cin >> pass;
        try {
            if (pass != PASS) {
                throw runtime_error("Wrong password entered, try again.\n");
            }
            if (pass == PASS) {
                cout << ("Successful, welcome!\n");
            }
        }
        catch (const exception& error) {
            system("CLS");
            cout << "Error: " << error.what() << endl;
        }
    }
    do {
        try {
            startMenu();
            cout << "Input: ";
            cin >> command;

            if (command == 1) {
                consoleWork();
            }
            else if (command == 2) {
                fileWork();
            }
            else if (command == 3) {
                fileView();
            }
            else if (command != 0) {
                throw runtime_error("Invalid command entered. Try again \n");
            }
        }
        catch (const exception& error)
        {
            system("CLS");
            cout << "Error: " << error.what() << endl;
        }
    } while (command != 0);
}
