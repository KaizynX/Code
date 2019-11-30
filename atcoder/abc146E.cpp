#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, k;
int a[N], s[N];
long long res;
map<int, int> cnt;

int main()
{
    cin >> n >> k;
    ++cnt[0];
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        --a[i];
        a[i] %= k;
        s[i] = (s[i-1]+a[i])%k;
        if (i-k >= 0) --cnt[s[i-k]];
        res += cnt[s[i]];
        ++cnt[s[i]];
    }
    cout << res << endl;
    return 0;
}
