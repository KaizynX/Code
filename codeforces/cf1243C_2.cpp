#include <bits/stdc++.h>

using namespace std;

int cnt;
long long n, p;

int main()
{
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (long long i = 2; i*i <= n; ++i) {
        if (n%i) continue;
        p = i;
        if (++cnt > 1) {
            cout << 1 << endl;
            return 0;
        }
        while (n%i == 0) n /= i;
    }
    if (n > 1) ++cnt, p = n;
    if (cnt > 1) cout << 1 << endl;
    else cout << p << endl;
    return 0;
}
