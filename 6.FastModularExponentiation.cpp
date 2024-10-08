#include <iostream>
using namespace std;

int fastModularExp(int a, int b, int c) {
    a = a % c;
    int res = 1;

    while(b > 0) {
        if(b % 2 == 1) {
            res = (res * a) % c;
        }
        a = (a * a) % c;
        b = b/2;
    }
    return res;
}

int main() {
    cout << fastModularExp(11, 137, 97) << endl;
    return 0;
}