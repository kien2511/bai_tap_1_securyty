#include <bits/stdc++.h>
using namespace std;

string vigenere_encrypt(const string &text, const string &key) {
    string res;
    int n = key.size();
    for (size_t i = 0; i < text.size(); i++) {
        char c = text[i];
        if (isalpha((unsigned char)c)) {
            char base = isupper(c) ? 'A' : 'a';
            char k = toupper(key[i % n]) - 'A';
            res += (c - base + k) % 26 + base;
        } else res += c;
    }
    return res;
}

string vigenere_decrypt(const string &text, const string &key) {
    string res;
    int n = key.size();
    for (size_t i = 0; i < text.size(); i++) {
        char c = text[i];
        if (isalpha((unsigned char)c)) {
            char base = isupper(c) ? 'A' : 'a';
            char k = toupper(key[i % n]) - 'A';
            res += (c - base - k + 26) % 26 + base;
        } else res += c;
    }
    return res;
}

int main() {
    string text = "HELLOWORLD";
    string key = "KEY";
    cout << "Ban ro: " << text << endl;
    string enc = vigenere_encrypt(text, key);
    cout << "Ban ma: " << enc << endl;
    cout << "Giai ma: " << vigenere_decrypt(enc, key) << endl;
    return 0;
}

