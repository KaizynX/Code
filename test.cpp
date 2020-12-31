#include <bits/stdc++.h>
using namespace std;
int vis[100000];
void bfs()
{
	queue<int> q;
	q.push(点);
	vis[点]=1; 
	while(!q.empty()) // while(q.size())
	{
		int x = q.front(); // 取队首
		q.pop(); // 别忘了出队
		for(所有x相邻点) {
			if (vis[]没被标记) {
				q.push(相邻点);
				vis[标记一下]
			}
			
		} 
	}
} 

int main(){
	queue<int> q;
	q.push(1); // 入队 
	q.push(2);
	q.pop();   // 出队 
	q.front(); // 队首
	q.back();  // 队尾 
	q.size();  // 大小 
	cout<<q.front()<<"\n"; 
	return 0;
} 
