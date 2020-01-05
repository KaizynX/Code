#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n[4], nn[4], m;
int a[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 4; ++i) cin >> n[i], m += n[i];
    for (int i = 1; i <= n[1] && i <= n[2]; ++i) {
        for (int j = 0; j < 4; ++j) nn[j] = n[j];
        nn[1] -= i;
        nn[2] -= i;
        if (nn[0]-nn[1] < 0 || nn[0]-nn[1] > 1 || nn[3]-nn[2] < 0 || nn[3]-nn[2] > 1) continue;

        int k = 0;
        if (nn[0] > nn[1]) a[++k] = 0;
        for (int j = 1; j <= nn[1]; ++j) {
            a[++k] = 1;
            a[++k] = 0;
        }
        for (int j = 1; j <= i; ++j) {
            a[++k] = 1;
            a[++k] = 2;
        }
        for (int j = 1; j <= nn[2]; ++j) {
            a[++k] = 3;
            a[++k] = 2;
        }
        if (nn[3] > nn[2]) a[++k] = 3;

        cout << "YES" << endl;
        for (int i = 1; i <= m; ++i)
            cout << a[i] << " \n"[i==m];
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}

