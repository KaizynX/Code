#include <bits/stdc++.h>
using namespace std;
char a[30], b[]="abcdefghijklmnopqrstuvwxyz";
int main()
{
    scanf("%s",a);
    int i;
    for(i=0;a[i]!='\0';++i)
        if(a[i]!=b[i])break;
    printf("%d\n",i);
    return 0;
}
