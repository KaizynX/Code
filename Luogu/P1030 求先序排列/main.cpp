#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

string mid,nex;
int a[100];

void solve(int sm,int tm,int sn,int tn,int i)
{
    if(sm>tm || sn>tn)return;
    a[i]=nex[tn];
    if(sm==tm || sn==tn)return;
    int pos=mid.find(a[i]);
    solve(sm,pos-1,sn,sn+pos-sm-1,i*2);
    solve(pos+1,tm,sn+pos-sm,tn-1,i*2+1);
}

void print(int i)
{
    if(a[i]==0)return;
    putchar(a[i]);
    print(i*2);
    print(i*2+1);
}

int main()
{
    int len;
    cin>>mid>>nex;
    len=mid.length()-1;
    solve(0,len,0,len,1);
    print(1);
    return 0;
}
