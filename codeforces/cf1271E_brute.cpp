#include <bits/stdc++.h>

using namespace std;

long long n, k;
long long res;

int f(int i, int x) {
    while (i) {
        if (i == x) return 1;
        if (i&1) --i;
        else i >>= 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int x = n; x; --x) {
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
            cnt += f(i, x);
        if (cnt >= k) {
            cout << x << endl;
            return 0;
        }
    }
    return 0;
}

