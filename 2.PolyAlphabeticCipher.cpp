#include <iostream>
using namespace std;

string generateKey(string key, int n) {
    string res = "";
    for(int i = 0; i < n; i++) {
        res += key[i % key.length()];
    }
    return res;
}

string encrypt(string text, string key) {
    string genKey = generateKey(key, text.length());

    string res = "";

    for(int i = 0; i < text.length(); i++) {
        int x = (genKey[i] - 'a');
        if(text[i] == ' ') {
            res += ' ';
        } else if(isdigit(text[i])) {
            res += text[i] + x;
        } else if(isupper(text[i])) {
            res += ((text[i] - 'A') + x) % 26 + 'A';
        } else if(islower(text[i])) {
            res += ((text[i] - 'a') + x) % 26 + 'a';
        }
    }
    return res;
}

string decrypt(string text, string key) {
    string genKey = generateKey(key, text.length());

    string res = "";

    for(int i = 0; i < text.length(); i++) {
        int x = (genKey[i] - 'a');
        if(text[i] == ' ') {
            res += ' ';
        } else if(isdigit(text[i])) {
            res += text[i] - x;
        } else if(isupper(text[i])) {
            res += ((text[i] - 'A') - x + 26) % 26 + 'A';
        } else if(islower(text[i])) {
            res += ((text[i] - 'a') - x + 26) % 26 + 'a';
        }
    }
    return res;
}

int main() {
    string text = "rendezvous";
    string key = "ace";

    cout << encrypt(text, key) << endl;
    cout << decrypt(encrypt(text, key), key) << endl;

    return 0;
}