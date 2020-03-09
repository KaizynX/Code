/*
 * @Author: Kaizyn
 * @Date: 2020-03-08 14:26:20
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-08 14:32:49
 * @FilePath: \Code\HDU\hdu1788.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 20;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, aa;
int a[N], m[N];

void exgcd(int a, int b, int &x, int &y)
{
    if (!b) x = 1, y = 0;
    else exgcd(b, a%b, y, x), y -= a/b*x;
}

inline int mul_inverse(const int &a, const int &m)
{
    int x, y;
    exgcd(a, m, x, y);
    return (x%m+m)%m;
}

inline int CRT(int a[], int m[])
{
    int res = 0, M = 1;
    for (int i = 1; i <= n; ++i)
        M *= m[i];
    for (int i = 1; i <= n; ++i)
        res = (res + a[i]*(M/m[i])*mul_inverse(M/m[i], m[i]))%M;
    return (res+M)%M;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n >> aa && n|aa) {
        for (int i = 1; i <= n; ++i) {
            cin >> m[i];
            a[i] = m[i]-aa;
        }
        cout << CRT(a, m) << endl;
    }
    return 0;
}