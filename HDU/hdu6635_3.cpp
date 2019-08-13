#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e4+7;

int T, n;
int p[Maxn], k[Maxn], pre[Maxn], nex[Maxn], f[Maxn], res[Maxn];
vector<vector<pair<int, int> > > lis;

inline void del(int i)
{
    nex[pre[i]] = nex[i];
    pre[nex[i]] = pre[i];
}

inline void LIS()
{
    lis.clear();
    for(int i = nex[0]; i <= n; i = nex[i])
    {
        if(!lis.size() || lis.back().back().first < p[i])
            lis.push_back(vector<pair<int, int> >{ make_pair(p[i], i) });
        int l = 0, r = lis.size()-1;
        while(l < r)
        {
            int mid = (l+r)/2;
            if(lis[mid].back().first > p[i]) r = mid;
            else l = mid+1;
        }
        lis[l].push_back(make_pair(p[i], i));
    }

    memset(f, 0, sizeof(int)*n);
    pair<int, int> last = lis.back().front();
    f[last.first] = 1;
    for(int i = lis.size()-2; i >= 0; --i)
    {
        int l = 0, r = lis[i].size()-1;
        while(l < r)
        {
            int mid = (l+r)/2;
            if(lis[i][mid].first > last.first) l = mid+1;
            else r = mid;
        }
        r = lis[i].size()-1;
        // [l, r].first < last.first
        while(l < r)
        {
            int mid = (l+r+1)/2;
            if(lis[i][mid].second > last.second) r = mid-1;
            l = mid;
        }
        last = lis[i][l];
        f[last.first] = 1;
    }
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", p+i);
            pre[i] = i-1; nex[i] = i+1;
        }
        nex[0] = 1; pre[n+1] = n;
        for(int i = 1; i <= n; ++i) scanf("%d", k+i);
        LIS();
        res[n] = lis.size();
        for(int i = n; i > 1; --i)
        {
            del(k[i]);
            if(f[p[k[i]]]) LIS();
            res[i-1] = lis.size();
        }
        for(int i = 1; i < n; ++i) printf("%d ", res[i]);
        printf("%d\n", res[n]);
    }
    return 0;
}
