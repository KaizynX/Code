#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register ll
ll n,s[6],t[4],f[6],ff[6],tot,teacher,bjjjj;
string a,d;
struct did{
    char s[100];
}sn[6],tn[4];
bool operator <(did a,did b)
{
    for(re i=0;i<strlen(a.s)&&i<strlen(b.s);i++)
    {
        if (a.s[i]<b.s[i]) return 1;
        if (a.s[i]>b.s[i]) return 0;
    }
    return strlen(a.s)<strlen(b.s);
}
int main()
{
    scanf("%lld",&n);
    for(re i=1;i<=3;i++) cin>>tn[i].s; 
    for(re i=1;i<=5;i++) cin>>sn[i].s; scanf("\n");
    sort(sn+1,sn+6);
    for(re i=1;i<=n;i++)
    {
        re ans[6];
        getline(cin,a);
        re l=a.length();
        string h="";
        for(re j=l-6;j<l-1;j++)
        h+=a[j];
        if(h=="games")
        {
            string bj1="",bj2="",bj3="";re bjj=-1;
            for(re j=l-14;j<=l-8;j++)
            bj1+=a[j];
            if(bj1=="playing")
            {
                for(re j=l-22;j<=l-16;j++)
                bj2+=a[j];
                if(bj2=="started") bjj=1;
                else if(bj2=="stopped") bjj=0;
                if(bjj>=0)
                {
                    for(re j=0;j<=l-24;j++)
                    bj3+=a[j];
                    for(re j=1;j<=5;j++)
                    if(bj3==sn[j].s)
                    {
                        s[j]=bjj;
                        break;
                    }
                }
            }
        }
        else if(h==" came"||h==" left")
        {           
            string bj="";
            re bjj=0;
            for(re j=0;j<=l-7;j++)
            bj+=a[j];
            for(re j=1;j<=3;j++)
            if(bj==tn[j].s)
            bjj=1;
            if(bjj)
            {
                if(h==" came") teacher=1;
                else teacher=0;
            }
        }
        if(teacher)
        for(re j=1;j<=5;j++)
        if(s[j])
        {
            f[j]=1;
            bjjjj=1;
        }
    }
    for(re i=1;i<=5;i++)
    if(f[i])
    {
        cout<<sn[i].s<<" ";
        tot++;
    }
    if(tot==0) cout<<"How Good Oiers Are!"<<endl;
    else if(tot==5) cout<<endl<<"How Bad Oiers Are!"<<endl;
    return 0;
}
