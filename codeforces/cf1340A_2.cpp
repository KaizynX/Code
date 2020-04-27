/*
 * @Author: Kaizyn
 * @Date: 2020-04-23 23:08:58
 * @LastEditTime: 2020-04-23 23:15:38
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n;
int a[N], p[N];

inline bool solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
    }
    int s = p[1], t = n;
    for (int i = 2; i <= n; s = min(s, p[i++])) {
        if (p[i] == p[i-1]+1) continue;
        if (p[i-1] == t) {
            t = s-1;
        } else {
            return false;
        }
    }
    return true;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        cout << (solve() ? "Yes" : "No") << endl;
    }
    return 0;
}