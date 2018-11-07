#include <bits/stdc++.h>

using namespace std;

long long n, ans;

int main()
{
    cin >> n;
    for(long long i = 1; i <= n; ++i)
        for(long long j = 1; j <= n; ++j)
            if(i*j/__gcd(i, j) == n) ++ans;
    cout << ans << endl;
    return 0;
}
