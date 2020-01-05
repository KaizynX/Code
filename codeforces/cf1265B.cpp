#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int T, n;
int a[N], p[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            p[a[i]] = i;
        }
        for (int i = 1, l = n, r = 1; i <= n; ++i) {
            l = min(l, p[i]);
            r = max(r, p[i]);
            cout << (r-l+1 == i);
        }
        cout << endl;
    }
    return 0;
}

