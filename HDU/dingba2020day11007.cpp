#include <bits/stdc++.h>

using namespace std;

const int N = 5e5;

int T, n;
int f[N+7];

inline void init()
{
    for (int i = 1; i <= N; ++i)
        for (int j = i*2; j <= N; j += i)
            f[j] += i;
}

int main()
{
    init();
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int m = f[n];
        if (n == m || m > N || m < 1) {
            puts("ע������");
            continue;
        }
        int k = f[m];
        if (n == k) puts("Ե���Ѷ�");
        else puts("Ե��δ��");
    }
    return 0;
}
