#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, res;
int a[N], f[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (f[a[i]-1]) f[a[i]] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        if (f[i]) res = max(res, i);
    }
    cout << (res ? n-res : -1) << endl;
    return 0;
}
