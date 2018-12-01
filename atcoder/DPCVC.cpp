#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e6+7;
const int Maxq = 80;

int n, Q, k;
int s[Maxn][3];
string S;

int main()
{
    cin >> n >> S >> Q;
    for(int i = 0; i < (int)S.length(); ++i)
    {
        for(int j = 0; j < 3; ++j) s[i+1][j] = s[i][j];
        if(S[i] == 'D') s[i+1][0]++;
        if(S[i] == 'M') s[i+1][1]++;
        if(S[i] == 'C') s[i+1][2]++;
    }
    while(Q--)
    {
        cin >> k;
        long long ans = 0;
        for(int a = 1; a <= (int)S.length()-2; ++a)
            if(S[a-1] == 'D')
                for(int c = a+1; c <= min((int)S.length(), a+k-1); ++c)
                    if(S[c-1] == 'C')
                        ans += (s[c-1][1]-s[a][1]);
        cout << ans << endl;
    }
    return 0;
}
