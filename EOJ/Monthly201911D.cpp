#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, sum;
int a[N], b[N], vis[N];
long long res;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) res += a[i]*a[(i+1)%n];
    for (int i = 0; i < n; ++i) {
        if (!b[i]) continue;
        vis[i] = 1;
        sum -= a[i];
        res += 1ll*a[i]*(sum-(vis[(i-1+n)%n] ? 0 : a[(i-1+n)%n])-(vis[(i+1)%n] ? 0 : a[(i+1)%n]));
    }
    cout << res << endl;
    return 0;
}
