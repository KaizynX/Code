#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    char c=getchar();
    int cnt=0;
    while(c!='@')
    {
        if(c=='(')cnt++;
        if(c==')')
        {
            if(cnt==0)
            {
                printf("NO\n");
                return 0;
            }
            cnt--;
        }
        c=getchar();
    }
    if(cnt==0)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}
