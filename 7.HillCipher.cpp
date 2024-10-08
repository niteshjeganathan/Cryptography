#include <iostream>
#include <vector>
using namespace std;

string encrypt(string text, vector<vector<int>> key) {
    vector<int> txt;
    for(char chr : text) {
        txt.push_back(chr - 'A');
    }

    vector<int> res(text.length(), 0);
    for(int i = 0; i < key.size(); i++) {
        for(int j = 0; j < key[i].size(); j++) {
            res[i] += key[i][j] * txt[j];
        }
        res[i] = res[i] % 26;
    }

    string cipher = "";
    for(int num : res) {
        cipher += num + 'A';
    }
    
    return cipher;
}

string decrypt(string text, vector<vector<int>> key) {
    vector<int> txt;
    for(char chr : text) {
        txt.push_back(chr - 'A');
    }

    vector<int> res(text.length(), 0);
    for(int i = 0; i < key.size(); i++) {
        for(int j = 0; j < key[i].size(); j++) {
            res[i] += key[i][j] * txt[j];
        }
        res[i] = res[i] % 26;
    }

    string cipher = "";
    for(int num : res) {
        cipher += num + 'A';
    }
    
    return cipher;
}

int main() {
    string text = "BCA";
    vector<vector<int>> key{
        {6, 24, 1}, 
        {13, 16, 10}, 
        {20, 17, 15}
    };

    vector<vector<int>> inverseKey {
        {8, 5, 10}, 
        {21, 8, 21}, 
        {21, 12, 8}
    };

    cout << encrypt(text, key) << endl;
    cout << decrypt(encrypt(text, key), inverseKey) << endl;
}