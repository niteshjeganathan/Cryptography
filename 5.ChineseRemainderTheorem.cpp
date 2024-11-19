#include <iostream>
#include <vector>
using namespace std;

int extendedEuclidean(int a, int b, int x1, int x2) {
    if(b == 0) return x1;

    int q = a/b;
    int r = a%b;

    int x = x1 - q*x2;

    return extendedEuclidean(b,r,x2,x);
}

int mulInverse(int a, int b) {
    if(a > b) {
        return extendedEuclidean(a, b, 1, 0);
    } else {
        return extendedEuclidean(b, a, 1, 0);
    }
}

int chineseRemainderTheorem(vector<int> a, vector<int> m) {
    int n = a.size();

    int M = 1;

    int sum = 0;

    for(int i = 0; i < n; i++) {
        M *= m[i];
    }

    for(int i = 0; i < n; i++) {
        int Mi = M/m[i];

        int Mi_inverse = mulInverse(Mi, m[i]);
        Mi_inverse = ((Mi_inverse % m[i]) + m[i]) % m[i];

        sum += a[i] * Mi * Mi_inverse;
    }
    
    return sum % M;
}

int main() {
    vector<int> a{3, 4, 5};
    vector<int> m{5, 11, 7};

    cout << chineseRemainderTheorem(a, m) << endl;

    return 0;
}