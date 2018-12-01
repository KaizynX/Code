#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e1;

int n, k;
long long ans;

int main()
{
    cin >> n >> k;
    ans += 2*n/k + (2*n%k != 0);
    ans += 5*n/k + (5*n%k != 0);
    ans += 8*n/k + (8*n%k != 0);
    cout << ans << endl;
    return 0;
}
