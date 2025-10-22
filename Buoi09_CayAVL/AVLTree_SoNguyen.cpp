#include "asciinode.h"
#include "AVLTree_SoNguyen.h"
//==============================================================
AVLNode* createAVLNode(ItemType x)
{//Tạo 1 node mới
	AVLNode* p = new AVLNode;
	if (p == NULL)
	{
		printf("Khong the cap phat bo nho !");
		getch();
		return NULL;
	}
	p->balFactor = 0;
	p->Info = x; // Gán giá trị 
	p->Left = NULL;// Giá địa chỉ (mặc dịnh là node)
	p->Right = NULL;
	return p;
}
//==============================================================
void initAVLTree(AVLTree& avl)
{//Set địa chỉ Head - Tail
	avl.Root = NULL;
}
//==============================================================
void rotateLL(AVLNode *&T)
{
	AVLNode *T1 = T->Left;
	T->Left = T1->Right;
	T1->Right = T;
	switch (T1->balFactor)
	{
	case LH:
		T->balFactor = EH;
		T1->balFactor = EH;
		break;
	case EH:
		T->balFactor = LH;
		T1->balFactor = RH;
		break;
	}
	T = T1;
}
//==============================================================
void rotateRR(AVLNode *&T)
{
	AVLNode *T1 = T->Right;
	T->Right = T1->Left;
	T1->Left = T;
	switch (T1->balFactor)
	{
	case RH:
		T->balFactor = EH;
		T1->balFactor = EH;
		break;
	case EH:
		T->balFactor = RH;
		T1->balFactor = LH;
		break;
	}
	T = T1;
}
//==============================================================
void rotateLR(AVLNode *&T)
{
	AVLNode*T1 = T->Left;
	AVLNode*T2 = T1->Right;
	T1->Right = T2->Left;
	T2->Left = T1;
	T->Left = T2->Right;
	T2->Right = T;
	switch (T2->balFactor)
	{
	case LH :
		T->balFactor = RH;
		T1->balFactor = EH;
		break;
	case EH:
		T->balFactor = EH;
		T1->balFactor = EH;
		break;
	case RH:
		T->balFactor = EH;
		T1->balFactor = LH;
		break;
	}
	T2->balFactor = EH;
	T = T2;
}
//==============================================================
void rotateRL(AVLNode *&T)
{
	AVLNode*T1 = T->Right;
	AVLNode*T2 = T1->Left;
	T1->Left = T2->Right;
	T2->Right = T1;
	T->Right = T2->Left;
	T2->Left = T;
	switch (T2->balFactor)
	{
	case RH:
		T->balFactor = LH;
		T1->balFactor = EH;
		break;
	case EH:
		T->balFactor = EH;
		T1->balFactor = EH;
		break;
	case LH:
		T->balFactor = EH;
		T1->balFactor = RH;
		break;
	}
	T2->balFactor = EH;
	T = T2;
}
//==============================================================
int balanceLeft(AVLNode *&T)
{
	AVLNode *T1 = T->Left;
	switch (T1->balFactor)
	{
	case LH:
		rotateLL(T);
		return 2;
	case EH:
		rotateLL(T);
		return 1;
	case RH:
		rotateLR(T);
		return 2;
	}
	return 0;
}
//==============================================================
int balanceRight(AVLNode *&T)
{
	AVLNode *T1 = T->Right;
	switch (T1->balFactor)
	{
	case LH:
		rotateRL(T);
		return 2;
	case EH:
		rotateRR(T);
		return 1;
	case RH:
		rotateRR(T);
		return 2;
	}
	return 0;
}
//==============================================================
int insertAVLNode(AVLNode *&T, AVLNode *p)
{
	if (p == NULL) return -1;
	if (T == NULL)
	{
		T = p;
		return 2;
	}
	int Result;
	if (T->Info == p->Info)
		return 0;
	if (T->Info > p->Info)
	{
		Result = insertAVLNode(T->Left, p);
		if (Result < 2)
			return Result;
		switch (T->balFactor)
		{
		case RH :
			T->balFactor = EH;
			return 1;
		case EH:
			T->balFactor = LH;
			return 2;
		case LH:
			balanceLeft(T);
			return 1;
		}
	}
	else
	{
		Result = insertAVLNode(T->Right, p);
		if (Result < 2)
			return Result;
		switch (T->balFactor)
		{
		case LH:
			T->balFactor = EH;
			return 1;
		case EH:
			T->balFactor = RH;
			return 2;
		case RH:
			balanceRight(T);
			return 1;
		}
	}
}
//==============================================================
int searchStandFor(AVLNode *&p, AVLNode *&q)
{
	int Result;
	if (q->Left)
	{
		Result = searchStandFor(p, q->Left);
		if (Result < 2)
			return Result;
		switch (q->balFactor)
		{
		case LH:
			q->balFactor = EH;
			return 2;
		case EH:
			q->balFactor = RH;
			return 1;
		case RH:
			return balanceRight(q);
		}
	}
}
//==============================================================
int deleteAVLNode(AVLNode *&T, ItemType x)
{
	int Result;
	if (T == NULL) return 0;
	if (T->Info > x)
	{
		Result = deleteAVLNode(T->Left, x);
		if (Result < 2)
			return Result;
		switch (T->balFactor)
		{
		case LH :
			T->balFactor = EH;
			return 2;
			case EH : 
				T->balFactor = RH;
				return 1;
			case RH :
				return balanceRight(T);
		}
	}
	else if (T->Info < x)
	{
		Result = deleteAVLNode(T->Right, x);
		if (Result < 2)
			return Result;
		switch (T->balFactor)
		{
		case RH:
			T->balFactor = EH;
			return 2;
		case EH:
			T->balFactor = LH;
			return 1;
		case LH :
			return balanceLeft(T);
		}
	}
	else
	{
		AVLNode *p = T;
		if (T->Left == NULL)
		{
			T = T->Right;
			Result = 2;
		}
		else
		{
			if (T->Right == NULL)
			{
				T = T->Left;
				Result = 2;
			}
			else
			{
				Result = searchStandFor(p, T->Right);
				if (Result < 2)
					return Result;
				switch (T->balFactor)
				{
				case RH : 
					T->balFactor = EH;
					return 2;
				case EH:
					T->balFactor = LH;
					return 1;
				case LH:
					return balanceLeft(T);
				}
			}
		}
		delete p;
		return Result;
	}
	return Result;
}
//==============================================================
AVLNode *findAVLNode(AVLNode *root, ItemType x)
{
	if (!root) return NULL;
	if (root->Info == x) return root;
	else if (root->Info > x)
		return findAVLNode(root->Left, x);
	else
		return findAVLNode(root->Right, x);
}
//==============================================================
int deleteAVLTree(AVLNode *&root)
{
	if (!root) return 0;
	deleteAVLTree(root->Left);
	deleteAVLTree(root->Right);
	deleteAVLTree(root);
	return 1;
}
//==============================================================
void createAVLTree_ByHand(AVLTree& avl)
{
	initAVLTree(avl);
	int n;
	do
	{
		printf("Nhap so luong phan tu cua Cay : ");
		scanf("%d", &n);
		if (n <= 0) printf("Nhap sai roi! Vui long nhap lai.\n");
	} while (n <= 0);
	int i = 0;
	while (i < n)
	{
		ItemType x;
		printf("Nhap gia tri cho Node thu %d: ", i + 1);
		scanf("%d", &x);
		AVLNode* p = createAVLNode(x);
		int kq = insertAVLNode(avl.Root, p);
		if (kq == 1) i++;
	}
}
//==============================================================
void createAVLTree_Random(AVLTree& avl)
{//Chèn ngẫu nhiên AVLTree
	initAVLTree(avl);
	int n;
	do
	{
		printf("Nhap so luong phan tu cua Cay : ");
		scanf("%d", &n);
		if (n <= 0) printf("Nhap sai roi! Vui long nhap lai.\n");
	} while (n <= 0);
	srand((unsigned)time(NULL));
	int i = 0;
	while (i < n)
	{
		ItemType x;
		x = rand() % 199 - 99;
		printf("\nSo vua tao la : %d", x);
		AVLNode* p = createAVLNode(x);
		int kq;
		kq = insertAVLNode(avl.Root, p);
		if (kq == 1) i++;
	}
}
//==============================================================
void createAVLTree_FromArray(AVLTree& avl, ItemType a[], int n)
{//Chèn từ mảng vào AVLTree
	initAVLTree(avl);
	for (int i = 0; i < n; i++)
	{
		AVLNode *p = createAVLNode(a[i]);
		insertAVLNode(avl.Root, p);
	}
}
//==============================================================
void traverseNLR(AVLNode *root)
{
	if (!root) return;
	printf("%4d", root->Info);
	traverseNLR(root->Left);
	traverseNLR(root->Right);
}
//==============================================================
void traverseNRL(AVLNode *root)
{
	if (!root) return;
	printf("%4d", root->Info);
	traverseNLR(root->Right);
	traverseNLR(root->Left);
}
//==============================================================
void traverseLNR(AVLNode *root)
{
	if (!root) return;
	traverseLNR(root->Left);
	printf("%4d", root->Info);
	traverseLNR(root->Right);
}
//==============================================================
void traverseLRN(AVLNode *root)
{
	if (!root) return;
	traverseLNR(root->Left);
	traverseLNR(root->Right);
	printf("%4d", root->Info);
}
//==============================================================
void traverseRLN(AVLNode *root)
{
	if (!root) return;
	traverseLRN(root->Right);
	traverseLRN(root->Left);
	printf("%4d", root->Info);
}
//==============================================================
void traverseRNL(AVLNode *root)
{
	if (!root) return;
	traverseLRN(root->Right);
	printf("%4d", root->Info);
	traverseLRN(root->Left);
}
//==============================================================
void showAVLNode(AVLNode* p)
{//Hiển thị 1 Node
	printf("%5d", p->Info);
}
//==============================================================
void printAVLTree(AVLNode *p)
{
	print_ascii_tree(p);
}