#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int n;
int m[N][N], a[N];

int gcd(int x, int y) { return y ? gcd(y, x%y) : x;}

inline void print()
{
    for (int i = 1; i <= n; ++i) printf("%d%c", a[i], " \n"[i==n]);
}

inline bool check()
{
    for (int i = 1; i < n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            if (1ll*a[i]*a[j] != m[i][j]) return false;
        }
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &m[i][j]);
        }
    }
    a[1] = gcd(m[1][2], m[1][3]);
    for (int i = 4; i <= n; ++i) a[1] = gcd(a[1], m[1][i]);
    for (int i = 1, orig = a[1]; i*i <= orig; ++i) {
        if (orig%i) continue;
        a[1] = i;
        for (int i = 2; i <= n; ++i) a[i] = m[1][i]/a[1];
        if (check()) {
            print();
            return 0;
        }
        if (orig/i == i) continue;
        a[1] = orig/i;
        for (int i = 2; i <= n; ++i) a[i] = m[1][i]/a[1];
        if (check()) {
            print();
            return 0;
        }
    }
    return 0;
}
