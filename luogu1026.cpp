#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define DEBUG

using namespace std;

const int Maxl = 207;
const int Maxk = 50;
const int Maxs = 10;

int k, n, len[Maxs], f[Maxl][Maxl][Maxk];
string str, s[Maxs];

inline void read()
{
    int line;
    string tmp;
    cin >> line >> k;
    len[0] = line*20;
    while(line--)
    {
        cin >> tmp;
        str += tmp;
    }
    // len[0] = str.length()
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> s[i];
}

inline void init()
{
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(i == j) continue;
            if(s[i].find(s[j]) == 0)
            {
                swap(s[i], s[n]);
                --n;
                --i;
                break;
            }
        }
    }
    for(int i = 1; i <= n; ++i)
        len[i] = s[i].length();
    for(int i = 1, l, r; i <= n; ++i)
    {
        l = 0;
        while((l = str.find(s[i], l)) != str.npos)
        {
            r = l + len[i];
            ++l;
#ifdef DEBUG
            printf("%d %d %d\n", i, l ,r);
#endif
            for(int i2 = 1; i2 <= l; ++i2)
                for(int i3 = r; i3 <= len[0]; ++i3)
                    f[i2][i3][1]++;
        }
    }
}

inline void dp()
{
    for(int ki = 2; ki <= k; ++ki)
    {
        for(int i = ki; i <= len[0]; ++i)
        {
            for(int l = 1, r; l <= len[0]-i+1; ++l)
            {
                r = l+i-1;
                for(int j = l; j < r; ++j)
                {
                    if(j-l+1 >= ki-1) f[l][r][ki] = max(f[l][r][ki], f[l][j][ki-1]+f[j+1][r][1]);
                    if(r-j >= ki-1)   f[l][r][ki] = max(f[l][r][ki], f[l][j][1]+f[j+1][r][ki-1]);
                }
            }
        }
    }
}

int main()
{
    read();
    init();
    dp();
    cout << f[1][len[0]][k] << endl;
}
