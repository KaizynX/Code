#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    char a[100009];
    int l=0,r=0,num=0,i=0;
    while(char b=getchar())
    {
        if(b=='E')break;
        if(b!=' ')
        a[i++]=b;
    }
    for(int j=0;j<i;j++)
    {
        if(a[j]=='W')
        {
            l++;
            num++;
        }
        if(a[j]=='L')
        {
            r++;
            num++;
        }
        if((l>=11||r>=11)&&(l-r>=2||r-l>=2))
        {
            printf("%d:%d\n",l,r);
            l=0;
            r=0;
            num=0;
        }
    }
    printf("%d:%d\n",l,r);
    l=0;r=0;
    printf("\n");
    for(int j=0;j<i;j++)
    {
        if(a[j]=='W')
        {
            l++;
            num++;
        }
        if(a[j]=='L')
        {
            r++;
            num++;
        }
        if((l>=21||r>=21)&&(l-r>=2||r-l>=2))
        {
            printf("%d:%d\n",l,r);
            l=0;
            r=0;
            num=0;
        }
    }
    printf("%d:%d\n",l,r);
    return 0;
}
