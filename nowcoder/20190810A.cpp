#include <bits/stdc++.h>

using namespace std;

const int Maxn = 3e3+7;

char mapp[Maxn][Maxn];
int sum[Maxn][Maxn], vis[Maxn][Maxn];
int nowh[Maxn][Maxn];
pair<int, int> stac[Maxn];
int tail;
vector<int> st[Maxn][Maxn];

inline int SameR(vector<int> &x, vector<int> &y)
{
    int num = 0;
    for(auto i : x)
        for(auto j : y)
            if(i == j) ++num;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%s", mapp[i]+1);
        for(int j = 1; j <= m; ++j)
            sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mapp[i][j]-'0';
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if(mapp[i][j] == '0') nowh[i][j] = 0;
            else nowh[i][j] = nowh[i-1][j]+1;
        }
        stac[tail = 1] = make_pair(nowh[i][1], 1);
        for(int j = 1; j <= m; ++j)
        {
            if(nowh[i][j] < 2) continue;
            if(nowh[i][j] == stac[tail].first)
            {
                ;
                continue;
            }
            if(nowh[i][j] < stac[tail].first)
            {
                while(tail && stac[tail].first > nowh[i][j]) tail--;
            }
            else
            {
                st[i][j].assign(st[i][stac[tail].second].begin(), st[i][stac[tail].second].end());
                st[i][j].push_back(stac[tail].second);
                stac[++tail] = make_pair(nowh[i][j], j);
            }
            res += st[i][j].size();
            res -= SameR(st[i][j], st[i-1][j]);
        }
    }
    return 0;
}
