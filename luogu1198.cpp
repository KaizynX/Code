#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 2e5 + 7;

long long n, m, mo, t;
pair<bool,long long> q[Maxn];
long long tr[Maxn * 4];

inline long long getint();
void update_tree(long long,long long,long long,long long,long long);
long long query_tree(long long, long long, long long, long long, long long);

int main()
{
	m = getint(); mo = getint();
	for(long long  i = 0,tmp; i < m; ++i)
	{
		char c = getchar(); tmp = getint();
		if(c == 'A') { q[i] = make_pair(true,tmp); ++n; }
		else q[i] = make_pair(false,tmp);
	}
	// build_tree(1,n,1);
	for(long long i = 0, cnt = 0; i < m; ++i)
	{
		if(q[i].first) update_tree(++cnt,(t + q[i].second+mo) % mo,1,n,1);
		else
		{
			if(q[i].second == 0) printf("0\n");
			else printf("%lld\n",t = query_tree(cnt-q[i].second+1,cnt,1,n,1));
		}
	}
	return 0;
}

void update_tree(long long cur,long long v,long long l, long long r,long long i)
{
	if(l == r && l == cur) { tr[i] = v; return; }
	long long mid = (l + r) / 2;
	if(cur <= mid) update_tree(cur,v,l,mid,i*2);
	else update_tree(cur,v,mid+1,r,i*2+1);
	tr[i] = max(tr[i*2],tr[i*2+1]);
}

long long query_tree(long long ql,long long qr,long long l, long long r, long long i)
{
	if(l >= ql && r <= qr) return tr[i];
	long long mid = (l + r) / 2;
	if(qr <= mid) return query_tree(ql,qr,l,mid,i*2);
	else if(ql > mid) return query_tree(ql,qr,mid+1,r,i*2+1);
	else return max(query_tree(ql,qr,l,mid,i*2), query_tree(ql,qr,mid+1,r,i*2+1));
}

inline long long getint()
{
	char c; bool tag = false;
	while((c=getchar()) < '0' || c > '9')if(c == '-') tag = true;
	long long res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = res * 10 + c - '0';
	return tag == true ? -res : res;
}
