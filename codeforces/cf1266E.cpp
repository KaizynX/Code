#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, q;
int a[N], cnt[N];
long long sum;
map<pair<int, int>, int> mp;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    cin >> q;
    for (int i = 1, s, t, u; i <= q; ++i) {
        cin >> s >> t >> u;
        int last = mp[{s, t}];
        if (last) {
            if (cnt[last] <= a[last]) ++sum;
            --cnt[last];
        }
        ++cnt[mp[{s, t}] = u];
        if (cnt[u] <= a[u]) --sum;
        cout << sum << endl;
    }
    return 0;
}

