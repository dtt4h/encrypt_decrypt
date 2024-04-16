#include <iostream>
#include <fstream>
#include <string>
#include "fileWork.h"
#include "menu.h"
#include "encryption.h"
using namespace std;

void fileWork() {
    ofstream fout;
    ifstream fin;
    string filename;
    int command;
    string text;
    string key;
    string encrypted_text;
    string decrypted_text;
    int x, y;
    while (filename == "") {
        cout << "If you want to open file, enter \"1\".\n"
                "If you want to create new file, enter \"2\".\n";
        cout << "Input: ";
        cin >> command;
        while (command != 1 && command != 2) {
            cout << "If you want to open file, enter \"1\".\n"
                    "If you want to create new file, enter \"2\".\n";
            cout << "Input: ";
            cin >> command;
        }
        if (command == 1) {
            cout << "Enter filename: ";
            cin >> filename;
            fin.open(filename);
            if (!(fin.is_open())) {
                cout << "The file does not exist\n";
                filename = "";
                fin.close();
            }
            else {
                text = "";
                string buff;
                while (!fin.eof()) {
                    getline(fin, buff);
                    text += buff;
                }
            }
            fin.close();
        }
        else {
            if (command == 2) {
                cout << "Enter filename: ";
                cin >> filename;
                cout << "Enter the text. Only lowercase and uppercase English letters will be encrypted." << endl;
                cout << "Input: ";
                cin.get();
                cin.clear();
                while (true) {
                    try {
                        getline(cin, text);

                        if (text.empty()) {
                            throw runtime_error("Input should not be empty.");
                        }

                        break;
                    }
                    catch (const runtime_error& error) {
                        system("CLS");
                        cout << "Error: " << error.what() << endl;
                        cout << "Please enter the text to encrypt: ";
                    }
                }
            }
        }
        fout.open(filename);
    }
    cout << "If you want to encrypt the text, enter \"1\".\n"
            "If you need to decrypt the text, enter \"2\".\n";
    cout << "Input: ";
    cin >> command;
    while (command != 1 && command != 2) {
        cout << "If you want to encrypt the text, enter \"1\".\n"
                "If you need to decrypt the text, enter \"2\".\n";
        cout << "Input: ";
        cin >> command;
    }
    if (command == 1) {
        encryptMenu();
        cout << "Input: ";
        cin >> command;
        while (command < 1 || command > 3) {
            encryptMenu();
            cout << "Input: ";
            cin >> command;
        }
        switch (command) {
            case 1:
                cout << "Enter the key for Vigenere method. The key must contain only English letters and must be one word." << endl;
                cout << "Input: ";
                cin >> key;
                encrypted_text = encrypt_vigenere(text, key);
                cout << "Text encrypted using the Vigenere method. " << endl;
                fout << encrypted_text << endl << endl;
                break;
            case 2:
                cout << "Enter the number of rows and columns\n";
                cin >> y >> x;
                encrypted_text = encrypt_table(text, x, y);
                cout << "Text encrypted using the Table method." << endl;
                fout << encrypted_text << endl << endl;
                break;
            case 3:
                encrypted_text = encrypt_atbash(text);
                cout << "Text encrypted using the Atbash method." << endl;
                fout << encrypted_text << endl << endl;
                break;
        }
    }
    else {
        if (command == 2) {
            decryptMenu();
            cout << "Input: ";
            cin >> command;
            while (command < 1 || command > 3) {
                decryptMenu();
                cout << "Input: ";
                cin >> command;
            }
            switch (command) {
                case 1:
                    cout << "Enter the key for Vigenere method. The key must contain only English letters and must be one word." << endl;
                    cout << "Input: ";
                    cin >> key;
                    decrypted_text = decrypt_vigenere(text, key);
                    cout << "Text decrypted using the Vigenere method." << endl;
                    fout << decrypted_text << endl << endl;
                    break;
                case 2:
                    cout << "Enter the number of rows and columns\n";
                    cin >> y >> x;
                    decrypted_text = decrypt_table(text, x, y);
                    cout << "Text decrypted using the Table method." << endl;
                    fout << decrypted_text << endl << endl;
                    break;
                case 3:
                    decrypted_text = decrypt_atbash(text);
                    cout << "Text decrypted using the Atbash method." << endl;
                    fout << decrypted_text << endl << endl;
                    break;
            }
        }
    }
    fout.close();
}
