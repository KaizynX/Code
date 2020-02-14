#include <bits/stdc++.h>

using namespace std;

const int N = 5e2+7;
typedef pair<int, int> pii;

int n, m, k, q;
int col[N];
vector<pii> e;

inline bool check()
{
    set<int> s(col+1, col+n+1);
    if ((int)s.size() != k) return false;
    for (pii p : e)
        if (col[p.first] == col[p.second]) return false;
    return true;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        e.emplace_back(u, v);
    }
    cin >> q;
    while (q--) {
        for (int i = 1; i <= n; ++i) cin >> col[i];
        cout << (check() ? "Yes" : "No") << endl;
    }
    return 0;
}
