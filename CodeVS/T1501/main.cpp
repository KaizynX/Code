#include<iostream>                   //别人的拿来理解
using namespace std;
int ch[17][2];
int width[1000];                     //用来记录每一层的宽度
int x=0,deep=0,height=0;             //deep用来记录当前高度，height用来记录最大高度
void dfs(int i,int deep)
{
    if(deep>height)
        height=deep;
    width[deep]++;                   //每一次dfs说明往下移了
    if(ch[i][0])dfs(ch[i][0],deep+1);//如果有左儿子dfs
    if(ch[i][1])dfs(ch[i][1],deep+1);//如果有右儿子dfs
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>ch[i][0]>>ch[i][1];
    dfs(1,1);                         //从1,1根节点开始
    for(int i=1;i<=1000;i++){         //寻找最大宽度
        if(width[i]>x)
            x=width[i];
    }
    cout<<x<<" "<<height;
}
