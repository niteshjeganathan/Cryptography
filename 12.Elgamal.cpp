#include <iostream>
#include <cmath>
using namespace std;

int powerMod(int a, int b, int c) {
    int power = pow(a, b);
    return power % c;
}

int main() {
    int q, r, m, a, b;
    q = 11;
    r = 2;
    m = 8;
    a = 5;
    b = 6;

    int A = powerMod(r, a, q);
    int B = powerMod(r, b, q);

    cout << "Public Key of A: " << A << endl;
    cout << "Public Key of B: " << B << endl;

    int C1 = powerMod(r, b, q);
    int C2 = (m * powerMod(A, b, q)) % q;

    cout << "Cipher Text:  " << C1 << ", " << C2 << endl;

    int PT = C2 * powerMod(C1, q - a - 1, q) % q;

    cout <<  "Plain Text: " << PT << endl;
}