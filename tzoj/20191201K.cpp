#include <bits/stdc++.h>

using namespace std;

long long d;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> d) {
        long long res = 0;
        for (long long i = 1; i*i <= d; ++i) {
            if (d%i) continue;
            long long k = d/i;
            if (k >= 3) res += k-3+1;
            if (k == i) continue;
            if (i >= 3) res += i-3+1;
        }
        cout << res << endl;
    }
    return 0;
}

