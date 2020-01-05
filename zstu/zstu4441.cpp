#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+7;
const int M = 22;

int T, n;
int a[N];
bitset<2200007> f;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a+i);
        }
        if (n > 22) {
            puts("no");
            continue;
        }
        f.reset();
        f[0] = 1;
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            if (((f<<a[i])&f).any()) {
                flag = 1;
                break;
            } else {
                f |= f<<a[i];
            }
        }
        puts((flag ? "no" : "yes"));
    }
    return 0;
}
