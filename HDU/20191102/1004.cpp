#include <bits/stdc++.h>

using namespace std;

int t, n, m, x;

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> m >> x;
        m = min(m, n/2);
        n -= m;
        cout << m << " " << 1ll*n*m*x << endl;
    }
    return 0;
}
