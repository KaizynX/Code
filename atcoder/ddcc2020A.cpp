#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int x, y, res;

int main()
{
    cin >> x >> y;
    if (x == 1) res += 3e5;
    if (x == 2) res += 2e5;
    if (x == 3) res += 1e5;
    if (y == 1) res += 3e5;
    if (y == 2) res += 2e5;
    if (y == 3) res += 1e5;
    if (x == 1 && y == 1) res += 4e5;
    cout << res << endl;
    return 0;
}
