#include <bits/stdc++.h>
using namespace std;
int vis[100000];
void bfs()
{
	queue<int> q;
	q.push(��);
	vis[��]=1; 
	while(!q.empty()) // while(q.size())
	{
		int x = q.front(); // ȡ����
		q.pop(); // �����˳���
		for(����x���ڵ�) {
			if (vis[]û�����) {
				q.push(���ڵ�);
				vis[���һ��]
			}
			
		} 
	}
} 

int main(){
	queue<int> q;
	q.push(1); // ��� 
	q.push(2);
	q.pop();   // ���� 
	q.front(); // ����
	q.back();  // ��β 
	q.size();  // ��С 
	cout<<q.front()<<"\n"; 
	return 0;
} 
