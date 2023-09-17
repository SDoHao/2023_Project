#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<map>
using namespace std;

typedef struct List * pList;
struct List
{
	int Addr;
	int Data;
	int Next;
};

int main()
{
	int StAddr;
	int i, j, N, K;
	int addr = -1, data, addr_next;
	int res_st_addr;
	pList p;
	map<int, pList> MapList;
	bool NotAtTail = true;
	cin >> StAddr >> N >> K;
	for (i = 0; i < N; i++)
	{
		p = new struct List;
		cin >> addr >> data >> addr_next;
		p->Addr = addr;
		p->Data = data;
		p->Next = addr_next;
		MapList[addr] = p;
	}
	p = MapList[StAddr];
	i = 1;
	if (N == 1)
	{
		res_st_addr = StAddr;
	}
	else
	{
		while (i < K)
		{
			i++;
			p = MapList[p->Next];
		}
		res_st_addr = p->Addr;
		int count = 0;
		p = MapList[StAddr];
		while (1)
		{
			count++;
			if (p->Next == -1)break;
			p = MapList[p->Next];

		}
		int temp_addr;
		pList head, pre_tail, temp_p, next_p;
		temp_p = MapList[StAddr];
		pre_tail = temp_p;
		if (N - count / K * K != 0)
		{
			for (i = 0; i < count / K; i += 1)
			{
				head = temp_p;
				next_p = MapList[head->Next];
				for (j = 0; j < K - 1; j++)
				{
					temp_addr = temp_p->Addr;
					addr_next = next_p->Next;
					next_p->Next = temp_addr;
					temp_p = next_p;
					next_p = MapList[addr_next];
				}
				pre_tail->Next = next_p->Addr;
				pre_tail = head;
			}
		}
		else
		{
			pList pre, head, pre_head;
			pre = MapList[StAddr];
			pre_head = pre;
			for (i = 0; i < N / K; i += 1)
			{
				head = pre;
				p = MapList[pre->Next];
				for (j = 0; j < K; j++)
				{
					addr = pre->Addr;
					addr_next = p->Next;
					p->Next = addr;
					pre = p;
					if (addr_next == -1)
					{
						pre_head->Next = p->Addr;
						head->Next = -1;
						NotAtTail = false;
						break;
					}
					else
						p = MapList[addr_next];

				}
				if (NotAtTail)
				{
					head->Next = pre->Addr;
					pre->Next = addr_next;
					pre_head = head;
				}
			}
		}
	}

	p = MapList[res_st_addr];
	while (1)
	{
		printf("%05d %d ", p->Addr, p->Data);
		if (p->Next != -1)
			printf("%05d\n", p->Next);
		else
			printf("-1\n");
		if (p->Next == -1)break;
		p = MapList[p->Next];
	}
	return 0;
}