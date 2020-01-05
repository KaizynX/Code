#include <bits/stdc++.h>

using namespace std;

const int N = 5e2+7;

int n, k;
set<int> q;

struct DSU
{
    int fa[N];
    void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i; }
    int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
    int& operator [] (int i) { return fa[get(i)]; }
    bool merge(int x, int y) {
        int fx = get(x), fy = get(y);
        if (fx == fy) return false;
        fa[fx] = fy; return true;
    }
} dsu;

inline void make_query()
{
    cout << "?";
    for (int i : q) cout << " " << i;
    cout << endl;
    cout.flush();
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    dsu.init(n+1);
    int p, a, pp, aa;
    for (int i = 1; i <= k; ++i)
        q.insert(i);
    make_query();
    cin >> p >> a;

    q.insert(k+1);
    for (int i = 1; i <= k; ++i) {
        if (i == p) continue;
        q.erase(i);
        make_query();
        cin >> pp >> aa;
        q.insert(i);
        if (pp == p) dsu.merge(i, k+1);
        else if (aa < a) {
            dsu.merge(pp, 0);
            dsu.merge(k+1, 0);
            dsu.merge(i, n+1);
        } else if (aa > a) {
            dsu.merge(pp, n+1);
            dsu.merge(k+1, n+1);
            dsu.merge(i, 0);
        }
    }
    if (dsu[k+1] != 0 && dsu[k+1] != n+1) {
        q.erase(p);
        make_query();
        cin >> pp >> aa;
        cout << "! " << (aa < a ? k : 1) << endl;
        cout.flush();
    } else {
        int m = 1;
        for (int i = 1; i <= k; ++i) {
            if (i == p) continue;
            if (dsu[i] == 0) ++m;
        }
        cout << "! " << m << endl;
        cout.flush();
    }
    return 0;
}
