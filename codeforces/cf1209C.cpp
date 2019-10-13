#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5+7;
const int INF = 1e9;

int n, T;
char d[MAXN];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s", &n, d);
        int _flag = 0;
        for (int cut = '0'; cut < '9'; ++cut) {
            // [0, cut], [cut+1, 9]
            int flag = 1;
            for (int i = 0, last1 = -1, last2 = -1; i < n; ++i) {
                if (d[i] <= cut) {
                    if (last1 == -1) last1 = d[i];
                    else if (d[i] > last1) last1 = d[i];
                    else {
                        flag = 0;
                        break;
                    }
                } else {
                    if (last2 == -1) last2 = d[i];
                    else if (d[i] >= last2) last2 = d[i];
                    else {
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag) {
                _flag = 1;
                for (int i = 0; i < n; ++i)
                    putchar((d[i] <= cut ? '1' : '2'));
                break;
            }
        }
        if (!_flag) putchar('-');
        putchar('\n');
    }
    return 0;
}
