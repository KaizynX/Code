#include <bits/stdc++.h>

using namespace std;

const int Maxn = 60;

int n;
long long x, ans;
long long s[Maxn], p[Maxn];

int main()
{
    cin >> n >> x;
    s[0] = p[0] = 1;
    for(int i = 1; i <= n; ++i)
    {
        s[i] = s[i-1]*2+3;
        p[i] = p[i-1]*2+1;
    }
    for(int i = n; i >= 0; --i)
    {
        if(s[i] <= x)
        {
            x -= s[i];
            ans += p[i];
            if(x) // the mid P
            {
                x--;
                ans++;
            }
            if(s[i] <= x)
            {
                x -= s[i];
                ans += p[i];
            }
            if(x) x--; // the top B
        }
        else x--; // cut tht B at bottom
    }
    cout << ans << endl;
    return 0;
}
