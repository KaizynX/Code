#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct node{
    int x,y,t;
};
int n,m;
int mx[]={0,1,0,-1};
int my[]={1,0,-1,0};//右，下，左，上
char map[30][30];
int d[30][30];
int tx,ty,sx,sy;
node ft;
int judge(int x,int y){
    if(x<0||x>=n||y<0||y>=m){
        return 0;
    }
    if(d[x][y]){
        return 0;
    }
    if(map[x][y]=='*'){
        return 0;
    }
    return 1;
}
void bfs(){
    queue<node> q;
    ft.x=sx;
    ft.y=sy;
    ft.t=0;
    q.push(ft);
    d[sx][sy]=1;
    while(!q.empty()){
        node ff=q.front();
        q.pop();
        int x=ff.x;
        int y=ff.y;
        if(map[x][y]=='T'){
            printf("%d\n",ff.t);
            return;
        }
        for(int i=0;i<4;i++){
            x=ff.x+mx[i];
            y=ff.y+my[i];
            if(!judge(x,y)){
                continue;
            }
            node nt;
            if(map[x][y]=='.'||map[x][y]=='T'){//正常走
                nt.x=x;
                nt.y=y;
                nt.t=ff.t+1;
                d[nt.x][nt.y]=1;
                q.push(nt);
                continue;
            }else if(i==0||i==2){//右和左
                if(map[x][y]=='-'&&ff.t%2==0){//可以过去
                    nt.x=x+mx[i];
                    nt.y=y+my[i];
                    if(judge(nt.x,nt.y)){
                        nt.t=ff.t+1;
                        d[nt.x][nt.y]=1;
                        q.push(nt);
                    }
                }else if(map[x][y]=='|'&&ff.t%2!=0){
                    nt.x=x+mx[i];
                    nt.y=y+my[i];
                    if(judge(nt.x,nt.y)){
                        nt.t=ff.t+1;
                        d[nt.x][nt.y]=1;
                        q.push(nt);
                    }
                }else {//不能过楼梯，得等一分钟
                    nt.x=ff.x;
                    nt.y=ff.y;
                    nt.t=ff.t+1;
                    d[nt.x][nt.y]=1;
                    q.push(nt);
                }
            }else{//上和下
                if(map[x][y]=='|'&&ff.t%2==0){//可以过去
                    nt.x=x+mx[i];
                    nt.y=y+my[i];
                    if(judge(nt.x,nt.y)){
                        nt.t=ff.t+1;
                        d[nt.x][nt.y]=1;
                        q.push(nt);
                    }
                }else if(map[x][y]=='-'&&ff.t%2!=0){
                    nt.x=x+mx[i];
                    nt.y=y+my[i];
                    if(judge(nt.x,nt.y)){
                        nt.t=ff.t+1;
                        d[nt.x][nt.y]=1;
                        q.push(nt);
                    }
                }else {//不能过楼梯，得等一分钟
                    nt.x=ff.x;
                    nt.y=ff.y;
                    nt.t=ff.t+1;
                    d[nt.x][nt.y]=1;
                    q.push(nt);
                }
            }
        }
    }
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        memset(d,0,sizeof(d));
        for(int i=0;i<n;i++){
            scanf("%s",map[i]);
            for(int j=0;j<m;j++){
                if(map[i][j]=='S'){
                    sx=i,sy=j;
                }
            }
        }
        bfs();
    }
    return 0;
}
