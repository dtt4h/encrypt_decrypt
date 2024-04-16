#include "encryption.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

string encrypt_vigenere(const string& text, string key) {
    string encrypted;
    for (int i = 0; i < text.size(); ++i) {
        char encrypting_letter = key[i % key.size()];
        if ((encrypting_letter >= 65) && (encrypting_letter <= 90)) {
            encrypting_letter -= 65;
        }
        else {
            if ((encrypting_letter >= 97) && (encrypting_letter <= 122)) {
                encrypting_letter -= 97;
            }
            else {
                cout << "The key must contain only English letters!";
                return "";
            }
        }
        char character = text[i];
        if (character >= 65 && character <= 90) {
            encrypted += ((((character - 65) + encrypting_letter) % 26) + 65);
        }
        else {
            if (character >= 97 && character <= 122) {
                encrypted += ((((character - 97) + encrypting_letter) % 26) + 97);
            }
            else {
                encrypted += character;
            }
        }
    }
    return encrypted;
}

string decrypt_vigenere(const string& text, string key) {
    string decrypted;
    for (int i = 0; i < text.size(); ++i) {
        char decrypting_letter = key[i % key.size()];
        if ((decrypting_letter >= 65) && (decrypting_letter <= 90)) {
            decrypting_letter -= 65;
        }
        else {
            if ((decrypting_letter >= 97) && (decrypting_letter <= 122)) {
                decrypting_letter -= 97;
            }
            else {
                cout << "The key must contain only English letters!";
                return "";
            }
        }
        char character = text[i];
        if (character >= 65 && character <= 90) {
            decrypted += ((((character - 65) - decrypting_letter + 26) % 26) + 65);
        }
        else {
            if (character >= 97 && character <= 122) {
                decrypted += ((((character - 97) - decrypting_letter + 26) % 26) + 97);
            }
            else {
                decrypted += character;
            }
        }
    }
    return decrypted;
}

string encrypt_table(const string& text, int table_x_size, int table_y_size) {
    string encrypted;
    for (int part = 0; part <= ceil(text.size() / (table_x_size * table_y_size)); ++part) {
        vector<vector<char>> table(table_y_size);
        for (int i = 0; i < table_y_size; ++i) {
            table[i].resize(table_x_size);
        }
        int part_len = table_x_size * table_y_size;
        if (part == (ceil(text.size() / (table_x_size * table_y_size)))) {
            part_len = (text.size()) % (table_x_size * table_y_size);
        }
        string sub_string = text.substr(part * (table_x_size * table_y_size), part_len);
        for (int i = 0; i < part_len; ++i) {
            table[i / table_x_size][i % table_x_size] = sub_string[i];
        }
        for (int i = 0; i < table_x_size; ++i) {
            for (int j = 0; j < table_y_size; ++j) {
                encrypted += table[j][i];
            }
        }
    }
    return encrypted;
}
string decrypt_table(const string& text, int table_y_size, int table_x_size) {
    string decrypted;
    for (int part = 0; part <= ceil(text.size() / (table_x_size * table_y_size)); ++part) {
        vector<vector<char>> table(table_y_size);
        for (int i = 0; i < table_y_size; ++i) {
            table[i].resize(table_x_size);
        }
        int part_len = table_x_size * table_y_size;
        if (part == (ceil(text.size() / (table_x_size * table_y_size)))) {
            part_len = (text.size()) % (table_x_size * table_y_size);
        }
        string sub_string = text.substr(part * (table_x_size * table_y_size), part_len);
        for (int i = 0; i < part_len; ++i) {
            table[i / table_x_size][i % table_x_size] = sub_string[i];
        }
        for (int i = 0; i < table_x_size; ++i) {
            for (int j = 0; j < table_y_size; ++j) {
                decrypted += table[j][i];
            }
        }
    }
    return decrypted;
}

string encrypt_atbash(const string& text) {
    string encrypted;
    for (int i = 0; i < text.size(); ++i) {
        char character = text[i];
        if (character >= 65 && character <= 90) {
            encrypted += (25 - (character - 65)) + 65;
        }
        else {
            if (character >= 97 && character <= 122) {
                encrypted += (25 - (character - 97)) + 97;
            }
            else {
                encrypted += character;
            }
        }
    }
    return encrypted;
}
string decrypt_atbash(const string& text) {
    return encrypt_atbash(text);
}
