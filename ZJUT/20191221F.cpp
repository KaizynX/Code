#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T, bx, ex, by, ey;

int main()
{
    cin >> T;
    while (T--) {
        cin >> bx >> by >> ex >> ey;
        int dx = abs(bx-by), dy = abs(ex-ey);
        if (bx == ex || by == ey ||
            (dx == 1 && dy != 1) || (dy == 1 && dx != 1) || 
            (dx == 2 && dy > 2) || (dy == 2 && dx > 2)) {
            cout << "Seele" << endl;
        } else {
            cout << "Bronya" << endl;
        }
    }
    return 0;
}
