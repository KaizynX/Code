#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=3005;
char mp[N][N];
int up[N][N];
pii st[N];
int top;
 
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",mp[i]+1);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(mp[i][j]=='1'){
                up[i][j]=up[i-1][j]+1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int maxh=-1;
        top=0;
        for(int j=1;j<=m+1;j++){
            // (i-up+1, pos) -> (i, j)
            int pos=j;
            while(top&&st[top].first>up[i][j]){
                // has 0 in [pos, j]
                if (st[top].second<=maxh){
                    ans++;
                }
                pos=st[top].second;
                top--;
            }
            // next line the right 0
            if(!up[i+1][j])maxh=j;
            if(up[i][j]&&(!top||st[top].first<up[i][j]))
                st[++top]={up[i][j],pos};
        }
    }
    printf("%d\n",ans);
    return 0;
}
