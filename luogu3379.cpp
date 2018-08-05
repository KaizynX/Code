#include <iostream>
#include <vector>

using namespace std;

const int Maxn = 5e5+7;

int n, m, root;
vector<int> e[Maxn];
bool vis[Maxn];

struct Tree
{
    int fa, d;
    Tree(){ fa = 0; d = 0; }
} tr[Maxn];

void build_tree(int cur, int depth)
{
    tr[cur].d = depth;
    vis[cur] = true;
    for(vector<int>::iterator it = e[cur].begin(); it != e[cur].end(); it++)
    {
        if(vis[*it]) continue;
        tr[*it].fa = cur;
        build_tree(*it, depth+1);
    }
}

inline int query(int x, int y)
{
    while(tr[x].d > tr[y].d)
        x = tr[x].fa;
    while(tr[x].d < tr[y].d)
        y = tr[y].fa;
    while(x != y)
    {
        x = tr[x].fa;
        y = tr[y].fa;
    }
    return x;
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
    build_tree(root, 1);
    for(int i = 0, u, v; i < m; ++i)
    {
        cin >> u >> v;
        if(u == root || v == root)
            cout << root << endl;
        else cout << query(u, v) << endl;
    }
    return 0;
}
