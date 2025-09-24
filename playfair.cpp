#include <bits/stdc++.h>
using namespace std;

vector<vector<char> > generateMatrix(const string &key) {
    string k = key;
    string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // J = I
    for (size_t i = 0; i < alphabet.size(); i++) {
        char c = alphabet[i];
        if (k.find(c) == string::npos) k += c;
    }

    vector<vector<char> > matrix(5, vector<char>(5));
    int idx = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            matrix[i][j] = k[idx++];
    return matrix;
}

pair<int,int> findPos(const vector<vector<char> > &matrix, char c) {
    if (c == 'J') c = 'I';
    for (int i=0; i<5; i++)
        for (int j=0; j<5; j++)
            if (matrix[i][j] == c) return make_pair(i,j);
    return make_pair(-1,-1);
}

string playfair_encrypt(string text, const string &key) {
    vector<vector<char> > matrix = generateMatrix(key);
    string res;
    for (size_t i=0; i<text.size(); i+=2) {
        char a = text[i];
        char b = (i+1 < text.size() ? text[i+1] : 'X');
        if (a==b) b='X';
        pair<int,int> p1 = findPos(matrix,a);
        pair<int,int> p2 = findPos(matrix,b);
        int r1=p1.first, c1=p1.second;
        int r2=p2.first, c2=p2.second;
        if (r1==r2) {
            res += matrix[r1][(c1+1)%5];
            res += matrix[r2][(c2+1)%5];
        } else if (c1==c2) {
            res += matrix[(r1+1)%5][c1];
            res += matrix[(r2+1)%5][c2];
        } else {
            res += matrix[r1][c2];
            res += matrix[r2][c1];
        }
    }
    return res;
}

string playfair_decrypt(string text, const string &key) {
    vector<vector<char> > matrix = generateMatrix(key);
    string res;
    for (size_t i=0; i<text.size(); i+=2) {
        char a = text[i], b = text[i+1];
        pair<int,int> p1 = findPos(matrix,a);
        pair<int,int> p2 = findPos(matrix,b);
        int r1=p1.first, c1=p1.second;
        int r2=p2.first, c2=p2.second;
        if (r1==r2) {
            res += matrix[r1][(c1+4)%5];
            res += matrix[r2][(c2+4)%5];
        } else if (c1==c2) {
            res += matrix[(r1+4)%5][c1];
            res += matrix[(r2+4)%5][c2];
        } else {
            res += matrix[r1][c2];
            res += matrix[r2][c1];
        }
    }
    return res;
}

int main() {
    string text = "HELLOWORLD";
    string key = "KEYWORD";
    cout << "Ban ro: " << text << endl;
    string enc = playfair_encrypt(text, key);
    cout << "Ban ma: " << enc << endl;
    cout << "Giai ma: " << playfair_decrypt(enc, key) << endl;
    return 0;
}

