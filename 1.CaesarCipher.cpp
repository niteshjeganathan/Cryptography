#include <iostream>
#include <string>
using namespace std;

string cipher(string PT, int shift) {
    string CT = "";
    for(int i = 0; i < PT.length(); i++) {
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

string decipher(string CT, int shift) {
    string PT = "";
    for(int i = 0; i < CT.length(); i++) {
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
    cout << cipher("I stand 5th in our class", 3) << endl;
    cout << decipher(cipher("I stand 5th in our class", 3), 3) << endl;
}
