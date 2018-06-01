#include <iostream>
#include <cstdio>
#define sb "Rua\n"
using namespace std;

const int Maxn = 20+5;

int T,N;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        while(N--)
        {
            printf(sb);
        }
        if(T!=0)putchar('\n');
    }
    return 0;
}
