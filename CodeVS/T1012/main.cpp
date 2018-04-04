#include <iostream>

using namespace std;
int x0,y0;
bool big(int p,int q){
    int time=0,sum=1;
    bool flag=false;
    if(p<q)swap(p,q);
    if(p%q==0&&q!=x0)return false;
    else{
        while(p!=1&&q!=1){
            for(int i=2;i<=q;++i){
                flag=false;
                if(p%i==0&&q%i==0){
                    p/=i;q/=i;
                    sum*=i;
                    flag=true;
                }
            }
            if(flag==false)break;
        }
        if(sum!=x0)return false;//此时的sum为最大公因数
        else{
            sum*=p*q;//此时的sum为最小公倍数
            if(sum==y0)return true;
            else return false;
        }
    }
}
int main()
{
    int p,q,ans=0;
    cin>>x0>>y0;
    for(p=x0;p<=y0;p+=x0){
        for(q=x0;q<=y0;q+=x0){
            if(big(p,q))ans++;
        }
    }
    cout<<ans;
    return 0;
}
