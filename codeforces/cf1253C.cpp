#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, m;
int a[N];
long long add[N], res[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    // reverse(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) {
        res[i] = res[i-1]+a[i];
        if (i > m) add[i%m] += a[i-m];
        res[i] += add[i%m];
        cout << res[i] << " ";
    }
    return 0;
}

