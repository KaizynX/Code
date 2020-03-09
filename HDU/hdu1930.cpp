/*
 * @Author: Kaizyn
 * @Date: 2020-03-08 15:30:18
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-08 15:50:58
 * @FilePath: \Code\HDU\hdu1930.cpp
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 60;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int exgcd(int a, int b, int &x, int &y)
{
    if (!b) { x = 1; y = 0; return a; }
    int d = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

inline int EXCRT(int a[], int m[], const int &n)
{
    // M*x + m[i]*y = a[i]-res (mod m[i])
    // res = res+x*M;
    int M = m[1], res = a[1], x, y, c, d;
    for (int i = 2; i <= n; ++i) {
        d = exgcd(M, m[i], x, y);
        c = (a[i]-res%m[i]+m[i])%m[i];
        if (c%d != 0) return -1;
        x = (c/d)*x%(m[i]/d);
        res += x*M;
        M *= m[i]/d;
        res = (res%M+M)%M;
    }
    return res;
}

int n;
int m[5], a[5];

inline void decode(int x, const int &t)
{
    for (int i = t; i; --i) {
        a[i] = x%100;
        x /= 100;
    }
}

inline void solve()
{
    string res;
    cin >> n;
    for (int i = 1; i <= 4; ++i) cin >> m[i];
    for (int i = 1, code; i <= n; ++i) {
        cin >> code;
        decode(code, 4);
        int tmp = EXCRT(a, m, 4);
        #ifdef DEBUG
        // cout << tmp << " \n"[i==n];
        #endif
        decode(tmp, 3);
        for (int i = 1; i <= 3; ++i) {
            if (a[i] == 27) res += ' ';
            else res += (char)('A'+a[i]-1);
        }
    }
    while (res.size() && res.back() == ' ') res.pop_back();
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}