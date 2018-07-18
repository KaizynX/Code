#include <iostream>

using namespace std;
int jiazu[5009];

int baba(int son)
{
    int father=son;
    while(jiazu[father]!=father)father=jiazu[father];
    int i;
    while(jiazu[son]!=father)
    {
        i=jiazu[son];
        jiazu[son]=father;
        son=i;
    }
    return father;
}

void lianjie(int a,int b)
{
    int fa=baba(a),fb=baba(b);
    if(fa!=fb)
    {
        jiazu[fa]=fb;
    }
}

int main()
{
    int n,m,p;
    int a,b;
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++)jiazu[i]=i;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        lianjie(a,b);
    }
    for(int i=0;i<p;i++)
    {
        cin>>a>>b;
        if(baba(a)==baba(b))cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
