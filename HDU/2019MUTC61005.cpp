#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

struct pp{
    int x,y,z,x1,y1;
}a[2005];

long long mapp[2005][2005], sum[2005][2005];

bool cmp1(pp x,pp y){
    if(x.x==y.x)
      return x.y<y.y;
    return x.x<y.x;
}

bool cmp2(pp x,pp y){
    if(x.y==y.y)
      return x.x<y.x;
    return x.y<y.y;
}

int main(){
    int T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<=n;i++)
          for(int j=0;j<=n;j++)
          {
            mapp[i][j]=0;
            sum[i][j] = 0;
          }
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
        }
        sort(a,a+n,cmp1);
        int now=0;
        int ii=0;
        for(int i=0;i<n;i++){
            if(a[i].x!=now){
                now=a[i].x;
                a[i].x1=++ii;
            }
            else {
                a[i].x1=ii;
            }
        }
        sort(a,a+n,cmp2);
        now=0;
        ii=0;
        for(int i=0;i<n;i++){
            if(a[i].y!=now){
                now=a[i].y;
                a[i].y1=++ii;
            }
            else{
                a[i].y1=ii;
            }
            mapp[a[i].x1][a[i].y1]+=a[i].z;
        } 
        /*for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
              cout<<mapp[i][j]<<" ";
            cout<<endl;  
        }*/
        for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++){
              sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mapp[i][j];
          }
        long long ans=0;
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = i+1; j < n; ++j)
            {
                int lx = a[i].x1, ly = a[i].y1, rx = a[j].x1, ry = a[j].y1;
                if(lx > rx) swap(lx, rx);
                if(ly > ry) swap(ly, ry);
                ans = max(ans, sum[rx][ry]-sum[lx-1][ry]-sum[rx][ly-1]+sum[lx-1][ly-1]);
            }
        }
        printf("%lld\n",ans);               
    }
    return 0;
}
