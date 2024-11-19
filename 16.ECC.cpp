#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;

    Point(int a, int b) {
        x = a;
        y = b;
    }
};

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

Point pointAddition(int p, int a, Point P, Point Q) {
    int lambda;
    if (P.x != Q.x || P.y != Q.y) {
        int numerator = (Q.y - P.y) % p;
        int denominator = (Q.x - P.x) % p;
        lambda = (numerator * mulInverse(denominator, p)) % p;
    } else {
        int numerator = (3 * P.x * P.x + a) % p;
        int denominator = (2 * P.y) % p;
        lambda = (numerator * mulInverse(denominator, p)) % p;
    }

    int x3 = (lambda * lambda - P.x - Q.x) % p;
    if (x3 < 0) x3 += p;

    int y3 = (lambda * (P.x - x3) - P.y) % p;
    if (y3 < 0) y3 += p;

    return Point(x3, y3);
}

Point scalarMul(int q, int a, Point P, int k) {
    Point result = P;
    for(int i = 1; i < k; i++) {
        result = pointAddition(q, a, result, P);
    }
    return result;

}

void cipher(int a, int b, int q, Point g, Point m, Point pubKey, int k) {
    Point C1 = scalarMul(q, a, g, k);

    cout << C1.x << ", " << C1.y << endl;

    Point kPubKey = scalarMul(q, a, pubKey, k);
    Point C2 = pointAddition(q, a, m, kPubKey);

    cout << C2.x << ", " << C2.y << endl;
}

int main() {
    int a = 2, b = 2, q = 17;
    Point g = Point(5, 1);
    Point m = Point(3, 1);
    Point pubKey = Point(7, 6);
    int k = 2;

    cipher(a, b, q, g, m, pubKey, k);
}