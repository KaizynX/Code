#include<bits/stdc++.h>
using namespace std;
#define fuck(x) cout<<#x<<"     "<<x<<endl;
char s[3][10];
int cnt[1000];
int a[10];
set<int>ss;
struct node
{
    int ch,val;
     node(int ch=0,int val=0)
    {
        this->ch=ch;
        this->val=val;
    }
     friend bool operator<(const node&mm,const node&gg)
    {
        if(mm.ch!=gg.ch)
            return mm.ch<gg.ch;
        else
            return mm.val<gg.val;
    }
}mmp[10];
int main()
{
    cin>>s[0]>>s[1]>>s[2];
    if(s[0][1]==s[1][1]&&s[0][1]==s[2][1])
    {
        a[0]=s[0][0]-'0';
        a[1]=s[1][0]-'0';
        a[2]=s[2][0]-'0';
        sort(a,a+3);
        if(a[0]==a[2]||(a[0]+1==a[1]&&a[1]+1==a[2]))
        {
            cout<<0<<endl;
            return 0;
        }
        if(a[0]==a[1]||a[1]==a[2]||a[1]-a[0]==1||a[2]-a[1]==1||a[2]-a[1]==2||a[1]-a[0]==2)
        {
            cout<<1<<endl;
            return 0;
        }
        cout<<2<<endl;
        return 0;
    }
    ss.insert(s[0][1]);
    ss.insert(s[1][1]);
    ss.insert(s[2][1]);
    if(ss.size()==3)
        cout<<2<<endl;
    else
    {
        mmp[0]=node(s[0][1],s[0][0]-'0');
        mmp[1]=node(s[1][1],s[1][0]-'0');
        mmp[2]=node(s[2][1],s[2][0]-'0');
        sort(mmp,mmp+3);
        if(mmp[0].ch==mmp[1].ch)
        {
            if(mmp[0].val==mmp[1].val||mmp[1].val-mmp[0].val==1||mmp[1].val-mmp[0].val==2)
                cout<<1<<endl;
            else
                cout<<2<<endl;
        }
        else
        {
            if(mmp[1].val==mmp[2].val||mmp[2].val-mmp[1].val==1||mmp[2].val-mmp[1].val==2)
                cout<<1<<endl;
            else
                cout<<2<<endl;
        }
    }
    return 0;
}
