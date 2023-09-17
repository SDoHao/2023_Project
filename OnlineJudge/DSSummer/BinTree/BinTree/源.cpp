#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

void PreorderTraversal(BinTree BT); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal(BinTree BT);  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert(BinTree BST, ElementType X);
BinTree Delete(BinTree BST, ElementType X);
Position Find(BinTree BST, ElementType X);
Position FindMin(BinTree BST);
Position FindMax(BinTree BST);

int main()
{
	BinTree BST, MinP, MaxP, Tmp;
	ElementType X;
	int N, i;

	BST = NULL;
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &X);
		BST = Insert(BST, X);
	}
	printf("Preorder:"); //PreorderTraversal(BST); printf("\n");
	MinP = FindMin(BST);
	MaxP = FindMax(BST);
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &X);
		Tmp = Find(BST, X);
		if (Tmp == NULL) printf("%d is not found\n", X);
		else {
			printf("%d is found\n", Tmp->Data);
			if (Tmp == MinP) printf("%d is the smallest key\n", Tmp->Data);
			if (Tmp == MaxP) printf("%d is the largest key\n", Tmp->Data);
		}
	}
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &X);
		BST = Delete(BST, X);
	}
	printf("Inorder:"); //InorderTraversal(BST); printf("\n");
	return 0;
}

Position FindPreNode(BinTree BST, ElementType X,int *LeftRight)
{
	Position tra = BST;
	Position pretra = tra;
	*LeftRight = 0;
	//0 无父亲节点
	//1 父亲节点的左子树
	//2 父亲节点的右子树
	if (tra)
	{
		while (1)
		{
			if (tra->Data > X)
			{
				if (tra->Left)
				{
					*LeftRight = 1;
					pretra = tra;
					tra = tra->Left;
				}	
				else
				{
					*LeftRight = 0;
					return NULL;
				}	
			}
			else if (tra->Data < X)
			{
				if (tra->Right)
				{
					*LeftRight = 2;
					pretra = tra;
					tra = tra->Right;
				}
				else
				{
					*LeftRight = 0;
					return NULL;
				}
			}
			else
				return pretra;
		}
	}
	else
	{
		*LeftRight = 0;
		return tra;
	}
}

Position FindAtPreNode(BinTree PreNode,int dir)
{
	Position Node = PreNode;
	if (dir == 1)
	{
		Node = Node->Left;
	}
	else if (dir == 2)
	{
		Node = Node->Right;
	}
	return Node;
}

Position Find(BinTree BST, ElementType X)
{
	Position Node = BST;
	int dir;
	Node = FindPreNode(Node, X, &dir);
	if (dir == 1)
	{
		Node = Node->Left;
	}
	else if(dir == 2)
	{
		Node = Node->Right;
	}
	return Node;
}


BinTree Insert(BinTree BST, ElementType X)
{
	BinTree T = (BinTree)malloc(sizeof(BinTree));
	BinTree tra;
	T->Data = X;
	T->Left = NULL;
	T->Right = NULL;
	if (BST)
	{
		tra = BST;
		while (tra)
		{
			if (tra->Data > X)
			{
				if (tra->Left)
					tra = tra->Left;
				else
				{
					tra->Left = T;
					break;
				}
			}
			else if (tra->Data < X)
			{
				if (tra->Right)
					tra = tra->Right;
				else
				{
					tra->Right = T;
					break;
				}
			}
		}
	}
	else
		BST = T;
	return BST;
}

Position FindMin(BinTree BST)
{
	Position tra = BST;
	if (tra)
	{
		while (tra->Left)
			tra = tra->Left;
	}

	return tra;
}

Position FindMax(BinTree BST)
{
	Position tra = BST;
	if (tra)
	{
		while (tra->Right)
			tra = tra->Right;
	}
	return tra;
}


void DeleteLeaf(BinTree PreNode,int dir)
{
	Position Node = PreNode;
	if (dir == 1)
	{
		Node = PreNode->Left;
		PreNode->Left = NULL;
	}
	else if (dir == 2)
	{
		Node = PreNode->Right;
		PreNode->Right = NULL;
	}
	//free(Node);
}

void DeleteOneChild(BinTree PreNode, int dir)
{
	Position Node = PreNode;
	if (dir == 1)
	{
		Node = PreNode->Left;
		if(Node->Left)
			PreNode->Left = Node->Left;
		else
			PreNode->Right = Node->Right;
	}
	else if (dir == 2)
	{
		Node = PreNode->Right;
		if (Node->Right)
			PreNode->Right = Node->Right;
		else
			PreNode->Right = Node->Left;
	}
	//free(Node);
}

BinTree Delete(BinTree BST, ElementType X)
{

	int dir;
	BinTree DelNode;
	BinTree LeftMaxNode;
	BinTree PreDelNode;
	BinTree LastDelNode;
	ElementType value;
	if (BST->Left || BST->Right)
	{
		LastDelNode = DelNode = BST;
		value = LastDelNode->Data;
		while (1)
		{
			PreDelNode = FindPreNode(BST, X, &dir);
			DelNode = FindAtPreNode(PreDelNode, dir);//dir为0 DelNode即为PreDelNode，无前驱
			if (DelNode)
			{
				LastDelNode->Data = value;
				if (DelNode->Left && DelNode->Right)
				{
					LeftMaxNode = FindMax(DelNode->Left);
					LastDelNode = DelNode;
					value = X = LeftMaxNode->Data;
					DelNode = LeftMaxNode;
				}
				else if (DelNode->Left || DelNode->Right)
				{
					DeleteOneChild(PreDelNode, dir);
					break;
				}
				else
				{
					DeleteLeaf(PreDelNode, dir);
					break;
				}
			}
			else
				break;	
		}
	}
	else if(BST->Data == X)
		BST = NULL;
	return BST;
}
