#include <bits/stdc++.h>

using namespace std;

int n, m, gcd;
int ln, lm;
long long lcm;
string S, T;

int main()
{
    cin >> n >> m;
    cin >> S >> T;
    gcd = __gcd(n, m);
    lcm = 1ll*n/gcd*m;
    ln = m/gcd; lm = n/gcd;
    for(int i = 0; i < gcd; ++i)
    {
        if(S[i*lm] != T[i*ln])
            return puts("-1")&0;
    }
    cout << lcm << endl;
    return 0;
}
