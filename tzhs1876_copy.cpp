#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 10010, maxm = 200010;

int n, m,first,tail,x[maxm],y[maxm],nextt[maxm * 2],to[maxm * 2],head[maxm],tot,s,t,q[maxn],step[maxn];
bool vis[maxn];

void add(int a, int b)
{
    to[++tot] = b;
    nextt[tot] = head[a];
    head[a] = tot;
}

void bfs1()
{
    q[0] = t;
    vis[t] = true;
    first = 0;
    tail = 1;
    while (first < tail)
    {
        int u = q[first++];
        for (int i = head[u];i;i = nextt[i])
        {
            if (!vis[to[i]])
            {
                vis[to[i]] = true;
                q[tail++] = to[i];
            }
        }
    }
}

bool chubian(int q)
{
    for (int i = head[q]; i; i = nextt[i])
        if (!vis[to[i]])
            return false;
    return true;
}

bool bfs2()
{
    first = 0;
    tail = 1;
    q[0] = s;
    step[s] = 0;
    while (first < tail)
    {
        int u = q[first++];
        if (!chubian(u))
            continue;
        for (int i = head[u]; i; i = nextt[i])
        {
            if (step[to[i]] == -1)
            {
                step[to[i]] = step[u] + 1;
                q[tail++] = to[i];
                if (to[i] == t)
                {
                    printf("%d", step[to[i]]);
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    memset(vis, false, sizeof(vis));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
        add(y[i], x[i]); //反着加便于反着bfs
    }
    scanf("%d%d", &s,&t);
    bfs1();
    memset(head, 0, sizeof(head));
    memset(step, -1, sizeof(step));
    memset(q, 0, sizeof(q));
    memset(nextt, 0, sizeof(nextt));
    memset(to, 0, sizeof(to));
    tot = 0;
    for (int i = 1; i <= m; i++)
        add(x[i], y[i]);
    if (!vis[s])
    {
        printf("-1\n");
        return 0;
    }
    if (!bfs2())
        printf("-1\n");

    return 0;
}
