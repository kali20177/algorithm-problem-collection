#include <iostream>
using namespace std;

struct Node
{
	Node(int x)
	{
		val = x;
		next = 0;
	}
	int val;
	Node *next;
};

int getListLen(Node *head)
{
	Node *slow = head;
	Node *fast = head;

	while (fast && fast -> next)
	{
		slow = slow -> next;
		fast = fast -> next -> next;
		if (fast == slow)
			break;
	}

	if (fast == NULL || fast -> next == NULL)   //无环
	{
		int len = 0;
		Node *p = head;
		while (p)
		{
			len ++;
			p = p -> next;
		}

		return len;
	}
	
	else
	{
		int len1 = 0, len2 = 0;
		Node *p1 = slow;
		Node *p2 = head;

		while (p1)
		{
			len1 ++;
			p1 = p1 -> next;
			p2 = p2 -> next;
			if (p1 == p2)
				break;
		}

		while (slow)
		{
			len2 ++;
			slow = slow -> next;
			if (slow == fast)
				break;
		}
		cout << "loop len: " << len2 << endl;
		cout << "linked list len: " << len1 + len2 << endl;
	}
		return 0;
}

int main()
{
	Node *p1 = new Node(1);
	Node *p2 = new Node(2);
	Node *p3 = new Node(3);
	Node *p4 = new Node(4);
	Node *p5 = new Node(5);
	Node *p6 = new Node(6);

	p1 -> next = p2;
	p2 -> next = p3;
	p3 -> next = p4;
	p4 -> next = p5;
	p5 -> next = p6;
	p6 -> next = p3;

	cout << getListLen(p1) << endl;

	return 0;
}
