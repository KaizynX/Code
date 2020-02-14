#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n;
int k[N];
vector<int> e[N];
double z, r, res;

void dfs(int u, double now)
{
    if (!k[u]) {
        res += now*e[u][0];
        return;
    }
    for (int v : e[u]) {
        dfs(v, now*r);
    }
}

int main()
{
    scanf("%d%lf%lf", &n, &z, &r);
    r = (100.0-r)/100.0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", k+i);
        e[i].resize((k[i] ? k[i] : 1));
        for (int j = 0; j < (k[i] ? k[i] : 1); ++j)
            scanf("%d", &e[i][j]);
    }
    dfs(0, z);
    // printf("%.0f\n", res);
    printf("%lld\n", (long long)res);
    return 0;
}
