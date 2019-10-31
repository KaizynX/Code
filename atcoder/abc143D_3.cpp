#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 2e3+7;

int n;
int a[N];
long long res;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for (int i = 1; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            int l = a[j]-a[i], r = a[i]+a[j];
            // l < a[k] < r
            res += lower_bound(a+j+1, a+n+1, r)-upper_bound(a+j+1, a+n+1, l);
#ifdef DEBUG
            cout << res << endl;
#endif
        }
    }
    cout << res << endl;
    return 0;
}
