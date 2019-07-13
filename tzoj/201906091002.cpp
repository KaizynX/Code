#include <bits/stdc++.h>

using namespace std;

int T;
long long n, m, k, l;

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> k >> l;
        if(n < m || k+l > n || n/m*m-k < l) cout << -1 << endl;
        else cout << (k+l)/m + ( (k+l)%m ? 1 : 0 ) << endl;
    }
    return 0;
}
