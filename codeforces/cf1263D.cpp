#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n;
string s;
int vis[30];

struct DSU
{
    int fa[30];
    void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i; }
    int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
    int& operator [] (int i) { return fa[get(i)]; }
    bool merge(int x, int y) {
        int fx = get(x), fy = get(y);
        if (fx == fy) return false;
        fa[fx] = fy; return true;
    }
} dsu;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    dsu.init(26);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s;
        for (char c : s) {
            vis[c-'a'+1] = 1;
            dsu.merge(c-'a'+1, s[0]-'a'+1);
        }
    }
    int res = 0;
    for (int i = 1; i <= 26; ++i) {
        if (!vis[i]) continue;
        if (dsu[i] == i) ++res;
    }
    cout << res << endl;
    return 0;
}

