#include <iostream>
using namespace std;


int extendedEuclidean(int a, int b, int x1, int x2) {
    if(b == 0) {
        return x1;
    }

    int q = a/b;
    int r = a%b;
    int x = x1 - q*x2;
    
    return extendedEuclidean(b, r, x2, x);
}

int main() {
    int a = 677;
    int b = 155;

    if(a > b) {
        cout << extendedEuclidean(a,b, 1, 0) << endl;
    } else {
        cout << extendedEuclidean(b, a, 1, 0) << endl;
    }

    return 0;
}