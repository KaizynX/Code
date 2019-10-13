#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n;
int a[N], p[N];

int dp(int x)
{
    if (p[x] != -1) return p[x];
    for (int i = a[x]; x-i > 0 || x+i <= n; i += a[x]) {
        if (x-i > 0 && a[x-i] > a[x] && !dp(x-i)) return p[x] = 1;
        if (x+i <= n && a[x+i] > a[x] && !dp(x+i)) return p[x] = 1;
    }
    return p[x] = 0;
}

int main()
{
    cin >> n;
    memset(p, -1, sizeof(int)*(n+1));
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (p[i] == -1) {
            dp(i);
        }
        cout << (p[i] ? 'A' : 'B');;
    }
    cout << endl;
    return 0;
}
