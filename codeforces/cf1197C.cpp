#include <bits/stdc++.h>

using namespace std;

const int Maxn = 3e5+7;

int n, k;
int a[Maxn], d[Maxn];

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if(i) d[i-1] = a[i]-a[i-1];
    }
    int res = 0;
    sort(d, d+n-1);
    reverse(d, d+n-1);
    for(int i = 0; i < k-1; ++i)
        res += d[i];
    cout << a[n-1]-a[0]-res << endl;
    return 0;
}
