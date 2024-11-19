#include <iostream>
#include <cmath>
using namespace std;

int modExp(int a, int b, int c) {
    int result = 1;
    b = b % c;

    while(b > 0) {
        if(b % 2 == 1) {
            result = result * a % c;
        } 
        b /= 2;
        a = a * a % c;
    }
    return result;
}

int extendedEuclidean(int a, int b, int X1, int X2) {
    if (b == 0) return X1;

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

int main() {
    int p = 7;
    int q = 13;
    int e = 5;
    int w = 35;

    int n = p*q;
    int phi = (p - 1) * (q - 1);
    int d = mulInverse(e, phi);

    int s = modExp(w, d, n);

    cout << s << endl;

    int w_calculated = modExp(s, e, n);
    
    cout << w_calculated << endl;
    
}
