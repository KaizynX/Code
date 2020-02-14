#include <bits/stdc++.h>

using namespace std;

const int N = 25;

int n;
int vis[N];
char a[N][N];
vector<int> res;

void dfs(int u, int d)
{
    vis[u] = 1;
    res.emplace_back(u);
    for (int i = 1; i <= n; ++i) {
        if (a[u][i] != 'W') continue;
        if (d == n && i == 1) {
            for (int j = 0; j < n; ++j)
                printf("%d%c", res[j], " \n"[j==n-1]);
            exit(0);
        }
        if (vis[i]) continue;
        dfs(i, d+1);
    }
    vis[u] = 0;
    res.pop_back();
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", a[i]+1);
    }
    dfs(1, 1);
    puts("No Solution");
    return 0;
}
