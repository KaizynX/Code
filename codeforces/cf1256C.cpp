#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int n, m, d;
int c[N], res[N];

int main()
{
    cin >> n >> m >> d;
    int sum = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> c[i];
        sum += c[i];
    }
    int id = 1, p = d;
    for ( ; id <= m && p < n-sum+1; ++id) {
        for (int j = 0; j < c[id]; ++j) {
            res[p+j] = id;
        }
        sum -= c[id];
        p += c[id]-1+d;
    }
    if (p < n-sum+1) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = m, j = n; i >= id; --i) {
        for (int k = 0; k < c[i]; ++k) {
            res[j--] = i;
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << " \n"[i==n];
    }
    return 0;
}
