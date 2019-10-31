#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 2e3+7;

int n, m;
int a[N], cnt[N];
long long res;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    sort(a+1, a+n+1);
    m = unique(a+1, a+n+1)-a;

    for (int i = 1; i < m; ++i) {
        for (int j = i+1; j < m; ++j) {
            // a[j]-a[i] <  <(=) a[j]+a[i]
            res += lower_bound(a+j+1, a+m, a[j]+a[i])-upper_bound(a+j+1, a+m, a[j]-a[i]);
        }
        if (cnt[a[i]] == 1) continue;
        //  < a[i]*2
        res += lower_bound(a+i+1, a+m, a[i]*2)-a-1;
        if (cnt[a[i]] == 2) --res;
    }
    cout << res << endl;
    return 0;
}
