#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int n, a, h, m;
char c;
int s[N], t[N];

int main()
{
    scanf("%d", &n);
    while (n--) {
        memset(s, -1, sizeof s);
        memset(t, -1, sizeof t);
        int cnt = 0, time = 0;
        while (scanf("%d %c %d:%d", &a, &c, &h, &m) == 4 && a) {
            if (c == 'S') s[a] = h*60+m;
            else if (s[a] != -1) t[a] = h*60+m;
            if (s[a] != -1 && t[a] != -1) {
                ++cnt;
                time += t[a]-s[a];
                s[a] = t[a] = -1;
            }
        }
        if (!cnt) printf("0 0\n");
        else printf("%d %.0f\n", cnt, 1.0*time/cnt);
    }
    return 0;
}
