#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n;
int a[N], cnt[32], f[N];

inline void add(int x, int k)
{
    for (int i = 0; i < 31; ++i)
        cnt[i] += k*((x>>i)&1);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        add(a[i], 1);
    }
    int res = 1;
    for (int i = 1, tmp; i <= n; ++i) {
        add(a[i], -1);
        tmp = 0;
        for (int j = 0; j < 31; ++j) {
            if (((a[i]>>j)&1) && !cnt[j])
                tmp += 1<<j;
        }
        f[i] = tmp;
        if (f[i] > f[res]) res = i;
        add(a[i], 1);
    }
    cout << a[res];
    for (int i = 1; i <= n; ++i) {
        if (i == res) continue;
        cout << " " << a[i];
    }
    cout << endl;
    return 0;
}
