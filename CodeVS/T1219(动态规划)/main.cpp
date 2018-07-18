#include <iostream>

using namespace std;
int f[51][51];
int main()
{
    int n,m,x1,x2,y1,y2;
    cin>>n>>m>>x1>>y1>>x2>>y2;
    f[x1][y1]=1;
    for(int i=x1;i<=x2;++i)
        for(int j=1;j<=m;++j)
        {
            if(i-1>=1)
            {
                if(j+2<=m)f[i][j]+=f[i-1][j+2];
                if(j-2>=1)f[i][j]+=f[i-1][j-2];
            }
            if(i-2>=1)
            {
                if(j+1<=m)f[i][j]+=f[i-2][j+1];
                if(j-1>=1)f[i][j]+=f[i-2][j-1];
            }
        }
    cout<<f[x2][y2]<<endl;
    return 0;
}
