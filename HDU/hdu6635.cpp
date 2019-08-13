#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e4+7;

int T, n;
int p[Maxn], k[Maxn], f1[Maxn], f2[Maxn], res[Maxn];
int lis[Maxn], cnt;

inline void LIS()
{
    cnt = 0;
    memset(lis, 0, sizeof(int)*(n+3));
    memset(f2, 0, sizeof(int)*(n+3));
    for(int i = 1; i <= n; ++i)
    {
        if(f1[p[i]]) continue;
        int pos = upper_bound(lis, lis+cnt, p[i])-lis;
        // lis[pos] > p[i]
        if(pos == cnt)
        {
            lis[cnt++] = p[i];
            f2[p[i]] = 1;
        }
        else
        {
            f2[lis[pos]] = 0;
            f2[p[i]] = 1;
            lis[pos] = p[i];
        }
        /*
        if(!cnt || p[i] > lis[cnt-1])
        {
            lis[cnt++] = p[i];
            f2[p[i]] = 1;
        }
        int l = 0, r = cnt-1;
        while(l < r)
        {
            int mid = (l+r)/2;
            if(lis[mid] < p[i]) l = mid+1;
            else r = mid;
        }
        f2[lis[l]] = 0;
        f2[p[i]] = 1;
        lis[l] = p[i];
        */
    }
    /*
    for(int i = 0; i < cnt; ++i)
        cout << lis[i] << ' ';
    cout << endl;
    */
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        memset(f1, 0, sizeof(int)*(n+3));
        for(int i = 1; i <= n; ++i) scanf("%d", p+i);
        for(int i = 1; i <= n; ++i) scanf("%d", k+i);
        LIS();
        res[n] = cnt;
        for(int i = n; i > 1; --i)
        {
            f1[p[k[i]]] = 1;
            if(f2[p[k[i]]]) LIS();
            res[i-1] = cnt;
        }
        for(int i = 1; i < n; ++i) printf("%d ", res[i]);
        printf("%d\n", res[n]);
    }
    return 0;
}
