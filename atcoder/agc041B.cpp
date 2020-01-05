#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e5+7;

int n, m, v, p;
int a[N];
long long s[N];

int main()
{
    cin >> n >> m >> v >> p;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) s[i] = s[i-1]+a[i];
#ifdef DEBUG
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " \n"[i==n];
#endif
    int res = p;
    while (res < n && a[res+1] == a[p]) ++res;
    while (res < n) {
        int i = res+1;
        if (a[i]+m < a[p]) break;
        // add m to [1, p-1] and i
        long long now = 1ll*p*m;
        // add m to [i+1, n]
        now += 1ll*(n-i)*m;
        // add  [p, i-1] to <= a[i]+m
        now += 1ll*(i-p)*(a[i]+m)-(s[i-1]-s[p-1]);
        if (now < 1ll*m*v) break;
        ++res;
    }
    cout << res << endl;
    return 0;
}
