#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3+7;

int n;
int a[MAXN][MAXN];

inline void MyFill(int x, int y, int k)
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            a[x+i][y+j] = k*16+i*4+j;
        }
    }
}

inline void print()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", a[i][j]);
        }
        putchar('\n');
    }
}

int main()
{
    cin >> n;
    int m = n/4;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            MyFill(i*4, j*4, i*m+j);
        }
    }
    print();
    return 0;
}
