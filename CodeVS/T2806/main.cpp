#include <iostream>
#include <cstring>
using namespace std;
const int maxn=20;
char c[maxn][maxn];
int w,h,ans;
int visit[maxn][maxn];

int sou(int i,int j)
{
    if(i<0||i>=h||j<0||j>=w)return 0;
    if(c[i][j]!='.'||visit[i][j]!=0)return 0;
    ans++;
    visit[i][j]++;
    sou(i-1,j);
    sou(i,j-1);
    sou(i+1,j);
    sou(i,j+1);
    return 0;
}

int main()
{
    while(cin>>w &&cin>>h&&w&&h)
    {
        ans=0;
        int mi,mj;
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++)
            {
                cin>>c[i][j];
                if(c[i][j]=='@')
                {
                    c[i][j]='.';
                    mi=i;
                    mj=j;
                }
            }
        memset(visit,0,sizeof(visit));
        sou(mi,mj);
        cout<<ans<<endl;
    }
    return 0;
}
