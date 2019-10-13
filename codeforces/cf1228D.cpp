#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 1e5+7;
const int M = 3e5+7;

int n, m;
int a[M], b[M], col[N], del[N];
vector<int> e[N];

inline void paint(int c)
{
    for (int i = 1; i <= n; ++i) {
        if (del[i]) continue;
        col[i] = c;
        for (int j : e[i]) del[j] = 1;
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d", a+i, b+i);
        e[a[i]].push_back(b[i]);
        e[b[i]].push_back(a[i]);
    }
    paint(1);
    for (int i = 1; i <= n; ++i) del[i] = col[i];
    paint(2);
    for (int i = 1; i <= n; ++i) del[i] = col[i];
    paint(3);

    int check[4];
    for (int i = 1; i <= 3; ++i) check[i] = 0;
    for (int i = 1; i <= n; ++i) {
        ++check[col[i]];
        if (!col[i]) return puts("-1")&0;
    }
    for (int i = 1; i <= 3; ++i) {
        if (!check[i]) return puts("-1")&0;
    }
    if (1ll*check[1]*check[2]+1ll*check[1]*check[3]+1ll*check[2]*check[3] != m) {
        return puts("-1")&0;
    }

    for (int i = 1; i <= n; ++i) {
        printf("%d%c", col[i], " \n"[i==n]);
    }
    return 0;
}
