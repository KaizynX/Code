#include <iostream>
#include <cstring>

using namespace std;

const int Maxl = 1e6+7;

string text, pattern;
int len_t, len_p, _next[Maxl];

int main()
{
    cin >> text >> pattern;
    len_t = text.length();
    len_p = pattern.length();
    int k = 0, i = 2, j = 1;
    while(i <= len_p)
    {
        if(!k || pattern[k] == pattern[i-1])
            _next[++i] = ++k;
        else k = _next[k];
    }
    i = 1;
    while(i <= len_t)
    {
        if(!j || text[i-1] == pattern[j-1])
        {
            ++i; ++j;
        }
        else j = _next[j];
        if(j > len_p)
        {
            cout << i-len_p+1 << endl;
            j = _next[j];
        }
    }
    for(i = 1; i <= len_p; ++i)
        cout << _next[i] << " ";
    return 0;
}
