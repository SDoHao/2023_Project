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

BinTree Insert(BinTree BST, ElementType X)
{
	BinTree T = (BinTree)malloc(sizeof(BinTree));
	BinTree temp;
	T->Data = X;
	T->Left = NULL;
	T->Right = NULL;
	if (BST)
	{
		temp = BST;
		while (temp)
		{
			if (X > temp->Data)
			{ 
				if (temp->Right)
					temp = temp->Right;
				else
				{
					temp->Right = T;
					break;
				}
					
			}
			else if (X < temp->Data)
			{
				if (temp->Left)
					temp = temp->Left;
				else
				{
					temp->Left = T;
					break;
				}
					
			}
		}
	}
	else
		BST = T;
	return BST;
}

Position Find(BinTree BST, ElementType X)
{
	Position Temp = BST;
	if (BST)
	{
		while (Temp)
		{
			if (Temp->Data > X)
			{
				Temp = Temp->Left;
			}
			else if (Temp->Data < X)
			{
				Temp = Temp->Right;
			}
			else
				break;
		}
	}
	return Temp;
}


Position FindParent(BinTree BST, ElementType X, int *LeftRight)
{
	Position tra = BST;
	Position partra = NULL;
	*LeftRight = 0;
	//0 无父亲节点
	//1 父亲节点的左子树
	//2 父亲节点的右子树
	if (tra)
	{
		while (tra->Data != X)
		{
			if (tra->Data > X)
			{
				if (tra->Left)
				{
					*LeftRight = 1;
					partra = tra;
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
					partra = tra;
					tra = tra->Right;
				}
				else
				{
					*LeftRight = 0;
					return NULL;
				}

			}		
		}
	}
	else
	{
		*LeftRight = 0;
		return partra;
	}
	return partra;
}



BinTree Delete(BinTree BST, ElementType X)
{
	int LeftRight;
	BinTree Parent = FindParent(BST, X, &LeftRight);
	BinTree Temp = Find(BST, X);
	BinTree LeftMAXRightMin;
	if (!Temp)printf("Not Found\n");
	while (Temp)
	{
		if (Temp->Left == NULL && Temp->Right == NULL)
		{
			if (LeftRight == 1)
				Parent->Left = NULL;
			else if(LeftRight == 2)
				Parent->Right = NULL;
			else
				return NULL;
			Temp = NULL;
		}
		else if (Temp->Left != NULL)
		{
			LeftMAXRightMin = FindMax(Temp->Left);
			Temp->Data = LeftMAXRightMin->Data;
			X = LeftMAXRightMin->Data;
			Parent = FindParent(Temp->Left, X, &LeftRight);
			Temp = LeftMAXRightMin;
		}
		else if (Temp->Right != NULL)
		{
			LeftMAXRightMin = FindMin(Temp->Right);
			Temp->Data = LeftMAXRightMin->Data;
			X = LeftMAXRightMin->Data;
			Parent = FindParent(Temp->Right, X, &LeftRight);
			Temp = LeftMAXRightMin;
		}
	
	}
	return BST;
}