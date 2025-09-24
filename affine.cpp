#include <bits/stdc++.h>
using namespace std;

int modInverse(int a, int m) {
    a %= m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1) return x;
    return -1;
}

string affine_encrypt(const string &text, int a, int b) {
    string res;
    for (size_t i = 0; i < text.size(); i++) {
        char c = text[i];
        if (isalpha((unsigned char)c)) {
            char base = isupper(c) ? 'A' : 'a';
            res += (char)((a * (c - base) + b) % 26 + base);
        } else res += c;
    }
    return res;
}

string affine_decrypt(const string &text, int a, int b) {
    string res;
    int inv = modInverse(a, 26);
    for (size_t i = 0; i < text.size(); i++) {
        char c = text[i];
        if (isalpha((unsigned char)c)) {
            char base = isupper(c) ? 'A' : 'a';
            res += (char)(((inv * ((c - base) - b + 26)) % 26) + base);
        } else res += c;
    }
    return res;
}

int main() {
    string text = "HELLOWORLD";
    int a = 5, b = 8;
    cout << "Ban ro: " << text << endl;
    string enc = affine_encrypt(text, a, b);
    cout << "Ban ma: " << enc << endl;
    cout << "Giai ma: " << affine_decrypt(enc, a, b) << endl;
    return 0;
}

