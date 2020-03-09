#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 5e3+7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

int n, d;
int fa[N], dep[N];
vector<int> pt[N];

inline int calc_min()
{
    int res = 0;
    for (int i = 0, base = 1, num = n; num; ++i, base <<= 1) {
        int tmp = min(num, base);
        num -= tmp;
        res += i*tmp;
    }
    return res;
}

inline void solve()
{
    cin >> n >> d;
    int now = 0, cur = n;
    for (int i = 1; i <= n; ++i) {
        dep[i] = i;
        vector<int>(1, i).swap(pt[i]);
        now += i-1;
    }
    if (d < calc_min() || now < d) { cout << "NO" << endl; return; }
    while (now > d) {
        if (pt[dep[cur]-2].size()*2 < pt[dep[cur]-1].size()+1) --cur;
        pt[dep[cur]].pop_back();
        pt[--dep[cur]].emplace_back(cur);
        --now;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < (int)pt[i].size(); ++j) {
            fa[pt[i][j]] = pt[i-1][j>>1];
        }
    }
    cout << "YES" << endl;
    for (int i = 2; i <= n; ++i) {
        cout << fa[i] << " \n"[i==n];
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}