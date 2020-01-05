#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int n;
int a[N], x[N][N], y[N][N];

inline bool check(int s) {
    for (int i = 0; i < n; ++i) if((s>>i)&1) {
        for (int j = 0; j < a[i]; ++j) {
            if (((s>>x[i][j])&1) != y[i][j])
                return false;
        }
    }
    return true;
}

inline int count(int x)
{
    int res = 0;
    while (x) {
        res += x&1;
        x >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < a[i]; ++j) {
            cin >> x[i][j] >> y[i][j];
            --x[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < 1<<n; ++i) {
        if (check(i))
            res = max(res, count(i));
    }
    cout << res << endl;
    return 0;
}

