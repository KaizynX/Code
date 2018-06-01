#include <iostream>
#include <cstring>
using namespace std;
int a[21][21],n,f[21];
string lu[21],lu2[21];

string zhuan(int num)
{
    string fan,ans;
    while(num>0)
    {
        fan+=num%10+'0';
        num/=10;
    }
    for(int i=fan.length()-1;i>=0;i--)
    {
        ans+=fan[i];
    }
    return ans;
}

void fun(int num)
{
    for(int i=1;i<=n;i++)
    {
        if(a[i][num])
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i][j])
                {
                    if(f[i]&&f[j])
                    {
                        //f[i]=min(f[i],a[i][j]+f[j]);
                        if(a[i][j]+f[j]<f[i])
                        {
                            f[i]=a[i][j]+f[j];
                            lu[i]=lu2[i]+" "+lu[j];
                        }
                    }
                    else if(f[j]||num==n)
                    {
                        f[i]=f[j]+a[i][j];
                        lu[i]=lu2[i]+" "+lu[j];
                    }
                    fun(i);
                }
            }
        }
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        lu[i]=zhuan(i);
        lu2[i]=lu[i];
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    fun(10);
    cout<<"minlong="<<f[1]<<endl<<lu[1]<<endl;
    return 0;
}
