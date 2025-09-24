#include <bits/stdc++.h>
using namespace std;

string caesar_encrypt(const string &text, int shift) {
    string res;
    for (size_t i = 0; i < text.size(); i++) {
        char c = text[i];
        if (isalpha((unsigned char)c)) {
            char base = isupper(c) ? 'A' : 'a';
            res += (c - base + shift) % 26 + base;
        } else res += c;
    }
    return res;
}

string caesar_decrypt(const string &text, int shift) {
    return caesar_encrypt(text, 26 - shift);
}

int main() {
    string text = "HELLOWORLD";
    int shift = 3;
    cout << "Ban ro: " << text << endl;
    string enc = caesar_encrypt(text, shift);
    cout << "Ban ma: " << enc << endl;
    cout << "Giai ma: " << caesar_decrypt(enc, shift) << endl;
    return 0;
}

