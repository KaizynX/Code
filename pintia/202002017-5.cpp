#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long res = 0, base = 1;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        base *= i;
        res += base;
    }
    cout << res << endl;
    return 0;
}
