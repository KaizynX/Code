#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 5e2+7;

int n, m;
int a[N][N];

inline void print()
{
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cout << a[i][j] << " \n"[j==m];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    if (m == 1) {
        if (n == 1) {
            cout << 0 << endl;
            return 0;
        }
        for (int i = 1; i <= n; ++i) a[i][1] = i+1;
        print();
        return 0;
    }
    for (int i = 1; i <= m; ++i) a[1][i] = i+1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[i][j] = a[1][j]*(m+i);
        }
    }
    print();
#ifdef DEBUG
    for (int i = 1; i <= n; ++i) {
        int g = a[i][1];
        for (int j = 1; j <= m; ++j)
            g = __gcd(g, a[i][j]);
        cout << g << " ";
    }
    for (int j = 1; j <= m; ++j) {
        int g = a[1][j];
        for (int i = 1; i <= n; ++i)
            g = __gcd(g, a[i][j]);
        cout << g << " ";
    }
#endif
    return 0;
}

