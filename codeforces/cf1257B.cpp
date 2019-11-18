#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int t, x, y;

int main()
{
    cin >> t;
    while (t--) {
        cin >> x >> y;
        if (x > 3 || y <= x || (x == 2 && y == 3)) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}
