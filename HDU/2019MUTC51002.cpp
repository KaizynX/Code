#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e4+7;

int T, n;
int p[Maxn], k[Maxn], res[Maxn], cnt[Maxn];
pair<int, int> pos[Maxn];

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        vector<vector<int> > ll, tr;
        scanf("%d", &n);
        memset(cnt, 0, sizeof(int)*(n+2));
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", p+i);
            if(!ll.size())
            {
                ll.push_back(vector<int>{p[i]});
                pos[p[i]] = make_pair(0, 0);
                continue;
            }
            if(p[i] > ll.back().back())
            {
                pos[p[i]] = make_pair(ll.size(), 0);
                ll.push_back(vector<int>{p[i]});
                continue;
            }
            int l = 0, r = ll.size()-1;
            while(l < r)
            {
                int mid = (l+r)/2;
                if(ll[mid].back() > p[i]) r = mid;
                else l = mid+1;
            }
            // ll[l].back() > p[i]
            pos[p[i]] = make_pair(l, ll[l].size());
            ll[l].push_back(p[i]);
            res[n] = ll.size();
        }
        for(int i = 1; i <= n; ++i)
            scanf("%d", k+i);
        for(int i = n; i > 1; --i)
        {
            int v = p[k[i]];
            res[i-1] = res[i];
            if(++cnt[pos[v].first] == ll[pos[v].first].size())
                res[i-1]--;
        }
        for(int i = 1; i < n; ++i) printf("%d ", res[i]);
        printf("%d\n", res[n]);
    }
    return 0;
}
