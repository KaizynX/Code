#include <algorithm>
#include <iostream>
#include <cstring>
#define DEBUG

using namespace std;

const int Maxm = 110;

int L, s, t, m, ans = Maxm;
int a[Maxm], f[Maxm];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> s >> t >> m;
    for(int i = 1; i <= m; ++i)
        cin >> a[i];
    sort(a+1, a+1+m);
    // a[m+1] = L; a[0] = 0;
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for(int i = 1; i <= m; ++i)
    {
        for(int j = i-1, dis; j >= 0; --j)
        {
            dis = a[i]-a[j];
            if(dis < s) continue;
            if(dis > t) break;
            f[i] = min(f[i], f[j]+1);
        }
    }
    for(int i = m; i >= 0; --i)
    {
        if(L-a[i] > t) break;
        ans = min(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}
