#include<iostream>  
#include<cstdio>  
#include<algorithm>  
#include<cmath>  
using namespace std;  
long long f[6000];  
long long c[6000];  
int cnt=0;  
int n;  
long long a[6000];  
int main(){  
    scanf("%d",&n);  
    int i,j;  
    for(i=1;i<=n;i++){  
        scanf("%d",&a[i]);  
    }  
    int max1=0;  
    for(i=1;i<=n;i++){  
        for(j=1;j<i;j++) if(a[i]<a[j] && f[i]<f[j]+1)f[i]=f[j];  
        f[j]++;  
        if(f[j]==1)c[j]=1;  
        for(j=1;j<i;j++){  
            if(a[i]<a[j] && f[i]==f[j]+1){  
                c[i]+=c[j];   
            }  
            else if(a[i]==a[j] && f[i]==f[j]) c[j]=0;  
        }  
        if(f[i]>max1)max1=f[i];  
    }  
    for(i=1;i<=n;i++){  
        if(f[i]==max1)cnt+=c[i];  
    }  
    printf("%d %d",max1,cnt);  
    return 0;  
}  
