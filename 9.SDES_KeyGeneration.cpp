#include <iostream>
#include <vector>
using namespace std;

string p10Permutate(string text) {
    vector<int> P10 {3, 5, 2, 7, 4, 10, 1, 9, 8, 6};
    string p10 = "";
    for(int i = 0; i < P10.size(); i++) {
        p10 += text[P10[i] - 1];
    }
    return p10;
}

string p8Permutate(string text) {
    vector<int> P8 {6, 3, 7, 4, 8, 5, 10, 9};
    string p8 = "";
    for(int i = 0; i < P8.size(); i++) {
        p8 += text[P8[i] - 1];
    }
    return p8;
}

string LCS(string text, int n) {
    for (int i = 0; i < n; i++) {
        char temp = text[0];
        for (int j = 0; j < text.length() - 1; j++) {
            text[j] = text[j + 1];
        }
        text[text.length() - 1] = temp;
    }
    return text;
}

void keyGenerate(string key) {
    string p10 = p10Permutate(key);

    string left = p10.substr(0, 5);
    string right = p10.substr(5, 10);

    string left_lcs1 = LCS(left, 1);
    string right_lcs1 = LCS(right, 1);

    string combined1 = left_lcs1 + right_lcs1;
    string key1 = p8Permutate(combined1);
    cout << key1 << endl;

    string left_lcs2 = LCS(left_lcs1, 2);
    string right_lcs2 = LCS(right_lcs1, 2);

    string combined2 = left_lcs2 + right_lcs2;
    string key2 = p8Permutate(combined2);
    cout << key2 << endl;
}

int main() {
    string key = "1100011110";

    keyGenerate(key);
}