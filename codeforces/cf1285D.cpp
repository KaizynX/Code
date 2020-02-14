#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e5+7;

int n;
int a[N];

int f(int cur, int l, int r)
{
    if (cur < 0) return 0;
    int p = r+1;
    while (p-1 >= l && (a[p-1]>>cur)&1) --p;
    if (p == l || p > r) return f(cur-1, l, r);
    else return min(f(cur-1, l, p-1), f(cur-1, p, r))+(1<<cur);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    if (a[n] == 0) {
        cout << 0 << endl;
        return 0;
    }
    int mb = 0;
    while (a[n] >= (1<<(mb+1))) ++mb;
    cout << f(mb, 1, n) << endl;
    return 0;
}
