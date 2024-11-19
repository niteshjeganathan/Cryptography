#include <iostream>
using namespace std;

int modExp(int a, int b, int c) {
    int result = 1;
    b = b % c;
    while( b > 0 ) {
        if( b % 2 == 1) {
            result = result * a % c;
        } 
        b = b / 2;
        a = a * a % c;
    }
    return result;
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
    inverse = ((inverse % b) + b) % b;
    return inverse;
}

int main() {
    // Input parameters
    int p = 11, q = 5, H = 54, h = 2, X = 3, k = 3;

    // Step 1: Compute g
    int g = modExp(h, (p - 1) / q, p);

    // Step 2: Compute r
    int r = modExp(g, k, p) % q;

    // Step 3: Compute k^-1 mod q
    int kInv = mulInverse(k, q);

    // Step 4: Compute s
    int s = (kInv * (H + X * r)) % q;

    // Output r and s
    cout << "r = " << r << endl;
    cout << "s = " << s << endl;

    // Step 5: Signature Verification
    int w = mulInverse(s, q);
    int u1 = (H * w) % q;
    int u2 = (r * w) % q;
    int v = (modExp(g, u1, p) * modExp(modExp(g, X, p), u2, p)) % p % q;

    // Output verification values
    cout << "w = " << w << endl;
    cout << "u1 = " << u1 << endl;
    cout << "u2 = " << u2 << endl;
    cout << "v = " << v << endl;

    return 0;
}