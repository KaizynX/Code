#include <bits/stdc++.h>

using namespace std;

long long k, m;
map<long long, int> mmp;

int main()
{
    cin >> k >> m;
    // 10^n (%m) = 9k+1 (%m)
    int t = sqrt(m);
    k = (k*9+1)%m;
    long long tmp = 1; // tmp = 10^i
    for(int i = 0; i < t; ++i)
    {
        mmp[(__int128)k*tmp%m] = i;
        tmp = tmp*10%m;
    }
    // now tmp = 10^t
    long long now = 1; // now = (10^t)^i
    for(int i = 0; i <= t; ++i)
    {
        if(mmp.count(now))
        {
            long long ans = 1ll*i*t-mmp[now];
            if(ans > 0)
            {
                cout << ans << endl;
                break;
            }
        }
        now = (__int128)now*tmp%m;
    }
    return 0;
}
