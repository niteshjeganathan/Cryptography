#include <iostream>
#include <cmath>
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

void addingPoints(int x1, int y1, int x2, int y2, int p) {
    int num = (y2 - y1) % p;
    int den = (x2 - x1) % p;

    int lambda = (num * mulInverse(den, p)) % p;

    int x3 = (lambda * lambda - x1 - x2) % p;
    if(x3 < 0) x3 += p;
    int y3 = (lambda * (x1 - x3) - y1) % p;
    if(y3 < 0) y3 += p;

    cout << x3 << ", " << y3 << endl;
}

int main() {
    int p, x1, y1, x2, y2, a, b;
    p = 97, a = 2, b = 3, x1 = 17, y1 = 10, x2 = 95, y2 = 31;

    addingPoints(x1, y1, x2, y2, p);
}