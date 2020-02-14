#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n;
int x[N], y[N], xx[N], yy[N];
long long sx[N], sy[N], sum[N];

int main()
{
    cin >> n;
    for (int i = 1, tmp; i <= n; ++i) {
        cin >> x[i] >> y[i];
        tmp = x[i];
        x[i] = x[i]+y[i];
        y[i] = tmp-y[i];
        xx[i] = x[i];
        yy[i] = y[i];
    }
    sort(xx+1, xx+n+1);
    sort(yy+1, yy+n+1);
    for (int i = 1; i <= n; ++i) {
        sx[i] = sx[i-1]+xx[i];
        sy[i] = sy[i-1]+yy[i];
    }
    for (int i = 1; i <= n; ++i) {
        int px = lower_bound(xx+1, xx+n+1, x[i])-xx,
            py = lower_bound(yy+1, yy+n+1, y[i])-yy;
        sum[i] = sx[n]-sx[px]-1ll*(n-px)*x[i] + 1ll*(px-1)*x[i]-sx[px-1]+
                 sy[n]-sy[py]-1ll*(n-py)*y[i] + 1ll*(py-1)*y[i]-sy[py-1];
    }
    int res = 1;
    for (int i = 2; i <= n; ++i) {
        if (sum[i] < sum[res])
            res = i;
    }
    cout << sum[res]/2 << endl;
    return 0;
}
