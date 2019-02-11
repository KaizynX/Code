#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n, m, k;
int b[Maxn], a[Maxn];

int main()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        a[i] = b[i]-b[i-1];
    }
    sort(a+2, a+n+1);
    int sum = k;
    for(int i = 2; i < n-k+2; ++i)
        sum += a[i];
    cout << sum << endl;
    return 0;
}