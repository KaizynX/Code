#include <iostream>

using namespace std;

int main()
{
    char a[1000];
    int i=1,s=0,ans=0;
    while(cin>>a[0]){
        a[i]=a[0];
        if(a[i]=='K'){
            ++s;
            ans=max(s,ans);
        }else{
            s=0;
        }
        ++i;
    }
    if(ans==1||ans==0||ans==2)cout<<"You are a Foolish Man";
    else if(ans==3)cout<<"You are on a Killing Spree";
    else if(ans==4)cout<<"You are Dominating";
    else if(ans==5)cout<<"You have a Mega-Kill";
    else if(ans==6)cout<<"You are Unstoppable";
    else if(ans==7)cout<<"You are Wicked Sick";
    else if(ans==8)cout<<"You have a M-m-m-m....Monster Kill";
    else if(ans==9)cout<<"You are Godlike";
    else if(ans>=10)cout<<"You are Beyond Godlike (Somebody kill him!)";
    return 0;
}
