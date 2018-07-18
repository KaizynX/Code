#include <iostream>
#include <cstring>
#include <cstdio>
 
using namespace std;
 
const int Maxn = 1e6+7;
const int BASE = 131;
 
string a, b;
int len_a, len_b, ans, T;
unsigned long long _hash[Maxn], pattern, base;
 
int main()
{
    cin >> T;
    while(T--)
    {
        ans = 0;
        base = 1;
        pattern = 0;
        cin >> a >> b;
        len_a = a.length();
        len_b = b.length();
        // base = BASE^len_a
        for(int i = 0; i < len_a; ++i)
            base *= BASE;
        for(int i = 1; i <= len_a; ++i)
            pattern = pattern*BASE + a[i-1];
        for(int i = 1; i <= len_b; ++i)
            _hash[i] = _hash[i-1]*BASE + b[i-1];
        for(int i = len_a; i <= len_b; ++i)
            if(pattern == _hash[i] - _hash[i-len_a]*base)
                ++ans;
        printf("%d\n", ans);
    }
    return 0;
}
