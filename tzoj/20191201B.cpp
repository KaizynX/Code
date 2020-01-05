#include <bits/stdc++.h>

using namespace std;

int sx, sy, ex, ey;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> sx >> sy >> ex >> ey) {
        int x = abs(ex-sx), y = abs(ey-sy);
        if (x > y) swap(x, y);
        if (x == 1 && y == 2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}

