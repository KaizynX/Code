#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n;
int du[N];
set<int> e[N];
typedef pair<int, int> pii;
set<pii> p[N];

inline void add(int x, pii y) // add y to x
{
    p[x].insert(y);
    if (p[x].size() > 3)
        p.erase(p[x].begin());
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].insert(v);
        e[v].insert(u);
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (e[i].size() == 1) {
            q.push(i);
            e[*e[i].begin()].erase(i);
            add(*e[i].begin(), {0, i});
        }
    }
    return 0;
}
