#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, k;
int a[N];
long long res;
map<int, int> mp;

inline long long qpow(int a, int p)
{
    long long res = 1;
    while (p) {
        if (p&1) res *= a;
        a *= a;
        p >>= 1;
    }
    return res;
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++mp[a[i]];
    }
    sort(a+1, a+n+1);
    long long powk, mx = 1ll*a[n]*a[n-1];
    for (int i = 1; (powk = qpow(i, k)) <= mx; ++i) {
        for (int j = 1; 1ll*j*j <= powk; ++j) {
            if (powk%j) continue;
            if (powk/j == j) {
                if (mp[j] >= 2) ++res;
            } else {
                if (mp.count(j) && mp.count(powk/j)) ++res;
            }
        }
    }
    cout << res << endl;
    return 0;
}
