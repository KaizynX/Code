#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#define INF 11
using namespace std;
const int maxq=10000;
map<string,bool> vis;
string bs,es;
string a[10],b[10];
string qs[maxq];
int head,tail,qt[maxq],num,ans=INF;

inline void q_push(string s,int t);
inline void q_pop(string &s,int &t);

void bfs()
{
    string s,ns;
    int t,pos;
    while(head<=tail)
    {
        q_pop(s,t);
        if(s==es)
        {
            ans=min(ans,t);
            return;
        }
        if(t>=10)return;
        for(int i=1;i<=num;++i)
        {
            pos=0;
            while(s.find(a[i],pos)!=s.npos)
            {
                pos=s.find(a[i],pos);
                ns=s;
                ns.replace(pos,a[i].length(),b[i]);
                pos++;
                if(vis[ns])continue;
                q_push(ns,t+1);
                vis[ns]=1;
            }
        }
    }
}

int main()
{
    cin>>bs>>es;
    num=1;
    while(cin>>a[num]>>b[num])
        num++;
    num--;
    q_push(bs,0);
    bfs();
    if(ans>10)printf("NO ANSWER!\n");
    else printf("%d\n",ans);
    return 0;
}

inline void q_push(string s,int t)
{
    qs[tail]=s;
    qt[tail]=t;
    tail++;
}

inline void q_pop(string &s,int &t)
{
    s=qs[head];
    t=qt[head];
    head++;
}
