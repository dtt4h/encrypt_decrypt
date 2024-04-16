#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>
#include <vector>
using namespace std;
string encrypt_vigenere(const string& text, string key);
string decrypt_vigenere(const string& text, string key);
string encrypt_table(const string& text, int table_x_size, int table_y_size);
string decrypt_table(const string& text, int table_y_size, int table_x_size);
string encrypt_atbash(const string& text);
string decrypt_atbash(const string& text);

#endif
