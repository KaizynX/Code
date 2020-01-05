#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int T, n, s;
int a[N], mv[N];
long long sum[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n >> s;
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum[i] = sum[i-1]+a[i];
            mv[i] = a[i] > a[mv[i-1]] ? i : mv[i-1];
            if (sum[i]-a[mv[i]] <= s) res = mv[i];
        }
        if (sum[n] <= s) res = 0;
        cout << res << endl;
    }
    return 0;
}
