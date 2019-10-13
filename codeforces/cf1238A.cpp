#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int t;
long long x, y;

int main()
{
    cin >> t;
    while (t--) {
        cin >> x >> y;
        cout << (x-y <= 1 ? "NO" : "YES") << endl;
    }
    return 0;
}
