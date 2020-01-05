#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+7;
const int MOD = 1e9+7;

int n;
long long a[N];
int cnt[70];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 0; j < 60; ++j) {
            if ((a[i]>>j)&1) ++cnt[j];
        }
    }
    long long sum = 0;
    for (int i = 0; i < 60; ++i) {
        (sum += (1ll<<i)%MOD*cnt[i]%MOD*(n-cnt[i])%MOD) %= MOD;
    }
    cout << sum << endl;
    return 0;
}

