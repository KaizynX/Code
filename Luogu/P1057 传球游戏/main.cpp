#include <iostream>
using namespace std;
const int maxn=30+5;

int n,m;
int a[maxn][maxn];

int main()
{
    cin>>n>>m;
    a[0][0]=1;
    for(int i=1;i<=m;++i)
    {
        for(int j=0;j<n;++j)
        {
            a[j][i]=a[(j+1)%n][i-1]+a[(j-1+n)%n][i-1];
        }
    }
    cout<<a[0][m];
    return 0;
}
