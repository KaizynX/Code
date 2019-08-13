#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>
#include<vector>
using namespace std;

const long long mod=998244353;
long long a[25];
int b[25];
int vis[25];


int main(){
    int T,n,k;
    scanf("%d",&T);
    a[0]=1;
    a[1]=1;
    for(int i=2;i<=20;i++){
        a[i]=a[i-1]*i;
    }
    while(T--){
        scanf("%d%d",&n,&k);
        int cnt=0;
        for(int i=1;i<=n;i++)
          vis[i]=0;
        int f=(k-1)/a[n-1];
        k=k%a[n-1];
        b[cnt++]=n-f;
        vis[n-f]=1;  
        int num=n-1;  
        while(cnt<n){
            f=(k-1)/a[num-1];
            int p=0;
            if(k!=0){
              for(int i=1;i<=n;i++){
                if(vis[i]==0){
                    p++;
                    if(p==f+1){
                        vis[i]=1;
                        b[cnt++]=i;
                        break;
                    }    
                }
            }     
            }
            else {
                for(int i=n;i>=1;i--){
                    if(vis[i]==0){
                        b[cnt++]=i;
                        vis[i]=1;
                    }
                }
            }    
            k=k%a[num-1];
            num--;
        }    
        for(int i=0;i<cnt-1;i++){
            printf("%d ",b[i]);
        }
        printf("%d\n",b[cnt-1]);         
    }      
    return 0;
}
