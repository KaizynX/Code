#include <bits/stdc++.h>

using namespace std;

long long n, m;
int q;

long long gcd(long long a, long long b)
{
    return b ? gcd(b, a%b) : a;
}

int main()
{
    cin >> n >> m >> q;
    long long gg = gcd(n, m), sy, ey;
    long long dd[3];
    dd[1] = n/gg;
    dd[2] = m/gg;
    for(int i = 1, sx, ex; i <= q; ++i) {
        cin >> sx >> sy >> ex >> ey;
        cout << ((sy-1)/dd[sx] == (ey-1)/dd[ex] ? "YES" : "NO") << endl;
    }
    return 0;
}
