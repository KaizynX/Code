#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3+107;

int T, S, D;
int e[Maxn][Maxn];
int dis[Maxn];
int q[100000], head, tail;

int main()
{
    cin >> T >> S >> D;
    memset(e, 0x7f, sizeof e);
    for(int i = 1, a, b, t; i <= T; ++i)
    {
        cin >> a >> b >> t;
        e[a][b] = e[b][a] = min(e[a][b], t);
    } 
    memset(dis, 0x7f, sizeof dis);
    head = tail = 0;
    for(int i = 1, s; i <= S; ++i)
    {
        cin >> s;
        dis[s] = 0;
        q[++tail] = s;
    }
    while(head < tail)
    {
        int cur = q[++head];
        for(int i = 1; i <= 1000; ++i)
        {
            if(e[cur][i] == -1) continue;
            int tmp = dis[cur]+e[cur][i];
            if(tmp >= dis[i]) continue;
            dis[i] = tmp;
            q[++tail] = i;
        }
    }
    int ans = 0x7f7f7f7f;
    for(int i = 1, d; i <= D; ++i)
    {
        cin >> d;
        ans = min(ans, dis[d]);
    }
    cout << ans << endl;
    return 0;
}