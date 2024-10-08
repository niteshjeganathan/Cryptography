#include <iostream>
using namespace std;

string encrypt(string text, string key) {
    int cols = key.length();
    int rows = (text.length() + cols - 1) / cols;

    while(text.length() < rows * cols) {
        text += ' ';
    }

    vector<vector<char>> grid(rows, vector<char>(cols));

    for(int i = 0; i < text.length(); i++) {
        grid[i/cols][i%cols] = text[i];
    }

    string sortedKey = key;
    sort(sortedKey.begin(), sortedKey.end());

    string res = "";
    for(int i = 0; i < sortedKey.length(); i++) {
        int col = key.find(sortedKey[i]);
        for(int row = 0; row < rows; row++) {
            res += grid[row][col];
        }
    }

    return res;
}

string decrypt(string text, string key) {
    int cols = key.length();
    int rows = (text.length() + cols - 1) / cols;

    vector<string> grid(rows, string(cols, ' '));

    string sortedKey = key;
    sort(sortedKey.begin(), sortedKey.end());

    int currentIndex = 0;

    for(int i = 0; i < sortedKey.length(); i++) {
        int col = key.find(sortedKey[i]);
        for(int row = 0; row < rows; row++) {
            grid[row][col] = text[currentIndex++];
        }
    }

    string res = "";
    for(int i = 0; i < rows; i++) {
        res += grid[i];
    }

    res = res.substr(0, res.find_last_not_of(' ') + 1);

    return res;
}

int main() {
    cout << encrypt("Apple is fresh", "heal") << endl;
    cout << decrypt(encrypt("Apple is fresh", "heal"), "heal") << endl;
}