#include <bits/stdc++.h>

using namespace std;

const int Maxn = 2e5+7;

int n, k;
int a[Maxn];

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a, a+n);
    int cur = a[n/2];
    for(int i = n/2+1; i < n; ++i)
    {
        if(k-1ll*(i-n/2)*(a[i]-cur) >= 0)
        {
            k -= (i-n/2)*(a[i]-cur);
            cur = a[i];
        }
        else
        {
            cout << cur+k/(i-n/2) << endl;
            return 0;
        }
    }
    cout << cur+k/(n-n/2) << endl;
    return 0;
}
