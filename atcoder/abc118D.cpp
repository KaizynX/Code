#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int num[10] = { 0, 1, 7, 4, 2, 3, 5, 6, 9, 8 };
const int val[10] = { 0, 2, 3, 4, 5, 5, 5, 6, 6, 7 };

int n, m;
int vis[10], cnt[10];

inline void print()
{
    for (int i = 9; i; --i) {
        for (int j = 0; j < cnt[i]; ++j) {
            putchar('0'+i);
        }
    }
    putchar('\n');
}

void dfs(int cur, int rest)
{
    if (!rest) { print(); exit(0); }
    if (cur > 9) return;
    if (!vis[num[cur]]) {
        dfs(cur+1, rest);
        return;
    }
#ifdef DEBUG
    cout << num[cur] << " " << rest << endl;
#endif
    for (int i = rest/val[cur]; i >= 0; --i) {
        cnt[num[cur]] = i;
        dfs(cur+1, rest-val[cur]*i);
        cnt[num[cur]] = 0;
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1, a; i <= m; ++i) {
        scanf("%d", &a);
        vis[a] = 1;
    }
    if (vis[5]) vis[3] = vis[2] = 0;
    if (vis[3]) vis[2] = 0;
    if (vis[9]) vis[6] = 0;
    dfs(1, n);
    // print();
    return 0;
}
