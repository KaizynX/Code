#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 2e5+7;

string S, T;
int mmps[256], mmpt[256];

int main()
{
    cin >> S >> T;
    if(S.length() != T.length())
    {
        puts("No");
        return 0;
    }
    for(int i = 0; i < S.length(); ++i)
    {
        if(!mmps[S[i]]) mmps[S[i]] = T[i];
        else if(mmps[S[i]] != T[i])
        {
            puts("No");
            return 0;
        }
        if(!mmpt[T[i]]) mmpt[T[i]] = S[i];
        else if(mmpt[T[i]] != S[i])
        {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
