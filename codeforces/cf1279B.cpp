#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int T, n, s;
int a[N], mv[N];
long long dp[N][2], sum[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n >> s;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum[i] = sum[i-1]+a[i];
            mv[i] = max(mv[i-1], a[i]);
        }
        if (sum[n] <= s) {
            cout << 0 << endl;
            continue;
        }
        int l = 1, r = n;
        while (l < r) {
            int mid = (l+r+1)>>1;
            if (sum[mid]-mv[mid] > s) r = mid-1;
            else l = mid;
        }
        for (int i = 1; i <= n; ++i) {
            if (a[i] == mv[l]) {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}

