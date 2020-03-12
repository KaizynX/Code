/*
 * @Author: Kaizyn
 * @Date: 2020-03-07 22:56:55
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-12 10:22:20
 * @FilePath: \Code\atcoder\abc158E_3.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int P = 1e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m, p;
long long pw10[N], inv[N];
char s[N];

void exgcd(long long a, long long b, long long &d, long long &x, long long &y)
{
    if (!b) d = a, x = 1, y = 0;
    else exgcd(b, a%b, d, y, x), y -= x*(a/b);
}

inline long long mul_inv(const int &a)
{
    long long d, x, y;
    exgcd(a, p, d, x, y);
    return (x%p+p)%p;
}

long long f(const int &l, const int &r)
{
    if (l == r) return (s[l]-'0')%p == 0;
    int mid = (l+r)>>1;
    long long res = 0, now;
    map<long long, int> mp;
    res += f(l, mid)+f(mid+1, r);
    // i <= mid, j > mid
    // s[i, j] = s[i, mid]*pw10[j-mid]+s[mid+1, j]
    // s[i, j]%p == 0 ==> mul inv by two side
    // s[i, mid]+s[mid+1, j]*inv === 0 %p
    now = 0;
    for (int i = mid+1; i <= r; ++i) {
        now = (now*10+s[i]-'0')%p;
        ++mp[now*inv[i-mid]%p];
    }
    now = 0;
    for (int i = mid; i >= l; --i) {
        now = (pw10[mid-i]*(s[i]-'0')+now)%p;
        res += mp[(p-now)%p];
    }
    return res;
}

int main()
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
    pw10[0] = inv[0] = 1; inv[1] = mul_inv(10);
    for (int i = 1; i <= n; ++i) pw10[i] = pw10[i-1]*10%p;
    for (int i = 2; i <= n; ++i) inv[i] = inv[i-1]*inv[1]%p;
    cout << f(1, n) << endl;
    return 0;
}