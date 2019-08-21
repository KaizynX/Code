#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int MAXN = 2e3+7;

int p[MAXN];
char s[MAXN];

int main()
{
    scanf("%s", s+1);
    int n = strlen(s+1);
    for (int i = 1; i < n; ++i) {
        if (p[i]) continue;
        if (s[i] == '1' && s[i+1] == '0') {
            p[i] = i+1;
            p[i+1] = i;
            int l = i, r = i+1;
            while (l-1 > 0 && r+1 <= n) {
                if (p[l-1]) {
                    l = p[l-1];
                    p[r] = l;
                    p[l] = r;
                } else if (p[r+1]) {
                    r = p[r+1];
                    p[l] = r;
                    p[r] = l;
                } else if (s[l-1] == '1' && s[r+1] == '0') {
                    --l; ++r;
                    p[l] = r;
                    p[r] = l;
                } else {
                    break;
                }
            }
#ifdef DEBUG
            printf("%d %d", l, r);
#endif
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%c", (p[i] ? s[i] : '0'));
    }
    putchar('\n');
    return 0;
}
