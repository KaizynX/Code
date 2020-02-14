#include<bits/stdc++.h>
using namespace std;

int mapp[1005][1005];
int v[1005][1005];
int dic[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m,d,k;

struct pp{
    int x,y,step;
};
void bfs(int x,int y){
    queue<pp>q;
    pp cur,nex;
    int ans=0;
    cur.x=x;
    cur.y=y;
    cur.step=0;
    q.push(cur);
    while(!q.empty()){
        cur=q.front();
        q.pop();
        ans+=min(k,mapp[cur.x][cur.y]);
        mapp[cur.x][cur.y]-=min(k,mapp[cur.x][cur.y]);
        for(int i=0;i<4;i++){
            nex.x=cur.x+dic[i][0];
            nex.y=cur.y+dic[i][1];
            nex.step=cur.step+1;
            if(nex.x<1||nex.x>m||nex.y<1||nex.y>m) continue;
            if(v[nex.x][nex.y]) continue;
            if(nex.step>d) continue;
            v[nex.x][nex.y]=1;
            q.push(nex);
        }
    }
    printf("%d\n",ans);
}

int main(){
    scanf("%d%d%d%d",&n,&m,&d,&k);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&mapp[i][j]);
        }
    }
    while(n--){
        int x,y;
        scanf("%d%d",&x,&y);
        memset(v,0,sizeof(v));
        v[x][y]=1;
        bfs(x,y);
    }
    system("pause");
    return 0;
}
