#include <iostream>
#include <cstring>

using namespace std;

const int Maxn = 20;
const int Maxv = 5e4;

int n, k, res[Maxn], a[Maxn], ans, f[Maxv];

int dp(int cur)
{
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for(int i = 1; i <= cur; ++i)
        for(int j = a[i]; j <= a[cur]*n; ++j)
            f[j] = min(f[j], f[j-a[i]]+1);
    for(int i = 1; i <= a[cur]*n; ++i)
        if(f[i] > n) return i-1;
    return a[cur]*n;
}

void dfs(int cur, int mx)
{
    if(cur > k)
    {
        if(mx > ans)
        {
            ans = mx;
            memcpy(res, a, sizeof(int)*(k+1));
        }
        return;
    }
    for(int i = a[cur-1]+1, tmp; i <= mx+1; ++i)
    {
        a[cur] = i;
        tmp = dp(cur);
        dfs(cur+1, tmp);
    }
}

int main()
{
    cin >> n >> k;
    dfs(1, 0);
    for(int i = 1; i <= k; ++i)
        cout << res[i] << " ";
    cout << endl << "MAX=" << ans << endl;
    return 0;
}
