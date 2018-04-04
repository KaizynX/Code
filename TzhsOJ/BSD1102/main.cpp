#include <iostream>

using namespace std;
long long a[20005];
int n;

void f1(int cur)//min
{
    long long minn=a[2*cur];
    int min1=2*cur;
    for(int i=2*cur+1;i<n+cur;i++)
    {
        if(minn>a[i])
        {
            minn=a[i];
            min1=i;
        }
    }
    swap(a[min1],a[2*cur]);
}

void f2(int cur)//second min
{
    long long minn=a[2*cur+1];
    int min2=2*cur;
    for(int i=2*cur+2;i<n+cur;i++)
    {
        if(minn>a[i])
        {
            minn=a[i];
            min2=i;
        }
    }
    swap(a[min2],a[2*cur+1]);
}

int main()
{
    long long res=0;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n-1;i++)
    {
        f1(i);
        f2(i);
        a[n+i]=a[2*i]+a[2*i+1];
        res+=a[n+i];
    }
    cout<<res<<endl;
    return 0;
}
