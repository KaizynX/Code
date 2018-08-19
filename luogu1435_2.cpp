#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1e3+7;

string A, B;
int len, f[Maxn][Maxn];

int main()
{
    cin >> A;
    B = A;
    len = A.length();
    reverse(B.begin(), B.end());
    for(int i = 1; i <= len; ++i)
        for(int j = 1; j <= len; ++j)
            if(A[i-1] == B[j-1]) f[i][j] = f[i-1][j-1]+1;
            else f[i][j] = max(f[i-1][j], f[i][j-1]);
    printf("%d\n", len-f[len][len]);
    return 0;
}
