/*
 * @Author: Kaizyn
 * @Date: 2020-03-12 10:12:16
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-12 10:32:54
 * @FilePath: \Code\atcoder\abc158E_4.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int P = 1e4+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, p;
int cnt[P], val[N];
char s[N];

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> p >> (s+1);
    if (p == 2 || p == 5) {
        long long res = 0;
        for (int i = n; i; --i) {
            if ((s[i]-'0')%p == 0) res += i;
        }
        cout << res << endl;
        return 0;
    }
    // s[i, j] === 0 %p
    // (s[i, n]-s[j+1, n])/10^(n-j+1) === 0 %p
    // s[i, n] === s[j+1, n] %p
    long long res = 0;
    for (int i = n, cur = 0, base = 1; i; --i) {
        ++cnt[cur];
        cur = (cur+(s[i]-'0')*base)%p;
        res += cnt[cur];
        base = base*10%p;
    }
    cout << res << endl;
    return 0;
}