#include <bits/stdc++.h>

using namespace std;

string a, b;

int main()
{
    cin >> a >> b;
    int lena = a.length(),
        lenb = b.length();
    for(int i = 0; i <= lena-lenb; ++i)
    {
        bitset<lenb> tmp(a.substr(i));
    }
    return 0;
}
