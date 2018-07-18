#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxn=10;
const int maxl=25;
string A,B;
char a[maxn][maxl],b[maxn][maxl];
int ans,k;
queue<string>q;

void bfs(int sum,int step)
{
    if(step>10)
    {
        ans=step;
        return;
    }
    string now,then;
    int i,j,resum=0,f;
    for(i=0;i<sum;++i)
    {
        now=q.front();
        q.pop();
        for(j=0;j<k;++j)
        {
            f=now.find(a[j]);
            while(f!=now.npos)
            {
                then=now;
                then.replace(f,strlen(a[j]),b[j]);
                if(then==B)
                {
                    ans=step;
                    return;
                }
                q.push(then);
                resum++;
                f=now.find(a[j],f+1);
            }
        }
    }
    bfs(resum,step+1);
}

int main()
{
    cin>>A>>B;
    while(cin>>a[k])
    {
        cin>>b[k];
        k++;
    }
    q.push(A);
    bfs(1,1);
    if(ans>10)cout<<"NO ANSWER!";
    else cout<<ans;
    cout<<endl;
    return 0;
}
