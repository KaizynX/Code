#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n, d, e, res;

int main()
{
    cin >> n >> d >> e;
    e *= 5;
    res = n;
    for (int i = 0; i*d <= n; ++i) {
        res = min(res, (n-i*d)%e);
    }
    cout << res << endl;
    return 0;
}
