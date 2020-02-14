#include <bits/stdc++.h>

using namespace std;

const int N = 5e4+7;
const int INF = 1e9;

int n;

int main()
{
    cin >> n;
    int minx = INF, maxx = -INF, miny = INF, maxy = -INF;
    for (int i = 1, x, y; i <= n; ++i) {
        cin >> x >> y;
        minx = min(minx, x+y);
        maxx = max(maxx, x+y);
        miny = min(miny, x-y);
        maxy = max(maxy, x-y);
    }
    cout << max(maxx-minx, maxy-miny) << endl;
    return 0;
}
