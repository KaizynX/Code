#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e1;

int a, b, c, ans;

int main()
{
    cin >> a >> b >> c;
    if(b >= c) ans = b+c;
    else if(b < c)
    {
        ans += b*2;
        c -= b;
        ans += min(c, a+1);
    }
    cout << ans << endl;
    return 0;
}
