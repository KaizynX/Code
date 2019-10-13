#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 2e5+7;

int n, res;
bitset<N> x, tmp, b1, b2;

inline void ope(bitset<N> &a)
{
    if (a[0]) {
        a = a+b1;
        a >>= 1;
    } else {
        a >>= 1;
        a += b2;
    }
}

int main()
{
    cin >> n;
    cin >> x;
    tmp = x;
    b1[0] = 1;
    b2[n-1] = 1;
    ope(tmp);
    res = 1;
    while (tmp != x) {
        ope(tmp);
        ++res;
    }
    cout << res << endl;
    return 0;
}
