#include <bits/stdc++.h>

using namespace std;

const int N = 5e4+7;

int n, rt;
int du[N], ope[N], e[N][2];
double val[N], par[N];

void dfs(int u, int x)
{
    if (ope[u] == 0) {
        if (u == x) par[u] = 1;
        else par[u] = 0;
    } else if (ope[u] <= 3) {
        dfs(e[u][0], x);
        dfs(e[u][1], x);
        if (ope[u] == 1) {
            val[u] = val[e[u][0]]+val[e[u][1]];
            par[u] = par[e[u][0]]+par[e[u][1]];
        } else if (ope[u] == 2) {
            val[u] = val[e[u][0]]-val[e[u][1]];
            par[u] = par[e[u][0]]-par[e[u][1]];
        } else if (ope[u] == 3) {
            val[u] = val[e[u][0]]*val[e[u][1]];
            par[u] = val[e[u][1]]*par[e[u][0]]+val[e[u][0]]*par[e[u][1]];
        }
    } else {
        dfs(e[u][0], x);
        if (ope[u] == 4) {
            val[u] = exp(val[e[u][0]]);
            par[u] = exp(val[e[u][0]])*par[e[u][0]];
        } else if (ope[u] == 5) {
            val[u] = log(val[e[u][0]]);
            par[u] = 1.0/val[e[u][0]]*par[e[u][0]];
        } else if (ope[u] == 6) {
            val[u] = sin(val[e[u][0]]);
            par[u] = cos(val[e[u][0]])*par[e[u][0]];
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> ope[i];
        if (ope[i] == 0) {
            cin >> val[i];
        } else if (ope[i] <= 3) {
            cin >> e[i][0] >> e[i][1];
            ++du[e[i][0]]; ++du[e[i][1]];
        } else {
            cin >> e[i][0];
            ++du[e[i][0]];
        }
    }
    for (int i = 0; i < n; ++i) if (!du[i]) rt = i;
    dfs(rt, 0);
    printf("%.3f\n", val[rt]);
    for (int i = 0, flag = 0; i < n; ++i) {
        if (ope[i]) continue;
        dfs(rt, i);
        if (flag) putchar(' ');
        flag = 1;
        printf("%.3f", par[rt]);
    }
    putchar('\n');
    return 0;
}
