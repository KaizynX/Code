#include <iostream>

using namespace std;

int main()
{
    int n,a[61][61],b[61][61];
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            cin>>a[i][j];
            b[i][j]=a[i][j];
        }
    }
    for(int i=n-1;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            b[i][j]+=max(b[i+1][j],b[i+1][j+1]);
        }
    }
    cout<<b[1][1]<<endl;
    cout<<a[1][1]<<"-";
    int j=1;
    for(int i=2;i<=n;i++)
    {
        if(b[i][j]>b[i][j+1])
        {
            cout<<a[i][j];
        }
        else
        {
            cout<<a[i][j+1];
            j++;
        }
        if(i!=n)cout<<"-";
    }
    return 0;
}
