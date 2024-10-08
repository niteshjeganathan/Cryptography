#include <iostream>
#include <vector>
using namespace std;

int mulInverse(int a, int b, int x1, int x2) {
    if(b == 0) return x1;

    int q = a/b;
    int r = a%b;
    int x = x1 - x2*q;

    return mulInverse(b, r, x2, x);
}

int chineseRemainderTheorem(vector<int> a, vector<int> m) {
    int M = 1;
    for(int i = 0; i < m.size(); i++) {
        M *= m[i];
    }

    int res = 0;

    for(int i = 0; i < a.size(); i++) {
        int Mi = M/m[i];

        int Mi_inverse = mulInverse(Mi, m[i], 1, 0);
        Mi_inverse = (Mi_inverse % m[i] + m[i]) % m[i];

        res += a[i] * Mi * Mi_inverse;
    }

    return res % M;
}

int main() {
    vector<int> a{3, 4, 5};
    vector<int> m{5, 11, 7};

    cout << chineseRemainderTheorem(a, m) << endl;

    return 0;
}