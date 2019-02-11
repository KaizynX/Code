#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int Maxn = 1e3+7;

int T, S, D;
int s[Maxn], d[Maxn];
int dd[Maxn];
int e[Maxn][Maxn];

void Dijiskra()
{
    typedef pair<int, int> pr;
    priority_queue<pr, vector<pr>, greater<pr> > q;
    memset(dd, 0x3f, sizeof dd);
    for(int i = 1; i <= S; ++i)
    {
        q.push(make_pair(0, s[i]));
        dd[s[i]] = 0;
    }
    while(q.size())
    {
        pr cur = q.top();
        q.pop();
        int now = cur.second;
        if(cur.first > dd[now]) continue;
        for(int i = 1; i <= 1000; ++i)
        {
            if(e[now][i] == -1) continue;
            if(dd[now]+e[now][i] < dd[i])
            {
                dd[i] = dd[now]+e[now][i];
                q.push(make_pair(dd[i], i));
            }
        }
    }
}

int main()
{
    while(cin >> T >> S >> D)
    {
        memset(e, -1, sizeof e);
        for(int i = 1, a, b, t; i <= T; ++i)
        {
            cin >> a >> b >> t;
            if(e[a][b] == -1) e[a][b] = e[b][a] = t;
            else e[a][b] = e[b][a] = min(e[a][b], t);
        } 
        for(int i = 1; i <= S; ++i)
            cin >> s[i];
        for(int i = 1; i <= D; ++i)
            cin >> d[i];
        Dijiskra();
        int ans = INF;
        for(int j = 1; j <= D; ++j)
            ans = min(ans, dd[d[j]]);
        cout << ans << endl;
    }
    return 0;
}