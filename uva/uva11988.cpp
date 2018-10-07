#include <cstdio>
#include <iostream>

using namespace std;

struct Node
{
	char word;
	Node *pre, *nex;

	Node(){ pre = nullptr; nex = nullptr; }
} ;

void print(Node *cur)
{
	if(cur->pre == nullptr) // head
	{
		delete cur;
		return;
	}
	print(cur->pre);
	putchar(cur->word);
	delete cur;
	return;
}

int main()
{
	string str;

	while(getline(cin, str))
	{
		Node *head = new(Node);
		Node *tail = head;

		Node *cur = tail;
		// (head, tail] head is empty
		// every time we push the new one behind the cur
		for(size_t i = 0; i < str.length(); ++i)
		{
			if(str[i] == '[') cur = head;
			else if(str[i] == ']') cur = tail;
			else
			{
				Node *tmp = new(Node);
				tmp->word = str[i];
				// cur (tmp) nex
				tmp->nex = cur->nex;
				tmp->pre = cur;
				if(cur == tail) tail = tmp;
				else cur->nex->pre = tmp;
				cur->nex = tmp;
				cur = tmp;
			}
		}
		print(tail);
		putchar('\n');
	}
	return 0;
}
