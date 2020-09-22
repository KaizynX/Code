/*
 * @Author: Kaizyn
 * @Date: 2020-03-03 16:51:41
 * @LastEditTime: 2020-09-20 15:19:14
 */
#include<bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)

int A, B, K, W;
long long dp[31][2][2][2][2][2];
// dp[][x==A][y==B][abs(x-y)==K][x^y==W][x==y]

void solve() {
    scanf("%d%d%d%d", &A, &B, &K, &W);
    long long res = 0;
    // x >= y
    memset(dp, 0, sizeof dp);
    dp[30][1][1][1][1][1] = 1;
    for(int i = 29; i >= 0; --i) {
        int a = (A>>i)&1;
        int b = (B>>i)&1;
        int k = (K>>i)&1;
        int w = (W>>i)&1;
        repeat(i0,0,2)
        repeat(i1,0,2)
        repeat(i2,0,2)
        repeat(i3,0,2)
        repeat(i4,0,2)
        repeat(x,0,2)
        repeat(y,0,2) {
            if (i0 && x > a) continue;
            if (i1 && y > b) continue;
            if (i2 && x-y > k) continue;
            if (i3 && (x^y) > w) continue;
            if (i4 && x < y) continue;
            dp[i][i0&(x==a)][i1&(y==b)][i2&(x-y==k)][i3&((x^y)==w)][i4&(x==y)]
                += dp[i+1][i0][i1][i2][i3][i4];
        }
    }
    repeat(i0,0,2)
    repeat(i1,0,2)
    repeat(i2,0,2)
    repeat(i3,0,2)
    repeat(i4,0,2)
        res += dp[0][i0][i1][i2][i3][i4];
    // x < y
    memset(dp, 0, sizeof dp);
    dp[30][1][1][1][1][1] = 1;
    for(int i = 29; i >= 0; --i) {
        int a = (A>>i)&1;
        int b = (B>>i)&1;
        int k = (K>>i)&1;
        int w = (W>>i)&1;
        repeat(i0,0,2)
        repeat(i1,0,2)
        repeat(i2,0,2)
        repeat(i3,0,2)
        repeat(i4,0,2)
        repeat(x,0,2)
        repeat(y,0,2) {
            if (i0 && x > a) continue;
            if (i1 && y > b) continue;
            if (i2 && y-x > k) continue;
            if (i3 && (x^y) > w) continue;
            if (i4 && x > y) continue;
            dp[i][i0&(x==a)][i1&(y==b)][i2&(y-x==k)][i3&((x^y)==w)][i4&(x==y)]
                += dp[i+1][i0][i1][i2][i3][i4];
        }
    }
    repeat(i0,0,2)
    repeat(i1,0,2)
    repeat(i2,0,2)
    repeat(i3,0,2)
        res += dp[0][i0][i1][i2][i3][0];

    printf("%lld\n", res);
}

int main() {
    int cas;scanf("%d", &cas);
    while(cas--) solve();
}