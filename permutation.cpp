#include <bits/stdc++.h>
using namespace std;

string permutation_encrypt(const string &text, const vector<int> &perm) {
    string res;
    int n = perm.size();
    for (size_t i = 0; i < text.size(); i += n) {
        for (int j = 0; j < n; j++) {
            int idx = i + perm[j];
            if (idx < (int)text.size()) res += text[idx];
            else res += 'X'; // padding
        }
    }
    return res;
}

string permutation_decrypt(const string &cipher, const vector<int> &perm) {
    string res(cipher.size(), ' ');
    int n = perm.size();
    for (size_t i = 0; i < cipher.size(); i += n) {
        for (int j = 0; j < n; j++) {
            int idx = i + perm[j];
            if (idx < (int)cipher.size())
                res[idx] = cipher[i + j];
        }
    }
    return res;
}

int main() {
    string text = "HELLOWORLD";
    int arr[] = {2,0,3,1};
    vector<int> perm(arr, arr+4);

    cout << "Ban ro: " << text << endl;
    string enc = permutation_encrypt(text, perm);
    cout << "Ban ma: " << enc << endl;
    cout << "Giai ma: " << permutation_decrypt(enc, perm) << endl;
    return 0;
}

