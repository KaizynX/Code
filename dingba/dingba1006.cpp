#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int n;
int a[N][N], b[N][N];

int main()
{
    while (cin >> n) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                cin >> a[i][j];
        int x[4], y[4];
        for (int i = 1; i <= (n+1)/2; ++i) {
            for (int j = i; j <= n-i+1; ++j) {
                x[0] = i; y[0] = j;
                x[1] = n-j+1; y[1] = i;
                x[2] = n-i+1; y[2] = n-j+1;
                x[3] = j; y[3] = n-i+1;
                for (int k = 0; k < 4; ++k)
                    b[x[k]][y[k]] = a[x[(k+3)%4]][y[(k+3)%4]];
            }
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                printf("%d%c", b[i][j], " \n"[j==n]);
    }
    return 0;
}
