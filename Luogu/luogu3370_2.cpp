#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef unsigned long long ull;

const int Maxn = 1e4+7;
const int Base = 131;
const int Prime =233317; 
const ull Mod = 212370440130137957ll;

int n, ans;
string str;
ull a[Maxn];

inline ull _hash(const string &s)
{
    unsigned long long res = 0;
    for(int i = 0; i < s.length(); ++i)
        res = (res*Base+s[i])%Mod+Prime;
    return res;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> str;
        a[i] = _hash(str);
    }
    sort(a+1, a+n+1);
    cout << unique(a+1, a+n+1)-a-1 << endl;
    return 0;
}
