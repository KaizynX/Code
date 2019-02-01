#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n, m;
int a[Maxn], c[Maxn], k[Maxn];

bool cmp(int x, int y)
{
    return c[x] == c[y] ? x < y : c[x] < c[y];
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        k[i] = i;
    }
    for(int i = 1; i <= n; ++i)
    {
        cin >> c[i];
    }
    sort(k+1, k+n+1, cmp);
    int pos = 1;
    for(int i = 1, t, d; i <= m; ++i)
    {
        long long res = 0;
        cin >> t >> d;
        int tmp = min(d, a[t]);
        res += 1ll*tmp*c[t];
        a[t] -= tmp;
        d -= tmp;
        while(d)
        {
            while(pos <= n && !a[k[pos]]) pos++;
            if(pos > n) break;
            tmp = min(d, a[k[pos]]);
            res += 1ll*tmp*c[k[pos]];
            a[k[pos]] -= tmp;
            d -= tmp;
        }
        cout << (d ? 0 : res) << endl;
    }
    return 0;
}
