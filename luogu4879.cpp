#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e5+7;
const int Maxx = 5e5;

// tr[i] the number of girls in city [1, i]
int n, m, has[Maxx+7], tr[Maxx+7];
long long a[Maxx+7], sum;

template <typename T> inline void read(T &x)
{
	char c; T tag = 1;
	while((c=getchar()) < '0' || c > '9') if(c == '-') tag = -1;
	x = c-'0';
	while((c=getchar()) >= '0' && c <= '9')
		x = (x<<1)+(x<<3) + c-'0';
	x *= tag;
}

template <typename T> inline void put(T x)
{
	if(x < 0) { putchar('-'); x = -x; }
	if(x/10) put(x/10);
	putchar(x%10+'0');
}

inline void update(int x, int y)
{
	for( ; x <= Maxx; x += x&-x) tr[x] += y;
}

inline int query(int x)
{
	int res = 0;
	for( ; x; x -= x&-x) res += tr[x];
	return res;
}

int main()
{
	read(n); read(m);
	for(int i = 1; i <= n; ++i)
	{
		read(a[i]);
		has[i] = 1;
		update(i, 1);
		sum += a[i];
	}
	int x, y;
	while(m--)
	{
		char op = getchar();
		while(!(op == 'Q' || op == 'C' || op == 'I' || op == 'D')) op = getchar();
		if(op == 'Q') put(sum), putchar('\n');
		else if(op == 'I')
		{
			read(x); read(y);
			// no girl in city x
			if(!has[x])
			{
				has[x] = true;
				update(x, 1);
				a[x] = y;
				sum += y;
			}
			else // replace the girl
			{
				sum += y-a[x];
				a[x] = y;
			}
		}
		else if(op == 'C')
		{
			read(x); read(y);
			a[x] -= y;
			sum -= y;
		}
		else // op == D
		{
			read(x);
			int l = x, r = Maxx, mid, tmp;
			// find the x'th girl
			while(l < r)
			{
				mid = (l+r)>>1;
				tmp = query(mid);
				if(tmp > x) r = mid-1;
				else if(tmp < x) l = mid+1;
				else r = mid;
			}
			has[l] = 0;
			update(l, -1);
			sum -= a[l];
			a[l] = 0;
		}
	}
	return 0;
}
