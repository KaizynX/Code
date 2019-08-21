#include <bits/stdc++.h>

using namespace std;

const int kN = 1e2+7;
const int INF = 1e8;

int T, n;
int a[kN], ii[5];
unsigned int dp[25][15][10][5];

void dfs(int cur, unsigned int num)
{
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
        nex |= nex<<b;
    }
}

void brute(int cur, unsigned int need10, int &res, const int maxa, int flag)
{
    if (cur >= 20) {
        if (!flag)
            for (int i1 = 0; i1 <= 20; ++i1)
                for (int i2 = 0; i2 <= 10; ++i2)
                    for (int i5 = 0; i5 <= 4; ++i5)
                        for (int i10 = 0; i10 <= 1; ++i10)
                            if ((need10&dp[i1][i2][i5][i10]) == need10)
                                res = min(res, i1+i2+i5+i10+maxa/10-1);    
        return;
    }
    if (need10&(1<<cur)) {
        brute(cur+1, need10^(1<<cur)|(1<<(cur-10)), res, maxa, flag&1);
        brute(cur+1, need10, res, maxa, 0);
    } else {
        brute(cur+1, need10, res, maxa, 1);
    }
}

int main()
{
    scanf("%d", &T);
    dfs(0, 1);
    while (T--) {
        int flag = 0, maxa = 0, res = INF;
        unsigned int need1 = 0, need10 = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a+i);
            if (a[i]%10) {
                flag = 1;
            } else {
                a[i] /= 10;
                maxa = max(maxa, a[i]);
                need1 |= 1<<(a[i]%10);
            }
        }
        if (flag) {
            printf("-1\n");
            continue;
        }
        if (maxa >= 10) {
            for (int i = 1; i <= n; ++i) {
                if (a[i] < maxa-maxa%10) {
                    need10 |= 1<<(a[i]%10);
                }
            }
            for (int i = 1; i <= n; ++i) {
                if (a[i] >= maxa-maxa%10) {
                    need10 |= 1<<(a[i]%10+10);
                }
            }
        }
        for (int i1 = 0; i1 <= 10; ++i1)
            for (int i2 = 0; i2 <= 5; ++i2)
                for (int i5 = 0; i5 <= 2; ++i5)
                    if ((need1&dp[i1][i2][i5][0]) == need1)
                        res = min(res, i1+i2+i5+maxa/10);
        if (maxa >= 10) {
            brute(11, need10, res, maxa, 1);
        }
        if (maxa >= 10)
            for (int i1 = 0; i1 <= 20; ++i1)
                for (int i2 = 0; i2 <= 10; ++i2)
                    for (int i5 = 0; i5 <= 4; ++i5)
                        for (int i10 = 0; i10 <= 1; ++i10)
                            if ((need10&dp[i1][i2][i5][i10]) == need10)
                                res = min(res, i1+i2+i5+i10+maxa/10-1);
        printf("%d\n", res);
        // cout << (bitset<30>)need10 << endl;
    }
    return 0;
}
