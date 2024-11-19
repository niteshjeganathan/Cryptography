#include <iostream>
using namespace std;

string cipher(string PT, string key) {
    string CT = "";
    for(int i = 0; i < PT.length(); i++) {
        int shift = key[i % key.length()] - 'a';
        if(PT[i] == ' ') {
            CT += " ";
        }else if(isdigit(PT[i]))  {
            CT += (PT[i] - '0' + shift) % 10 + '0';
        } else if(islower(PT[i])) {
            CT += (PT[i] - 'a' + shift) % 26 + 'a';
        } else {
            CT += (PT[i] - 'A' + shift) % 26 + 'A';
        }
    }
    return CT;
}

string decipher(string CT, string key) {
    string PT = "";
    for(int i = 0; i < CT.length(); i++) {
        int shift = key[i % key.length()] - 'a';
        if(CT[i] == ' ') {
            PT += " ";
        }else if(isdigit(CT[i]))  {
            PT += (CT[i] - '0' - shift + 10) % 10 + '0';
        } else if(islower(CT[i])) {
            PT += (CT[i] - 'a' - shift + 26) % 26 + 'a';
        } else {
            PT += (CT[i] - 'A' - shift + 26) % 26 + 'A';
        }
    }
    return PT;
}

int main() {
    cout << cipher("rendezvous", "ace") << endl;
    cout << decipher(cipher("rendezvous", "ace"), "ace") << endl;
}