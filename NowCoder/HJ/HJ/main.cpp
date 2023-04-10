//HJ51
#include <iostream>
using namespace std;

class ListNode
{
public:
	int m_nKey;
	ListNode* m_pNext;
	ListNode(int a) :m_nKey(a)
	{
		m_pNext = nullptr;
	}
};

void Insert(ListNode &list, int a)
{
	auto * plist = new ListNode(a);
	ListNode * t = &list;
	ListNode * pre = t;
	if (a <= list.m_nKey)
	{
		plist->m_nKey = list.m_nKey;
		list.m_nKey = a;
		plist->m_pNext = list.m_pNext;
		list.m_pNext = plist;
	}
	else
	{
		while (t)
		{
			if (t->m_nKey >= a)
				break;
			pre = t;
			t = t->m_pNext;
		}
		pre->m_pNext = plist;
		plist->m_pNext = t;
	}
}

void Print(ListNode &list)
{
	ListNode * t = &list;
	while (t)
	{
		cout << t->m_nKey << ' ';
		t = t->m_pNext;
	}
}

int main()
{
	int n, a, i;
	while (cin >> n)
	{
		cin >> a;
		i = n;
		ListNode List(a);
		ListNode *t;
		while (--i>0)
		{
			cin >> a;
			Insert(List, a);
		}
		cin >> a;
		t = &List;
		Print(List);
		if (n != 1 && a != 1)
		{
			while (a-->0)
			{
				t = t->m_pNext;
			}
		}
		cout << t->m_nKey << endl;
	}
	return 0;
}