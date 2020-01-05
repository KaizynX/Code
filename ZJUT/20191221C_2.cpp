#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T, d, h, f, n, x, y;

inline double calc(int d, int h, int f) {
    return 1.0*d*h/(h+f);
}

int main()
{
    cin >> T;
    while (T--) {
        cin >> d >> h >> f >> n >> x >> y;
        double fx = calc(d+n*x, h, f),
               fy = calc(d, h+n*y, f);
        if (fx >= fy) cout << n << " 0" << endl;
        else cout << "0 " << n << endl;
    }
    return 0;
}

