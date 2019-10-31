#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, p;
long long pow2[32];

inline pair<long long, long long> count(int a)
{
    pair<long long, long long> res = { 0, 0 };
    for (int i = 0; i <= 30; ++i) {
        if ((a>>i)&1) {
            ++res.first;
            res.second += pow2[i];
        }
    }
    return res;
}

int main()
{
    pow2[0] = 1;
    for (int i = 1; i <= 30; ++i) pow2[i] = pow2[i-1]<<1;
    cin >> n >> p;
    // n-p*res > 0
    for (int x = 1; n-x*p > 0; ++x) {
        pair<long long, long long> tmp = count(n-x*p);
        if (x >= tmp.first && x <= tmp.second) {
            cout << x << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
