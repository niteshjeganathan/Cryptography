#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string cipher(string PT, string key) {
    int cols = key.length();
    int rows = (PT.length() + cols - 1) / cols;

    while(PT.length() < rows * cols) {
        PT += " ";
    }

    string CT = "";

    vector<vector<char> > grid(cols, vector<char>(rows));

    for(int i = 0; i < PT.length(); i++) {
        grid[i/cols][i%cols] = PT[i];
    }
    
    string sortedKey = key;
    sort(sortedKey.begin(), sortedKey.end());

    for(int i = 0; i < cols; i++) {
        int col = key.find(sortedKey[i]);

        for(int row = 0; row < rows; row++) {
            CT += grid[row][col];
        }
    }

    return CT;
}

string decipher(string CT, string key) {
    int cols = key.length();
    int rows = CT.length() / cols;

    vector<vector<char> > grid(cols, vector<char>(rows));

    string sortedKey = key;
    sort(sortedKey.begin(), sortedKey.end());

    int currIndex = 0;
    for(int i = 0; i < CT.length(); i++) {
        int col = key.find(sortedKey[i]);
        for(int row = 0; row < rows; row++) {
            grid[row][col] = CT[currIndex++];
        }
    }

    string PT = "";

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            PT += grid[i][j];
        }
    }

    return  PT;
}



int main() {
    cout << cipher("Apple is fresh", "heal") << endl;

    cout << decipher(cipher("Apple is fresh", "heal"), "heal") << endl;
}