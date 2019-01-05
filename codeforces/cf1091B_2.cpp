#include <bits/stdc++.h>

using namespace std;

int n, x, y;
long long ansx, ansy;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> x >> y;
        ansx += x;
        ansy += y;
    }
    for(int i = 1; i <= n; ++i)
    {
        cin >> x >> y;
        ansx += x;
        ansy += y;
    }
    cout << ansx/n << " " << ansy/n << endl;
    return 0;
}
