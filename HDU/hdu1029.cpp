#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;

int n;

int main()
{
    while (scanf("%d", &n) == 1) {
        int res = 0;
        for (int i = 1, a, cnt = 0; i <= n; ++i) {
            scanf("%d", &a);
            if (a != res) --cnt;
            else ++cnt;
            if (cnt < 0) res = a, cnt = 1;
        }
        printf("%d\n", res);
    }
    return 0;
}
