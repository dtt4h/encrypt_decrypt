#include <iostream>
#include "consoleWork.h"
#include "encryption.h"

using namespace std;

void consoleWork() {
    int command;

    cout << "If you want to encrypt the text, enter \"1\".\n";
    cout << "If you need to decrypt the text, enter \"2\".\n";
    cout << "Input: ";
    cin >> command;

    if (command == 1) {
        cout << "Enter the text to encrypt. Only lowercase and uppercase English letters will be encrypted.\n";
        string text;
        cout << "Input: ";
        cin >> text;

        cout << "If you need to encrypt the text using the Vigenere method, enter \"1\"\n";
        cout << "If you need to encrypt the text using the Table method, enter \"2\"\n";
        cout << "If you need to encrypt the text using the Atbash method, enter \"3\"\n";
        cout << "Input: ";
        cin >> command;

        string encrypted_text;
        switch (command) {
            case 1: {
                string key;
                cout << "Enter the key for Vigenere method. The key must contain only English letters and must be one word.\n";
                cout << "Input: ";
                cin >> key;
                encrypted_text = encrypt_vigenere(text, key);
                cout << "Text encrypted using the Vigenere method:\n" << encrypted_text << endl;

                char choice;
                cout << "If you need to decrypt back, enter \"1\". If you don't need, enter any other character.\n";
                cout << "Input: ";
                cin >> choice;
                if (choice == '1') {
                    string decrypted_text = decrypt_vigenere(encrypted_text, key);
                    cout << "Text decrypted using the Vigenere method:\n" << decrypted_text << endl;
                }
                break;
            }
            case 2: {
                int table_x_size, table_y_size;
                cout << "Enter the number of rows and columns\n";
                cout << "Input: ";
                cin >> table_y_size >> table_x_size;
                encrypted_text = encrypt_table(text, table_x_size, table_y_size);
                cout << "Text encrypted using the Table method:\n" << encrypted_text << endl;

                char choice;
                cout << "If you need to decrypt back, enter \"1\". If you don't need, enter any other character.\n";
                cout << "Input: ";
                cin >> choice;
                if (choice == '1') {
                    string decrypted_text = decrypt_table(encrypted_text, table_y_size, table_x_size);
                    cout << "Text decrypted using the Table method:\n" << decrypted_text << endl;
                }
                break;
            }
            case 3: {
                encrypted_text = encrypt_atbash(text);
                cout << "Text encrypted using the Atbash method:\n" << encrypted_text << endl;

                char choice;
                cout << "If you need to decrypt back, enter \"1\". If you don't need, enter any other character.\n";
                cout << "Input: ";
                cin >> choice;
                if (choice == '1') {
                    string decrypted_text = decrypt_atbash(encrypted_text);
                    cout << "Text decrypted using the Atbash method:\n" << decrypted_text << endl;
                }
                break;
            }
            default:
                cout << "Invalid input\n";
                break;
        }
    } else if (command == 2) {
        cout << "Enter the text to decrypt. Only lowercase and uppercase English letters will be decrypted.\n";
        string text;
        cout << "Input: ";
        cin >> text;

        cout << "If you need to decrypt the text using the Vigenere method, enter \"1\"\n";
        cout << "If you need to decrypt the text using the Table method, enter \"2\"\n";
        cout << "If you need to decrypt the text using the Atbash method, enter \"3\"\n";
        cout << "Input: ";
        cin >> command;

        string decrypted_text;
        switch (command) {
            case 1: {
                string key;
                cout << "Enter the key for Vigenere method. The key must contain only English letters and must be one word.\n";
                cout << "Input: ";
                cin >> key;
                decrypted_text = decrypt_vigenere(text, key);
                cout << "Text decrypted using the Vigenere method:\n" << decrypted_text << endl;
                break;
            }
            case 2: {
                int table_x_size, table_y_size;
                cout << "Enter the number of rows and columns\n";
                cout << "Input: ";
                cin >> table_y_size >> table_x_size;
                decrypted_text = decrypt_table(text, table_y_size, table_x_size);
                cout << "Text decrypted using the Table method:\n" << decrypted_text << endl;
                break;
            }
            case 3: {
                decrypted_text = decrypt_atbash(text);
                cout << "Text decrypted using the Atbash method:\n" << decrypted_text << endl;
                break;
            }
            default:
                cout << "Invalid input\n";
                break;
        }
    } else {
        cout << "Invalid input\n";
    }
}
