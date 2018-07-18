#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

string S, T;

inline size_t max(size_t a, size_t b)
{
    return a < b ? b : a;
}

int main()
{
    cin >> S >> T;
    size_t pos = 0, len = T.length();
    while((pos = S.find(T, 0)) != S.npos)
    {
        S.replace(pos, len, "");
        pos = max(0, pos-len+1);
    }
    cout << S;
    return 0;
}
