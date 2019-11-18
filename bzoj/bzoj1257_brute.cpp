#include <bits/stdc++.h>

using namespace std;

int n, k;
long long res;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        res += k%i;
    }
    cout << res << endl;
    return 0;
}
