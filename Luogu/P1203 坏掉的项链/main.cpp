#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=350+5;

int n,ans;
string s;

int main()
{
    int l,r,last;
    cin>>n>>s;
    s=s+s+s;
    for(int i=n;i<2*n;++i)
    {
        l=0;r=0;
        //left
        last=0;
        for(int j=i-1;j>=0;--j)
        {
            if(s[j]=='w')l++;
            else
            {
                if(last==s[j])l++;
                else if(last==0)
                {
                    last=s[j];
                    l++;
                }
                else break;
            }
        }
        //right
        last=0;
        for(int j=i;j<s.length();++j)
        {
            if(s[j]=='w')r++;
            else
            {
                if(last==s[j])r++;
                else if(last==0)
                {
                    last=s[j];
                    r++;
                }
                else break;
            }
        }

        if(l+r>ans)
            ans=l+r;
    }
    if(ans>n)ans=n;
    cout<<ans;
    return 0;
}
