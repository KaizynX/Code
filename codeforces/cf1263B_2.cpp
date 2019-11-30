#include <bits/stdc++.h>

using namespace std;

const int N = 1e1+7;
const int M = 1e4+7;

int T, n;
int a[N], vis[M];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a+i);
            ++vis[a[i]];
        }
        for (int i = 1; i <= n; ++i) {
            if (vis[a[i]] > 1) {
                ++res;
                --vis[a[i]];
                for (int j = 0; j <= 9; ++j) {
                    if (!vis[a[i]-a[i]%10+j]) {
                        a[i] = a[i]-a[i]%10+j;
                        break;
                    }
                }
            }
            ++vis[a[i]] ;
        }
        cout << res << endl;
        for (int i = 1; i <= n; ++i) {
            printf("%04d\n", a[i]);
            --vis[a[i]] = 0;
        }
    }
    return 0;
}

