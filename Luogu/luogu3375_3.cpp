#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int Maxn = 1e6+7;

char a[Maxn], b[Maxn];
int len_a, len_b, _next[Maxn];

int main()
{
    cin >> a+1 >> b+1;
    len_a = strlen(a+1);
    len_b = strlen(b+1);
    for(int i = 2, k = 0; i <= len_b; ++i)
    {
        while(k && b[k+1] != b[i]) k = _next[k];
        if(b[k+1] == b[i]) ++k;
        _next[i] = k;
    }
    for(int i = 1, j = 0; i <= len_a; ++i)
    {
        while(j && a[i] != b[j+1]) j = _next[j];
        if(b[j+1] == a[i]) ++j;
        if(j == len_b)
        {
            cout << i-len_b+1 << endl;
            j = _next[j];
        }
    }
    for(int i = 1; i <= len_b; ++i)
        cout << _next[i] << " ";
    return 0;
}
