#include<iostream>                   //���˵��������
using namespace std;
int ch[17][2];
int width[1000];                     //������¼ÿһ��Ŀ��
int x=0,deep=0,height=0;             //deep������¼��ǰ�߶ȣ�height������¼���߶�
void dfs(int i,int deep)
{
    if(deep>height)
        height=deep;
    width[deep]++;                   //ÿһ��dfs˵����������
    if(ch[i][0])dfs(ch[i][0],deep+1);//����������dfs
    if(ch[i][1])dfs(ch[i][1],deep+1);//������Ҷ���dfs
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>ch[i][0]>>ch[i][1];
    dfs(1,1);                         //��1,1���ڵ㿪ʼ
    for(int i=1;i<=1000;i++){         //Ѱ�������
        if(width[i]>x)
            x=width[i];
    }
    cout<<x<<" "<<height;
}
