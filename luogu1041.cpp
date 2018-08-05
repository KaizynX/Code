#include <cstdio>
#include <vector>
#include <iostream>
#define DEBUG

using namespace std;

const int Maxn = 307;

int n, p, ans;
vector<int> e[Maxn];
int q[Maxn][Maxn], cnt[Maxn];
int flag[Maxn], w[Maxn], fa[Maxn];

int build_tree(int cur, int depth)
{
    for(vector<int>::iterator it = e[cur].begin(); it != e[cur].end(); ++it)
    {
        if(*it == fa[cur]) continue;
        q[depth][++cnt[depth]] = *it;
        fa[*it] = cur;
        w[cur] += build_tree(*it, depth+1);
    }
    return w[cur] += 1;
}

void cut(int cur, int v) // set the flag of the tree
{
    flag[cur] += v;
    for(vector<int>::iterator it = e[cur].begin(); it != e[cur].end(); ++it)
        if(*it != fa[cur]) cut(*it, v);
}

void dfs(int cur, int num)
{
    bool is_end = true;
    for(int i = 1, now; i <= cnt[cur]; ++i)
    {
        now = q[cur][i];
        if(flag[now]) continue;
        is_end = false;
        // cut this
        cut(now, 1);
        dfs(cur+1, num-w[now]);
        cut(now, -1);
    }
    if(is_end) ans = min(ans, num);
}

int main()
{
    scanf("%d%d", &n, &p);
    for(int i = 0, u, v; i < p; ++i)
    {
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    ans = n;
    build_tree(1, 1);
    dfs(1, n);
#ifdef DEBUG
    puts("DEBUG:");
    for(int i = 1; i <= n; ++i)
        printf("%d ", fa[i]);
    putchar('\n');
    for(int i = 1; i <= n; ++i)
        printf("%d ", w[i]);
    putchar('\n');
    int tmp = 1;
    while(cnt[tmp])
    {
        printf("%d: ", tmp);
        for(int i = 1; i <= cnt[tmp]; ++i)
        {
            printf("%d ", q[tmp][i]);
        }
        ++tmp;
        putchar('\n');
    }
    putchar('\n');
#endif
    printf("%d\n", ans);
    return 0;
}
