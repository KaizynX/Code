#include <bits/stdc++.h>

using namespace std;

int n, a, b, c, d, x, sum[2];

int main()
{
    cin >> n >> a >> b >> c >> d >> x;
    for(int i = 1; i <= n; ++i)
    {
        x = (int)((1ll*a*x%d*x%d + 1ll*b*x + c)%d);
        sum[__builtin_parity(x)]++;
    }
    cout << 1ll*sum[0]*sum[1] << endl;
    return 0;
}
