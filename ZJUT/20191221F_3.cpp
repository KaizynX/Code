#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T, bx, ex, by, ey;

int main()
{
    cin >> T;
    while (T--) {
        cin >> bx >> by >> ex >> ey;
        int dx = abs(bx-ex), dy = abs(by-ey);
        cout << (dx+dy == 0 || dx != dy ? "Seele" : "Bronya") << endl;
    }
    return 0;
}
