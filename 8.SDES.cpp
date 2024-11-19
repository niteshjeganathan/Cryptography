#include <iostream>
#include <vector>
using namespace std;

string initialPermute(string text) {
    vector<int> IP {2, 6, 3, 1, 4, 8, 5, 7};
    string ip = "";
    for(int i = 0; i < IP.size(); i++) {
        ip += text[IP[i] - 1];
    }
    return ip;
}

string inversePermute(string text) {
    vector<int> IIP {4, 1, 3, 5, 7, 2, 8, 6};
    string iip = "";
    for(int i = 0; i < IIP.size(); i++) {
        iip += text[IIP[i] - 1];
    }
    return iip;
}

string expandPermute(string text) {
    vector<int> EP {4, 1, 2, 3, 2, 3, 4, 1};
    string ep = "";
    for(int i = 0; i < EP.size(); i++) {
        ep += text[EP[i] - 1];
    }
    return ep;
}

string xorOperation(string s1, string s2) {
    string res = "";
    for(int i = 0; i < s1.length(); i++) {
        res += (s1[i] == s2[i])? '0' : '1';
    }
    return res;
}

string decimalToBinary(int n) {
    string binary = "00";
    if(n & 1) binary[1] = '1';
    if(n & 2) binary[0] = '1';
    return binary;
}

string sbox(string text) {
    vector<vector<int>> s0 = {
        {1, 0, 3, 2},
        {3, 2, 1, 0},
        {0, 2, 1, 3},
        {3, 1, 3, 2}
    };
    vector<vector<int>> s1 = {
        {0, 1, 2, 3},
        {2, 0, 1, 3},
        {3, 0, 1, 0},
        {2, 1, 0, 3}
    };

    int row1 = 2 * (text[0] - '0') + (text[3] - '0');
    int col1 = 2 * (text[1] - '0') + (text[2] - '0');
    int row2 = 2 * (text[4] - '0') + (text[7] - '0');
    int col2 = 2 * (text[5] - '0') + (text[6] - '0');

    int val1 = s0[row1][col1];
    int val2 = s1[row2][col2];

    string output = decimalToBinary(val1) + decimalToBinary(val2);
    return output;
}

string p4permutate(string text) {
    vector<int> P4 {2, 4, 3, 1};
    string p4 = "";
    for(int i = 0; i < P4.size(); i++) {
        p4 += text[P4[i] - 1];
    }
    return p4;
}

string swapFunction(string text) {
    string left = text.substr(0, 4);
    string right = text.substr(4, 4);
    return right + left;
}

string roundFunction(string text, string key) {
    string expanded_right = expandPermute(text);
    string xored = xorOperation(expanded_right, key);
    string substituted = sbox(xored);
    string p4 = p4permutate(substituted);
    return p4;
}

string SDES(string text, string key1, string key2) {
    string ip = initialPermute(text);

    string left = ip.substr(0, 4);
    string right = ip.substr(4, 4);

    string f_k1 = roundFunction(right, key1);
    string left_xor_f_k1 = xorOperation(f_k1, left);

    string combined = left_xor_f_k1 + right;
    string swapped = swapFunction(combined);

    string left2 = swapped.substr(0, 4);
    string right2 = swapped.substr(4, 4);

    string f_k2 = roundFunction(right2, key2);
    string left_xor_f_k2 = xorOperation(f_k2, left2);

    string combined2 = left_xor_f_k2 + right2;
    string cipher = inversePermute(combined2);

    return cipher;
}

int main() {
    string text = "00101000";
    string key1 = "11101001";
    string key2 = "10100111";

    cout << SDES(text, key1, key2) << endl;
}