/*
 * @Author: Kaizyn
 * @Date: 2020-04-08 22:31:56
 * @LastEditTime: 2020-04-08 22:47:43
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
int a[N], b[N];

inline bool solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    int neg = 0, pos = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == b[i]) {
            ;
        } else if (a[i] > b[i]) {
            if (!neg) return false;
        } else if (a[i] < b[i]) {
            if (!pos) return false;
        }
        if (a[i] > 0) pos = 1;
        else if (a[i] < 0) neg = 1; 
    }
    return true;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}