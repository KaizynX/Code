#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n, x, y;
int a[Maxn];

int main()
{
    cin >> n >> x >> y;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i)
    {
        int flag = 1;
        for(int j = max(1, i-x); j <= min(n, i+y); ++j)
        {
            if(i == j) continue;
            if(a[i] >= a[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
