#include <iostream>
#include <string>
using namespace std;
int a1[505],b1[505],c[505];
int main()
{
    string a,b;
    int l,flag=0;
    cin>>a>>b;
    for(int i=0;i<a.length();i++){
        a1[i]=a[a.length()-i-1]-'0';
    }
    for(int i=0;i<b.length();i++){
        b1[i]=b[b.length()-i-1]-'0';
    }
    l=a.length();
    if(a.length()<b.length())l=b.length();
    for(int i=0;i<l;i++){
        c[i]+=a1[i]+b1[i];
        if(i==l-1&&c[i]>=10){
            c[i]=c[i]%10;
            c[i+1]++;
            flag++;
        }
        if(c[i]>=10){
            c[i]=c[i]%10;
            c[i+1]++;
        }
    }
    bool zero=true;
    if(flag){
        for(int i=l;i>=0;i--){
            if(i==0){
                cout<<c[i];
                break;
            }
            if(c[i]==0&&zero){
                continue;
            }else zero=false;
            cout<<c[i];
        }
    }else{
        for(int i=l-1;i>=0;i--){
            if(i==0){
                cout<<c[i];
                break;
            }
            if(c[i]==0&&zero){
                continue;
            }else zero=false;
            cout<<c[i];
        }
    }
    return 0;
}
