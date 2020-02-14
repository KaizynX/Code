#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int n, m;
char s[N];
char a[N][N];

int main()
{
    scanf("%d", &n);
    getchar();
    fgets(s, sizeof s, stdin);
    int len = strlen(s)-1;
    for (int i = 0; i < len; ++i)
        a[i%n][i/n] = s[i];
    for (int i = 0; i < n; ++i) {
        for (int j = (len-1)/n; j >= 0; --j) {
            putchar((a[i][j] ? a[i][j] : ' '));
        }
        putchar('\n');
    }
    return 0;
}
