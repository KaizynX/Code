#include <bits/stdc++.h>

using namespace std;

int x, y, z, a, b, c;

int main()
{
    cin >> x >> y >> z >> a >> b >> c;
    if(x > a) return puts("NO")&0;
    a -= x;
    if(a+b < y) return puts("NO")&0;
    if(a+b+c-y < z) return puts("NO")&0;
    return puts("YES")&0;
}