#include <iostream>
//false???
using namespace std;
int s;
bool T1544(int a){
    int b[15],c[15],i,j,sum=1,judge=0;
    bool flag=true;
    for(i=2;i<=10;i++){
        if(judge>=2)return true;
        for(j=1;j<=14;j++){
            sum*=i;
            if(sum>a){
                j--;
                sum/=i;
                break;
            }
        }
        for(int k=1;k<=j+1;k++){
            b[k]=a/sum;
            c[j+2-k]=b[k];
            a-=b[k]*sum;
            sum/=i;
        }
        sum=1;
        for(int k=j+1;k>=1;k--){
            if(b[k]!=c[k]){
                flag=false;
                break;
            }
        }
        if(flag)judge++;
        flag=true;
        a=s;
    }
    if(judge>=2)return true;
    else return false;
}
int main()
{
    int n;
    cin>>n>>s;
    int a[n+1];
    int i=1;
    while(s++){
        if(i>n)break;
        if(T1544(s)){
            a[i]=s;
            i++;
        }
    }
    for(int j=1;j<=n;j++){
        cout<<a[j]<<endl;
    }
    return 0;
}
