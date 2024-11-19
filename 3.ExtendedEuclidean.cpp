#include <iostream>
using namespace std;

int extendedEuclidean(int a, int b, int x1, int x2) {
    if(b == 0)
        return x1;

    int q = a/b;
    int r = a%b;

    int x = x1 - q*x2;

    return extendedEuclidean(b, r, x2, x);
}


int multiplicativeInverse(int a, int b) {
    int inverse;
    if(a > b) {
        inverse =  extendedEuclidean(a, b, 1, 0);
        inverse = ((inverse % b) + b) % b;
    } else {
        inverse =  extendedEuclidean(b, a, 1, 0);
        inverse = ((inverse % a) + a) % a;
    }
    return inverse;
}

int main() {
    cout << multiplicativeInverse(155, 677) << endl;
}
