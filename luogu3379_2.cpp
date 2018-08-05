#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int Maxn = 5e5+7;

int n, m, root;
vector<int> e[Maxn];
bool vis[Maxn];

struct Tree
{
    int fa, d;
    vector<int> f;
    Tree(){ fa = 0; d = 0;}
} tr[Maxn];

void build_tree(int cur, int depth)
{
    tr[cur].d = depth;
    tr[cur].f.push_back(cur);
    vis[cur] = true;
    for(vector<int>::iterator it = e[cur].begin(); it != e[cur].end(); it++)
    {
        if(vis[*it]) continue;
        tr[*it].fa = cur;
        tr[*it].f.assign(tr[cur].f.begin(), tr[cur].f.end());
        build_tree(*it, depth+1);
    }
}

inline int query(int x, int y)
{
    if(tr[x].d > tr[y].d)
        x = tr[x].f[tr[y].d];
    if(tr[x].d < tr[y].d)
        y = tr[y].f[tr[x].d];
    int l = 0, r = tr[x].d;
    while(l < r)
    {
        int mid = (l+r+1) >> 1;
        if(tr[x].f[mid] == tr[y].f[mid]) l = mid;
        else r = mid - 1;
    }
    return tr[x].f[l];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> root;
    for(int i = 1, u, v; i < n; ++i)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    build_tree(root, 0);
    for(int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        if(u == root || v == root)
            cout << root << endl;
        else cout << query(u, v) << endl;
    }
    return 0;
}
