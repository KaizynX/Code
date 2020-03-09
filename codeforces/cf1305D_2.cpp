#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
list<int> e[N];
int du[N], tag[N];

inline int query(const int &u, const int &v)
{
    int res;
    cout << "? " << u << " " << v << endl;
    cout.flush();
    cin >> res;
    return res;
}

inline void write(const int &res)
{
    cout << "! " << res << endl;
    cout.flush();
    exit(0);
}

inline void solve()
{
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        ++du[u]; ++du[v];
    }
    int num = 0;
    for (int i = 1; i <= n; ++i) {
        tag[i] = du[i] == 1;
        num += tag[i];
    }
    while (num > 1) {
        vector<int> pt;
        for (int i = 1; i <= n; ++i) {
            if (tag[i]) pt.emplace_back(i);
            if (pt.size() >= 2) break;
        }
        int w = query(pt[0], pt[1]);
        if (w == pt[0] || w == pt[1] || tag[w]) write(w);
        --num; tag[pt[0]] = 0;
        --num; tag[pt[1]] = 0;
        ++num; tag[w] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (tag[i]) write(i);
    }
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
