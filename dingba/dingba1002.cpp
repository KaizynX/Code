#include <bits/stdc++.h>

using namespace std;

const int N = 47;

int n, m;
char a[N][N];

int main()
{
    while (cin >> n >> m) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                a[i][j] = '*';
            }
        }
        int d = (n-m)/2;
        for (int i = d+1; i <= n-d; ++i) {
            for (int j = d+1; j <= n-d; ++j) {
                a[i][j] = ' ';
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                putchar(a[i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}
