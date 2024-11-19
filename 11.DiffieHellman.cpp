#include <iostream>
#include <cmath>
using namespace std;

long long powerMod(int a, int b, int c) {
    int power = pow(a, b);
    return power % c;
}

int main() {
    int q, r, a, b;
    q = 7;
    r = 3;
    a = 4;
    b = 5;

    int A = powerMod(r, a, q);
    int B = powerMod(r, b, q);

    cout << "Public Key of A: " << A << endl;
    cout << "Public Key of B: " << B << endl;

    int secretA = powerMod(B, a, q);
    int secretB = powerMod(A, b, q);

    cout << "Private Key of A: " << secretA << endl;
    cout << "Private Key of B: " << secretB << endl;
}