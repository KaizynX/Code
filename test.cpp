/*                         _
                        _ooOoo_
                       o8888888o
                       88" . "88
                       (| -_- |)
                  .'  \\|     |//  `.
                 /  \\|||  :  |||//  \
                /  _||||| -:- |||||_  \
                |   | \\\  -  /'| |   |
                | \_|  `\`---'//  |_/ |
                \  .-\__ `-. -'__/-.  /
              ___`. .'  /--.--\  `. .'___
           ."" '<  `.___\_<|>_/___.' _> \"".
          | | :  `- \`. ;`. _/; .'/ /  .' ; |
          \  \ `-.   \_\_`. _.'_/_/  -' _.' /
===========`-.`___`-.__\ \___  /__.-'_.'_.-'================

                  Please give me AC.
*/
#include<bits/stdc++.h>
using namespace std;
#define mem(a) memset(a,0,sizeof(a))
#define rep(i,a,n) for(i=a;i<=n;i++)
#define reb(i,n,a) for(i=n;i>=a;i--)
#define INF (~(1<<31))
#define Min 1e-6
#define lowbit(x) ((x)&(-x))
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define all(v) (v).begin(),(v).end()
#define dbg(x,y) cout<<x<<" = "<<y<< endl;
#define fi first
#define se second
#define ls rt<<1
#define rs rt<<1|1
#define ll long long
#define int ll
typedef vector<int> vi;
typedef pair<int,int> pii;
inline int read() {int x=0,f=1;char c=getchar();while(c!='-'&&(c<'0'||c>'9'))c=getchar();if(c=='-')f=-1,c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return f*x;}

const int N = 2e2 + 7;
const int M = 1e9 + 7;
const ll MAXN = 1e18 +7;
const ll Mod = 998244353;

int _,i,j,k,n,m,t,T,p,s,x,y,z,d,l,r,h,len,o,u,v,w,st,en,sx,sy,ma,mi,th,mod,num,flag,ans,mid,cnt,now,nex,tmp;
int vis[N];
double a[N][N],c[N];
vector<pii> g;
char ch;
string s1,s2,s3;

int bfs()
{
    mem(vis);
    queue<int> q;
    q.push(st),vis[st]=1;
    while(!q.empty()){
        tmp=q.front(),q.pop();
        for(i = 0;i < g.size();i++){
            nex=(tmp+g[i].fi)%mod;
            if(!vis[nex]) vis[nex]=1,q.push(nex);
        }
    }
    return (vis[en]||vis[(mod-en)%mod]);
}

signed main()
{
    ios::sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while(T--){
        cin >> n >> m >> en >> st >> d;
        if(d==1) st=2*n-2-st;
        mod=2*(n-1);
        mem(a),mem(c);
        g.clear();
        for(i = 1;i <= m;i++){
            u=read();
            if(u) g.pb(pii(i,u));
        }
        if(st==en){
            printf("0.00\n");
            continue;
        }
        if(n==1){
            printf("Impossible !\n");
            continue;
        }
        if(!bfs()) printf("Impossible !\n");
        else{
            for(i = 0;i < mod;i++){
                if(!vis[i]) continue;
                a[i][i]=1;
                for(j = 0;j < g.size();j++){
                    v=(i+g[j].fi)%mod;
                    c[i]+=(1.0*g[j].fi*g[j].se/100);
                    if(v!=en&&v!=(mod-en)%mod) a[i][v]-=(1.0*g[j].se/100);
                }
                if(fabs(a[i][i])<Min) c[i]=0;
            }
            for(i = 0;i < mod;i++) a[en][i]=a[i][en]=0;
            if(en!=0&&en!=n-1){
                for(i = 0;i < mod;i++) a[mod-en][i]=a[i][mod-en]=0;
            }
            c[(mod-en)%mod]=c[en]=0;
//            for(i = 0;i < mod;i++){
//                for(j = 0;j < mod;j++) printf("%.2f ",a[i][j]);
//                printf("%.2f\n",c[i]);
//            }
            for(i = 0;i < mod;i++){
                if(fabs(a[i][i])<Min) continue;
                for(j = 0;j < mod;j++){
                    if(i==j) continue;
                    if(fabs(a[j][i])>Min){
                        double b=a[j][i]/a[i][i];
                        for(k = 0;k < mod;k++){
                            a[j][k]=a[j][k]-a[i][k]*b;
                        }
                        c[j]=c[j]-c[i]*b;
                    }
                }
            }
//            for(i = 0;i < mod;i++){
//                for(j = 0;j < mod;j++) printf("%.2f ",a[i][j]);
//                printf("%.2f\n",c[i]);
//            }
            if(fabs(a[st][st])<Min){
                printf("Impossible !\n");
                continue;
            }
            printf("%.2f\n",c[st]/a[st][st]);
        }
    }
    return 0;
}