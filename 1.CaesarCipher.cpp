#include <iostream>
#include <string>
using namespace std;

string encrypt(string text, int x) {
    string res = "";
    for(int i = 0; i < text.length(); i++) {
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

string decrypt(string text, int x) {
    string res = "";
    for(int i = 0; i < text.length(); i++) {
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
    string text = "I stand 5th in our class";
    int num = 3;

    cout << encrypt(text, num) << endl;
    cout << decrypt(encrypt(text, num), num) << endl;
    
    return 0;
} 
