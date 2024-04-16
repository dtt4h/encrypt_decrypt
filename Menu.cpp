#include "menu.h"
#include <iostream>
using namespace std;
void encryptMenu() {
    cout << "If you need to encrypt the text using the Vigenere method, enter \"1\"\n";
    cout << "If you need to encrypt the text using the Table method, enter \"2\"\n";
    cout << "If you need to encrypt the text using the Atbash method, enter \"3\"\n";
}
void decryptMenu() {
    cout << "If you need to decrypt the text using the Vigenere method, enter \"1\"\n";
    cout << "If you need to decrypt the text using the Table method, enter \"2\"\n";
    cout << "If you need to decrypt the text using the Atbash method, enter \"3\"\n";
}
void startMenu() {
    cout << "1) To work with the console, enter \"1\".\n"
            "2) To work with the file, enter \"2\".\n"
            "3) To view the text of the file, enter \"3\".\n"
            "If you need to exit \"0\".\n";
}
