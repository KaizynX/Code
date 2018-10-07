#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 100;
const int Maxm = 1e4+7;

int n, m, sum, ans;
int fa[Maxn];

struct Node
{
    int u, v, w;
    bool operator < (const Node &b) const
    {
        return w < b.w;
    }
} a[Maxm];

int getf(int s)
{
    return fa[s] == s ? s : fa[s] = getf(fa[s]);
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
        sum += a[i].w;
    }
    for(int i = 1; i <= n; ++i) fa[i] = i;
    sort(a, a+m);
    for(int i = 0, fu, fv; i < m; ++i)
    {
        fu = getf(a[i].u);
        fv = getf(a[i].v);
        if(fu != fv)
        {
            fa[fu] = fv;
            ans += a[i].w;
        }
    }
    cout << sum - ans << endl;
    return 0;
}
