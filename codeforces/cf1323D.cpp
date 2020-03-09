/*
 * @Author: Kaizyn
 * @Date: 2020-03-07 18:32:13
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-07 19:31:57
 * @FilePath: \Code\codeforces\cf1323D.cpp
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 4e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
int a[N];

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int xor_all = 0, res = 0;
    for (int i = 1; i <= n; ++i) xor_all ^= a[i];
    sort(a+1, a+n+1);
    #ifdef DEBUG
    cout << "shit" << endl;
    #endif
    for (int i = n; i > 1; --i) {
        xor_all ^= a[i];
        int base = 1;
        while (base <= a[i]) base <<= 1; 
        int p = lower_bound(a+1, a+i, base-a[i])-a;
        #ifdef DEBUG
        cout << i << " " << p << endl;
        #endif
        if ((i-p)&1) res ^= base;
        if (i&1) {
            res ^= xor_all;
        } else {
            res ^= xor_all^a[1];
            res ^= (a[1]+a[i]);
            if (a[1]+a[i] >= base) res ^= base;
        }
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