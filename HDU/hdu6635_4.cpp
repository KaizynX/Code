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
    for(int i = nex[0]; i <= n; i = nex[i]) {
        if (!lis.size() || lis.back().back().first < p[i]) {
            lis.push_back({{ p[i], (lis.size() ? lis.back().size()-1 : -1) }});
            continue;
        }
        int l = 0, r = lis.size()-1;
        while(l < r) {
            int mid = (l+r)/2;
            if (lis[mid].back().first > p[i])
                r = mid;
            else
                l = mid+1;
        }
        lis[l].push_back({ p[i], (l ? lis[l-1].size()-1 : -1) });
    }

    memset(f, 0, sizeof(int)*n);
    pair<int, int> cur = lis.back().back();
    for(int i = lis.size()-1; i >= 0; cur = lis[--i][cur.second]) {
        f[cur.first] = 1;
        if(!i) break;
    }
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", p+i);
            pre[i] = i-1; nex[i] = i+1;
        }
        nex[0] = 1; pre[n+1] = n;
        for(int i = 1; i <= n; ++i) scanf("%d", k+i);
        LIS();
        res[n] = lis.size();
        for(int i = n; i > 1; --i) {
            del(k[i]);
            if (f[p[k[i]]]) LIS();
            res[i-1] = lis.size();
        }
        for(int i = 1; i < n; ++i) printf("%d ", res[i]);
        printf("%d\n", res[n]);
    }
    return 0;
}
