#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e6+7;
const int MO = 1e9+7;

int T, n;
long long f[Maxn];

int main()
{
    cin >> T;
    f[1] = f[2] = f[3] = 1;
    for(int i = 4; i < Maxn; ++i)
        f[i] = f[i-1]*(i-1)%MO;
    while(T--)
    {
        cin >> n;
        cout << f[n] << endl;
    }
    return 0;
}
