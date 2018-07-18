#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char c[10];

int main()
{
    int p1,p2,p3,pre,nex,len,i=0,flag,flag2;
    string s;
    scanf("%d%d%d",&p1,&p2,&p3);
    cin>>s;
    len=s.length();
    while(i<len)
    {
        if(s[i]!='-')
        {
            i++;
            continue;
        }
        pre=s[i-1];
        nex=s[i+1];
        if(pre==nex)
        {
            i+=2;
            continue;
        }
        else if(pre+1==nex)
        {
            s.replace(i,1,"");
            i++;
            len--;
            continue;
        }
        else if(pre>nex)
        {
            i+=2;
            continue;
        }
        else
        {
            if(pre>='a'&&pre<='z')flag=0;
            else if(pre>='A'&&pre<='Z')flag=1;
            else if(pre>='0'&&pre<='9')flag=2;
            if(nex>='a'&&nex<='z')flag2=0;
            else if(nex>='A'&&nex<='Z')flag2=1;
            else if(nex>='0'&&nex<='9')flag2=2;
            if(flag!=flag2)
            {
                i+=2;
                continue;
            }

            if(p3==2)
            {
                s.replace(i,1,"");
                for(char j=pre+1;j<nex;++j)
                {
                    for(int k=0;k<p2;++k)
                    {
                        if(p1==3)c[k]='*';
                        else if(flag==2 || flag==0&&p1==1 || flag==1&&p1==2)c[k]=j;
                        else if(flag==0&&p1==2)c[k]=j-'a'+'A';
                        else if(flag==1&&p1==1)c[j]=j-'A'+'a';
                    }
                    s.replace(i,0,c);
                }
                len+=(nex-pre-1)*p2+1;
                i+=(nex-pre-1)*p2;
            }
            else if(p3==1)
            {
                s.replace(i,1,"");
                for(char j=nex-1;j>pre;--j)
                {
                    for(int k=0;k<p2;++k)
                    {
                        if(p1==3)c[k]='*';
                        else if(flag==2 || flag==0&&p1==1 || flag==1&&p1==2)c[k]=j;
                        else if(flag==0&&p1==2)c[k]=j-'a'+'A';
                        else if(flag==1&&p1==1)c[j]=j-'A'+'a';
                    }
                    s.replace(i,0,c);
                }
                len+=nex-pre;
                i+=nex-pre;
            }
        }
    }
    cout<<s<<endl;
    return 0;
}
