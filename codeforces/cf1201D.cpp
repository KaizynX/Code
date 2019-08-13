#include <bits/stdc++.h>

using namespace std;

const int Maxn = 2e5+7;

int n, m, k, q;
int b[Maxn], l[Maxn], r[Maxn];
long long dp[Maxn][2];

inline int bfl(int v)
{
    int l = 0, r = q-1;
    while(l < r)
    {
        int mid = (l+r+1)/2;
        if(b[mid] == v) return v;
        if(b[mid] > v) r = mid-1;
        else l = mid;
    }
    return b[l];
}

inline int bfr(int v)
{
    int l = 0, r = q-1;
    while(l < r)
    {
        int mid = (l+r)/2;
        if(b[mid] == v) return v;
        if(b[mid] < v) l = mid+1;
        else r = mid;
    }
    return b[l];
}

int main()
{
    cin >> n >> m >> k >> q;
    // fill(r+1, r+n+1, 0);
    fill(l+1, l+n+1, m+1);
    memset(dp, 0x7f, sizeof dp);
    for(int i = 0, row, col; i < k; ++i)
    {
        cin >> row >> col;
        l[row] = min(l[row], col);
        r[row] = max(r[row], col);
    }
    for(int i = 0; i < q; ++i) cin >> b[i];
    sort(b, b+q);
    // 0 left 1 right
    int cost1 = (r[1] ? r[1]-1 : 0), pos1 = (r[1] ? r[1] : 1);
    int i = 2, last = 1;
    while(i <= n && !r[i]) ++i;
    if(i > n)
    {
        cout << cost1 << endl;
        return 0;
    }
    // first
    if(pos1 >= b[0])
    {
        dp[i][0] = min(dp[i][0], 1ll*cost1+pos1-bfl(pos1)+i-last+r[i]-l[i]+abs(r[i]-bfl(pos1)));
        dp[i][1] = min(dp[i][1], 1ll*cost1+pos1-bfl(pos1)+i-last+r[i]-l[i]+abs(l[i]-bfl(pos1)));
    }
    if(pos1 <= b[q-1])
    {
        dp[i][0] = min(dp[i][0], 1ll*cost1+bfr(pos1)-pos1+i-last+r[i]-l[i]+abs(r[i]-bfr(pos1)));
        dp[i][1] = min(dp[i][1], 1ll*cost1+bfr(pos1)-pos1+i-last+r[i]-l[i]+abs(l[i]-bfr(pos1)));
    }
    last = i;

    for( ; i <= n; ++i)
    {
        if(!r[i]) continue;
        if(l[last] >= b[0])
        {
            dp[i][0] = min(dp[i][0], 
                dp[last][0]+l[last]-bfl(l[last])+i-last+r[i]-l[i]+abs(r[i]-bfl(l[last])));
            dp[i][1] = min(dp[i][1],
                dp[last][0]+l[last]-bfl(l[last])+i-last+r[i]-l[i]+abs(l[i]-bfl(l[last])));
        }
        if(l[last] <= b[q-1])
        {
            dp[i][0] = min(dp[i][0], 
                dp[last][0]+bfr(l[last])-l[last]+i-last+r[i]-l[i]+abs(r[i]-bfr(l[last])));
            dp[i][1] = min(dp[i][1],
                dp[last][0]+bfr(l[last])-l[last]+i-last+r[i]-l[i]+abs(l[i]-bfr(l[last])));
        }
        if(r[last] >= b[0])
        {
            dp[i][0] = min(dp[i][0], 
                dp[last][1]+r[last]-bfl(r[last])+i-last+r[i]-l[i]+abs(r[i]-bfl(r[last])));
            dp[i][1] = min(dp[i][1],
                dp[last][1]+r[last]-bfl(r[last])+i-last+r[i]-l[i]+abs(l[i]-bfl(r[last])));
        }
        if(r[last] <= b[q-1])
        {
            dp[i][0] = min(dp[i][0], 
                dp[last][1]+bfr(r[last])-r[last]+i-last+r[i]-l[i]+abs(r[i]-bfr(r[last])));
            dp[i][1] = min(dp[i][1],
                dp[last][1]+bfr(r[last])-r[last]+i-last+r[i]-l[i]+abs(l[i]-bfr(r[last])));
        }
        last = i;
    }
    cout << min(dp[last][0], dp[last][1]) << endl;
    return 0;
}
