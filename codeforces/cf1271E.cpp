#include <bits/stdc++.h>

using namespace std;

long long n, k;
long long res;

inline long long f(int i) {
    return (1ll<<i)-1+n%(1ll<<(i+1));
}

inline long long calc(long long x)
{
    if (x > n) return 0;
    if (x == 0) return 0;
    int i = 0;
    long long tmp = x;
    while ((x<<1) <= n) x <<= 1, ++i;
    return tmp == n>>i ? (1ll<<i)-1+n%(1ll<<(i+1)) : (1ll<<(i+1))-1;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    if (k == 1) {
        cout << n << endl;
        return 0;
    }
    int i = 1;
    while (f(i) < k) ++i;
    res = n>>i;

    int j = i-1;
    long long x = (n>>j)-1-((n>>j)%2 == 0);
    if (calc(x)+calc(x+1) >= k)
        res = max(res, (n>>j)-1-((n>>j)%2 == 0));
    cout << res << endl;
    return 0;
}
