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
    int q = 19;
    int r = 10;
    int XA = 16;
    int k = 5;
    int h = 14;

    int YA = modExp(r, XA, q);

    int s1 = modExp(r, k, q);
    int k_inv = mulInverse(k, q - 1);

    int s2 = k_inv * (h - XA * s1) % (q - 1);
    if(s2 < 0) s2 += q - 1;

    cout << s1 << " " << s2 << endl;

    int v1 = modExp(r, h, q);

    int v2 = modExp(YA, s1, q) * modExp(s1, s2, q) % q;

    cout << v1 << ", " << v2 << endl;
}