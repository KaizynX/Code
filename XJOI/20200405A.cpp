/*
 * @Author: Kaizyn
 * @Date: 2020-04-05 13:30:09
 * @LastEditTime: 2020-04-05 15:19:35
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

inline void solve()
{
    int n;
    cin >> n;
    cout << n*(n+1)-1 << endl;
    int x = 1, y = 1;
    cout << x << " " << y << endl;
    if (n&1) {
        for (int i = 1; i <= (n+1)/2; ++i) {
            ++y;
            cout << x << " " << y << endl;
            for (int j = 1; j < n; ++j) {
                ++x;
                y += (j&1 ? -1 : 1);
                cout << x << " " << y << endl;
            }
            --y;
            cout << x << " " << y << endl;
            for (int j = 1; j < n-1; ++j) {
                --x;
                y += (j&1 ? 1 : -1);
                cout << x << " " << y << endl;
            }
            if (i == (n+1)/2) break;
            --x; ++y;
            cout << x << " " << y << endl;
        }
    } else {
        for (int i = 1; i <= n/2; ++i) {
            for (int j = 1; j < n; ++j) {
                ++x;
                y += (j&1 ? 1 : -1);
                cout << x << " " << y << endl;
            }
            --y;
            cout << x << " " << y << endl;
            for (int j = 1; j < n; ++j) {
                --x;
                y += (j&1 ? 1 : -1);
                cout << x << " " << y << endl;
            }
            ++y;
            cout << x << " " << y << endl;
        }
        for (int i = 1; i < n; ++i) {
            ++x;
            cout << x << " " << y << endl;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}