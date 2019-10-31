#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, l, r;
int a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        r += a[i];
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n/2; ++i) {
        l += a[i];
    }
    r -= l;
    cout << 1ll*l*l+1ll*r*r << endl;
    return 0;
}
