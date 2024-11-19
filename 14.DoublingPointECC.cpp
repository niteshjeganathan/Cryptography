#include <iostream>
using namespace std;

int extendedEuclidean(int a, int b, int X1, int X2) {
    if(b == 0) return X1;

    int q = a/b;
    int r = a%b;
    int X = X1 - q * X2;

    return extendedEuclidean(b, r, X2, X);
}

int mulInverse(int a, int b) {
    int inverse = extendedEuclidean(a, b, 1, 0);
    inverse = ((inverse % b) + b) % b;
    return inverse;
}

void doublingPoint(int a, int x, int y, int p) {
    int num = (3 * x * x + a) % p;
    if (num < 0) num += p;
    int den = (2 * y) % p;
    if (den < 0) den += p;

    int lambda = (num * mulInverse(den, p)) % p;

    int x3 = (lambda * lambda - 2 * x) % p;
    if(x3 < 0) x3 += p;
    int y3 = (lambda * (x - x3) - y) % p;
    if(y3 < 0) y3 += p;

    cout << x3 << ", " << y3 << endl;
}

int main() {
    int p, a, b, x, y;
    p = 17, a = 2, b = 2, x = 5, y = 1;

    doublingPoint(a, x, y, p);
}