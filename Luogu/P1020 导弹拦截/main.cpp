#include <iostream>
#include <cstdio>

using namespace std;

const int maxn=100000+5;

int a;
int up[maxn],down[maxn],fu,fd;

int s_up(int i,int j,int a)
{
    if(i==j)
    {
        return i;
    }
    int mid=(i+j)/2;
    if(a<up[mid])
        return s_up(i,mid,a);
    else if(a>up[mid])
        return s_up(mid+1,j,a);
    else return mid;
}

int s_down(int i,int j,int a)
{
    if(i==j)
    {
        return i;
    }
    int mid=(i+j)/2;
    if(a<down[mid])
        return s_down(mid+1,j,a);
    else if(a>down[mid])
        return s_down(i,mid,a);
    else return mid;
}

void f_up(int a)//find a smaller
{
    int pos=s_up(1,fu,a);
    if(a==up[pos])
    {
        while(a==up[pos])pos++;
        up[pos]=a;
        if(pos>fu)
            fu=pos;
    }
    else if(a>=up[pos])
    {
        up[++pos]=a;
        if(pos>fu)
            fu=pos;
    }
    else if(a<up[pos])
    {
        up[pos]=a;
    }
}

void f_down(int a)//find a bigger
{
    int pos=s_down(1,fd,a);
    if(a==down[pos])
    {
        while(a==down[pos])pos++;
        down[pos]=a;
        if(pos>fd)
            fd=pos;
    }
    else if(a<=down[pos])
    {
        down[++pos]=a;
        if(pos>fd)
            fd=pos;
    }
    else if(a>down[pos])
    {
        down[pos]=a;
    }
}

int main()
{
    scanf("%d",&a);
    up[++fu]=a;
    down[++fd]=a;
    while(scanf("%d",&a)==1)
    {
        f_up(a);
        f_down(a);
    }
    printf("%d\n%d\n",fd,fu);
    for(int i=1;i<=fd;++i)//
        printf("%d ",down[i]);
    putchar('\n');
    for(int i=1;i<=fu;++i)//
        printf("%d ",up[i]);
    return 0;
}
