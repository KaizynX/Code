#include <iostream>

using namespace std;

int main()
{
    int n,len=0,a[5005]={0},b;
    cin>>n;
    while(n--)
    {
        cin>>b;
        if(b>a[len])a[++len]=b;
        else
        {
            for(int i=1;i<=len;i++)
            {
                if(a[i]>b)
                {
                    a[i]=b;
                    break;
                }
            }
        }
    }
    cout<<len<<endl;
    return 0;
}
