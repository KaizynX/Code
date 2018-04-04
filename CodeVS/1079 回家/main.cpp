#include <iostream>
#include <queue>
#define A 'A'
using namespace std;
const int maxp=10005;
const int maxa=58+10;//a to Z
const int maxl=0x7fffffff;
int P,e[maxa][maxa],dis[maxa];
bool vis[maxa];
struct Node
{
    int x,v;
    bool operator < (const Node & b)const
    {
        return v>b.v;//small
    }
}f;
priority_queue <Node> q;//big
int main()
{
    int i,l,next,minx,minl=maxl;
    char a,b;
    cin>>P;
    for(i=0;i<P;++i)
    {
        cin>>a>>b>>l;
        if(!e[a-A][b-A])
        {
            e[a-A][b-A]=l;
            e[b-A][a-A]=l;
        }
        else
        {
            e[a-A][b-A]=min(e[a-A][b-A],l);
            e[b-A][a-A]=min(e[b-A][a-A],l);
        }
    }
    for(i=0;i<58;++i)
        dis[i]=maxl;
    dis['Z'-A]=0;
    f.x=('Z'-A);
    f.v=0;
    q.push(f);
    //Dijistra
    while(!q.empty())
    {
        f=q.top();
        q.pop();
        next=f.x;
        vis[next]=1;
        for(i=0;i<58;++i)
            if(e[next][i]&&!vis[i])
                if(dis[next]+e[next][i]<dis[i])
                {
                    dis[i]=dis[next]+e[next][i];
                    f.x=i;
                    f.v=dis[i];
                    q.push(f);
                    if(i<('a'-A)&&dis[i]<minl)
                    {
                        minl=dis[i];
                        minx=i;
                    }
                }
    }
    a=minx+A;
    cout<<a<<" "<<minl<<endl;
    return 0;
}
