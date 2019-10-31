#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

long long n, res;

int main()
{
    cin >> n;
    res = n-1;
    for (long long i = 2; i*i <= n; ++i) {
        if (n%i) continue;
        res = min(res, i+n/i-2);
    }
    cout << res << endl;
    return 0;
}
