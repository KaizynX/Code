/*
 * @Author: Kaizyn
 * @Date: 2020-03-04 17:53:36
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-04 19:49:25
 * @FilePath: \Code\codeforces\cf1305F.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int n;
set<long long> s;
long long a[N];

inline long long count(const long long &x)
{
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] < x) res += x-a[i];
        else res += min(a[i]%x, x-a[i]%x);
    }
    return res;
}

inline void fac(long long x)
{
    for (long long i = 2; i*i <= x; ++i) {
        if (x%i) continue;
        while (x%i == 0) x /= i;
        s.insert(i);
    }
    if (x > 1) s.insert(x);
}

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    // srand(rnd());
    // random_shuffle(a+1, a+n+1);
    for (int i = n; i >= 3; --i) swap(a[i], a[rnd()%i+1]);
    for (int t = 1; t <= 30 && t <= n; ++t) {
        fac(a[t]);
        fac(a[t]-1);
        fac(a[t]+1);
    }
    long long res = INF;
    for (long long g : s) {
        res = min(res, count(g));
    }
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}