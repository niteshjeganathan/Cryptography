#include <iostream> 
#include <vector>
using namespace std;

vector<unsigned char> sbox(256, 0);

void initialiseSbox() {
    sbox[0x3A] = 0x80;
    sbox[0xF7] = 0x68;
    sbox[0xFA] = 0x2D;
    sbox[0xA0] = 0xE0;
}

vector<unsigned char> generateRotword(vector<unsigned char> c) {
    c = {c[1], c[2], c[3], c[0]};
    return c;
}

vector<unsigned char> generateSubword(vector<unsigned char> c) {
    for(int i = 0; i < c.size(); i++) {
        c[i] = sbox[c[i]];
    }
    return c;
}

vector<vector<unsigned char>> generateKey(vector<vector<unsigned char>> key, unsigned char round_constant) {
    vector<vector<unsigned char>> newKey(key.begin(), key.end()); 
    vector<unsigned char> c4 {newKey[0][3], newKey[1][3], newKey[2][3], newKey[3][3]};

    vector<unsigned char> rotword = generateRotword(c4);

    initialiseSbox();
    vector<unsigned char> subword = generateSubword(rotword);

    subword[0] ^= round_constant;

    for(int i = 0; i < 4; i++) {
        newKey[i][0] ^= subword[i];
    }

    for(int i = 1; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            newKey[j][i] ^= newKey[j][i-1];
        }
    }

    return newKey;
}

int main() {
    vector<vector<unsigned char>> key2 = {
    {0x56, 0xC7, 0x76, 0xA0},
    {0x08, 0x1A, 0x43, 0x3A},
    {0x20, 0xB1, 0x55, 0xF7},
    {0x07, 0x8F, 0x69, 0xFA}
    };

    unsigned char round_constant = 0x04;

    vector<vector<unsigned char>> key3 = generateKey(key2, round_constant);

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            printf("0x%02X ", key3[i][j]);
        }
        cout << endl;
    }

    return 0;
}