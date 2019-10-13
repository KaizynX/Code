#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int b, g, n;

int main()
{
    cin >> b >> g >> n;
    if (b > g) swap(b, g);
    // b <= g
    int res = min(b, n)-max(n-g, 0)+1;
    cout << res << endl;
    // cout << min(min(b, g), n)+1 << endl;
    return 0;
}
