#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e6+7;
const int Maxq = 80;

int n, Q, k;
int sm[Maxn], sc[Maxn];
long long sp[Maxn];
string S;

int main()
{
    cin >> n >> S >> Q;
    for(int i = 0; i < n; ++i)
    {
        sm[i+1] = sm[i]+(S[i] == 'M');
        sc[i+1] = sc[i]+(S[i] == 'C');
        sp[i+1] = sp[i]+(S[i] == 'C' ? sm[i+1]: 0);
    }
    while(Q--)
    {
        cin >> k;
        long long ans = 0;
        for(int a = 1; a <= n-2; ++a)
            if(S[a-1] == 'D')
                ans += (sp[min(n, a+k-1)]-sp[a]
                        -1ll*sm[a]*(sc[min(n, a+k-1)]-sc[a]));
        cout << ans << endl;
    }
    return 0;
}
