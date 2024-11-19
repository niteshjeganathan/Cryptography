#include <iostream>
#include <vector>
using namespace std;

string cipher(string PT, vector<vector<int>> key) {
    vector<int> text;

    for(int i = 0; i <  PT.length(); i++) {
        text.push_back(PT[i] - 'A');
    }

    vector<int> res;

    for(int i = 0; i < PT.length(); i++) {
        int sum = 0;
        for(int j = 0; j < PT.length(); j++) {  
            sum += text[j] * key[i][j];
        }
        sum = sum % 26;
        res.push_back(sum);
    }

    string cipher = "";
    for(int i = 0; i < res.size(); i++) {
        cipher += res[i] + 'A';
    }

    return cipher;
}

string decipher(string CT, vector<vector<int>> key) {
    vector<int> cipher;

    for(int i = 0; i <  CT.length(); i++) {
        cipher.push_back(CT[i] - 'A');
    }

    vector<int> text;

    for(int i = 0; i < CT.length(); i++) {
        int sum = 0;
        for(int j = 0; j < CT.length(); j++) {  
            sum += cipher[j] * key[i][j];
        }
        sum = sum % 26;
        text.push_back(sum);
    }

    string pt = "";
    for(int i = 0; i < text.size(); i++) {
        pt += text[i] + 'A';
    }

    return pt;
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

    cout << cipher(text, key) << endl;
    cout << decipher(cipher(text, key), inverseKey) << endl;
}