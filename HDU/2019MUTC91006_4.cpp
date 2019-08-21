#include <bits/stdc++.h>

using namespace std;

const int kN = 1e2+7;
const int INF = 1e8;

int T, n;
int a[kN], ii[5];
unsigned int dp[25][15][10][5];

void dfs(int cur, unsigned int num)
{
    // cout << (bitset<31>)num << endl;
    if (cur >= 4) {
        dp[ii[0]][ii[1]][ii[2]][ii[3]] = num;
        return;
    }
    int m, b;
    unsigned int nex = num;
    if (cur == 0) m = 20, b = 1;
    else if (cur == 1) m = 10, b = 2;
    else if (cur == 2) m = 4, b = 5;
    else m = 1, b = 10;
    for (int j = 0; j <= m; ++j) {
        ii[cur] = j;
        dfs(cur+1, nex);
        // dfs(cur+1, num|(num<<(j*b)));
        nex |= nex<<b;
    }
}

int main()
{
    scanf("%d", &T);
    dfs(0, 1);
    while (T--) {
        int flag = 0,  max1 = 0, max10 = 0, res1 = INF, res10 = INF;
        int maxv = 0;
        unsigned need1 = 0, need10 = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a+i);
            if (a[i]%10) {
                flag = 1;
            } else {
                a[i] /= 10;
                maxv = max(a[i], maxv);
                if (a[i] < 10) {
                    need1 |= 1<<a[i];
                } else {
                    need1 |= 1<<(a[i]%10);
                    max1 = max(max1, a[i]/10);
                }
            }
        }
        if (flag) {
            printf("-1\n");
            continue;
        }
        if (maxv >= 10)
        for (int i = 1; i <= n; ++i) {
            if (a[i] >= maxv-maxv%10) {
                need10 |= 1<<(a[i]%10+10);
                max10 = max(max10, a[i]/10-1);
            } else {
                need10 |= 1<<(a[i]%10);
            }
        }
        if (need1 > 1)
        for (int i1 = 0; i1 <= 10; ++i1)
            for (int i2 = 0; i2 <= 5; ++i2)
                for (int i5 = 0; i5 <= 2; ++i5)
                    if ((dp[i1][i2][i5][0]&need1) == need1)
                        res1 = min(res1, i1+i2+i5);
        if (maxv >= 10 && need10 > 1)
        for (int i1 = 0; i1 <= 20; ++i1)
            for (int i2 = 0; i2 <= 10; ++i2)
                for (int i5 = 0; i5 <= 4; ++i5)
                    for (int i10 = 0; i10 <= 1; ++i10)
                        if ((dp[i1][i2][i5][i10]&need10) == need10)
                            res10 = min(res10, i1+i2+i5+i10);
        int ans = min(max10+res10, max1+res1);
        res1 = INF;
        if (maxv >= 10 && maxv%10 == 0) {
            need1 |= 1<<10;
            for (int i1 = 0; i1 <= 10; ++i1)
                for (int i2 = 0; i2 <= 5; ++i2)
                    for (int i5 = 0; i5 <= 2; ++i5)
                        if ((dp[i1][i2][i5][0]&need1) == need1)
                            res1 = min(res1, i1+i2+i5+0);
            ans = min(ans , res1+maxv/10-1);
        }
        printf("%d\n", ans);
        // cout << (bitset<30>)need1 << endl;
        // cout << (bitset<30>)need10 << endl;
    }
    return 0;
}
