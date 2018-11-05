#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e4+7;
const int Maxm = 2e5+7;

int n, m;
int fa[Maxn];

inline void init() { for(int i = 1; i <= n; ++i) fa[i] = i; }
int getf(int s) { return fa[s] == s ? s : fa[s] = getf(fa[s]); }
inline void connect(int x, int y)
{
    int fx = getf(x), fy = getf(y);
    if(fx != fy) fa[fx] = fy;
}

int main()
{
    scanf("%d%d", &n, &m);
    init();
    while(m--)
    {
        int z, x, y;
        scanf("%d%d%d", &z, &x, &y);
        if(z == 1) connect(x, y);
        else puts(getf(x) == getf(y) ? "Y" : "N");
    }
    return 0;
}
