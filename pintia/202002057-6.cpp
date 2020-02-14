#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n;
char ch;
char a[N][N], b[N][N];

int main()
{
    scanf("%c %d", &ch, &n);
    getchar();
    for (int i = 1; i <= n; ++i) {
        fgets(a[i]+1, sizeof a[i]+1, stdin);
        for (int j = 1; j <= n; ++j)
            b[n-i+1][n-j+1] = a[i][j];
    }
    int flag = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            flag &= a[i][j] == b[i][j];
    if (flag) puts("bu yong dao le");
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            putchar((b[i][j] == ' ' ? ' ' : ch));
        putchar('\n');
    }
    return 0;
}
