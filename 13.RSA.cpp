#include <iostream>
#include <cmath>
using namespace std;

int powerMod(int a, int b, int c) {
    int power = pow(a, b);
    return power % c;
}

int extendedEuclidean(int a, int b, int X1, int X2) {
    if(b == 0) return X1;

    int q = a/b;
    int r = a%b;
    int X = X1 - X2 * q;

    return extendedEuclidean(b, r, X2, X);
}

int mulInverse(int a, int b) {
    int inverse = extendedEuclidean(a, b, 1, 0);
    return ((inverse % b) + b) % b;
}

int main() {
    int p, q, e, m;

    p = 3;
    q = 5;
    e = 5;
    m = 4;

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int d = mulInverse(e, phi);

    int cipher = powerMod(m, e, n);

    cout << "Cipher Text: " << cipher << endl;

    int plainText = powerMod(cipher, d, n);

    cout << "Plain Text: " << plainText << endl;
}