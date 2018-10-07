#include <iostream>
#include <cstdio>
 
using namespace std;
 
const int Maxn = 4e5+7;
const int P = 131;
 
string str;
unsigned long long base[Maxn] = {1}, _hash[Maxn];
 
int main()
{
    while(cin >> str)
    {
        int len = str.length();
        for(int i = 1; i <= len; ++i)
        {
            base[i] = base[i-1] * P;
            _hash[i] = _hash[i-1]*P + str[i-1]-'a'+1;
        }
        for(int i = 1; i <= len; ++i)
            if(_hash[i] == _hash[len] - _hash[len-i]*base[i])
                printf("%d ", i);
        putchar('\n');
    }
    return 0;
}
