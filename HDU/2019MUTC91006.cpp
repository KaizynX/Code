#include<bits/stdc++.h>
using namespace std;

int a[105];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,x;
        scanf("%d",&n);
        int a1=0,a2=0,a3=0,a4=0;//10,20,50,100
        int flag=0;
        for(int i=1;i<=n;i++)
          scanf("%d",&a[i]);
        sort(a+1,a+1+n);  
        for(int i=1;i<=n;i++){
            if(a[i]%10){
                flag=1;
                break;
            }
            int a11=a1,a22=a2,a33=a3,a44=a4;
            if(a[i]>=100){
                int now=a[i]/100;
                a[i]%=100;
                if(a[i]==0&&a1==1&&a2==2&&a3==1){
                    now--;
                }
                a4=max(now,a4);
            }
            if(a[i]==0) continue;
            else{
                if(a[i]==50&&a1==1&&a2==2){
                    continue;
                }
                if(a[i]>=50&&a3==0){
                    a3++;
                    a[i]-=50;
                }
                else if(a[i]>=50&&a3==1){
                    a[i]-=50;
                }
                if(a[i]==40&&a11==2&&a22==1) continue;
                if(a[i]==40&&a22==2) continue; 
                if(a[i]==30&&a11>=1&&a22>=1) continue;
                if(a[i]==20&&a22>=1) continue;
                if(a[i]==20&&a11==2) continue;
                if(a[i]==10&&a11>=1) continue;
                while(a[i]>=20&&a22){
                    a22--;
                    a[i]-=20;
                }
                if(a[i]==20&&a22>=1) continue;
                if(a[i]==20&&a11==2) continue;
                if(a[i]==10&&a11>=1) continue;
                while(a[i]>=20){
                    a[i]-=20;
                    a2++;
                }
                if(a[i]==10&&a11>=1) continue;
                while(a[i]>=10&&a11){
                    a[i]-=10;
                    a11--;
                }
                while(a[i]>=10){
                    a[i]-=10;
                    a1++;
                }
            }
        }
        if(flag==1){
            printf("-1\n");
        }
        else printf("%d\n",a1+a2+a3+a4); 
        printf("%d %d %d %d \n",a1,a2,a3,a4); 
    }
    return 0;
} 
