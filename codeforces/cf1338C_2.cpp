/*
 * @Author: Kaizyn
 * @Date: 2020-04-12 23:05:13
 * @LastEditTime: 2020-04-12 23:47:07
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

const int small_ans[] = {0,1,2,3,4,8,12,5,10,15,6,11,13,7,9,14};
const long long base[5] = {0,2,3,1};

long long n;

inline void solve()
{
    cin >> n;
    if (n < 16) return void(cout << small_ans[n] << endl);
    long long k = 16;
    while (k*4 <= n) k *= 4;
    n -= k;
    long long m = n/3;
    long long x[5];
    x[0] = k+m;
    for (long long b = 0; b <= 52; b += 2) {
        long long cur = (m&(3ll<<b))>>b;
        m ^= (cur^base[cur])<<b;
        if ((3ll<<b) > m) break;
    }
    x[1] = k*2+m;
    x[2] = x[0]^x[1];
    cout << x[n%3] << endl;
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