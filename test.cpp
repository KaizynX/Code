/*
 * @Author: Kaizyn
 * @Date: 2020-03-03 16:51:41
 * @LastEditTime: 2020-12-11 20:59:34
 */
#include<bits/stdc++.h>
using namespace std;
#define see(x) cout<<#x<<"="<<x<<endl
typedef long long ll;

const int N=3e5+10;
#define int ll
ll n,a,b,H[N];
void solve(ll n,ll a,ll b) {
    ll ans=0;
    ll dao=1;
    priority_queue<int> q;
    for(int i=1;i<=n;i++) scanf("%lld",&H[i]);
    for(int i=1;i<=n;i++) {
        int now=0;
        int c=(H[i]-1)/b;
        int A=c+1;
        now=c;
        H[i]-=c*b;
        c=(H[i]-1)/a+1;
        int B=now-c;
        if(dao+B>=0){
            q.push(A-B);
            ans++;
            dao+=B;
        }
        else if(!q.empty() && dao+q.top()+B>=0){
            dao+=q.top()+B;
            q.pop();
            q.push(A-B);
        }
        else dao+=A;
    }
    cout<<ans<<endl;
}

signed main() {
    while(~scanf("%lld%lld%lld",&n,&a,&b)) solve(n,a,b);
}