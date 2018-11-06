#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1e4+7;
const int Base1 = 233;
const int Base2 = 257;
const int MOD = 122777;

int n, ans;
string str;
int hash1[MOD], hash2[MOD];

inline int _hash(const string &s, const int Base, const int MO)
{
    int res = 0;
    for(int i = 0; i < s.length(); ++i)
        res = (res*Base+s[i])%MO;
    return res;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> str;
        int val1 = _hash(str, Base1, MOD),
            val2 = _hash(str, Base2, MOD);
        if(!hash1[val1] || !hash2[val2]) ++ans;
        hash1[val1] = hash2[val2] = 1;
    }
    cout << ans << endl;
    return 0;
}
