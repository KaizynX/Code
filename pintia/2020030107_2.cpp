#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e5+7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

int n, m;
int del[N];

inline int calc(int x, int y)
{
    int res = 0;
    while (x != y) {
        if (x < y) swap(x, y);
        if (del[x]) return INF;
        ++res;
        x >>= 1;
    }
    return res;
}

inline void solve()
{
    cin >> n >> m;
    char op;
    int x;
    while (m--) {
        cin >> op >> x;
        if (op == '-') {
            del[x] = 1;
        } else {
            int res = 0;
            for (int i = 1; i <= n; ++i) {
                for (int j = i+1; j <= n; ++j) {
                    if (calc(i, j) > x) continue;
                    ++res;
                }
            }
            cout << res << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}