#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1e6+7;

int len1, len2;
int nex[Maxn];
char s1[Maxn], s2[Maxn];

inline void GetNext(const char *str, int *_next)
{
    int len = strlen(str+1);
    for(int i = 2, j = 0; i <= len; ++i)
    {
        while(j && str[i] != str[j+1]) j = _next[j];
        if(str[i] == str[j+1]) j++;
        _next[i] = j;
    }
}

int main()
{
    scanf("%s%s", s1+1, s2+1);
    len1 = strlen(s1+1);
    len2 = strlen(s2+1);
    GetNext(s2, nex);
    for(int i = 1, j = 0; i <= len1; ++i)
    {
        while(j && s1[i] != s2[j+1]) j = nex[j];
        if(s1[i] == s2[j+1]) j++;
        if(j == len2)
        {
            cout << i-j+1 << endl;
            j = nex[j];
        }
    }
    for(int i = 1; i <= len2; ++i)
        cout << nex[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}