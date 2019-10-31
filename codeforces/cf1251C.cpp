#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+7;

int t, n;
int a[2][N], cnt[2];
char s[N];

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        n = strlen(s);
        cnt[0] = cnt[1] = 0;

        for (int i = 0, cur; i < n; ++i) {
            cur = s[i]-'0';
            a[cur&1][++cnt[cur&1]] = cur;
        }
        int i = 1, j = 1;
        while (i <= cnt[0] && j <= cnt[1]) {
            if (a[0][i] < a[1][j]) printf("%d", a[0][i++]);
            else printf("%d", a[1][j++]);
        }
        while (i <= cnt[0]) printf("%d", a[0][i++]);
        while (j <= cnt[1]) printf("%d", a[1][j++]);
        putchar('\n');
    }
    return 0;
}
