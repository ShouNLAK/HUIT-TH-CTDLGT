/*
Họ và tên : Nguyễn Lê Anh Khoa
Lớp :		THCTDL&GT - ST4 - A211
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>

typedef int ItemType;
struct BSTNode
{//Tạo 1 node
	ItemType Info;
	BSTNode* Left;
	BSTNode* Right;
};
//==============================================================
struct BSTree
{//Tạo 1 danh sách các Node
	BSTNode *Root;
};
//==============================================================
struct StackNode
{//Tạo 1 node
	ItemType Info;
	StackNode* Next;
};
//==============================================================
struct Stack
{//Tạo 1 danh sách các Node
	StackNode *Top;
};
//==============================================================
BSTNode* createBSTNode(ItemType x)
{//Tạo 1 node mới
	BSTNode* p = new BSTNode;
	if (p == NULL)
	{
		printf("Khong the cap phat bo nho !");
		getch();
		return NULL;
	}
	p->Info = x; // Gán giá trị 
	p->Left = NULL;// Giá địa chỉ (mặc dịnh là node)
	p->Right = NULL;
	return p;
}
//==============================================================
void showBSTNode(BSTNode* p)
{//Hiển thị 1 Node
	printf("%5d", p->Info);
}
//==============================================================
void initBSTree(BSTree& bst)
{//Set địa chỉ Head - Tail
	bst.Root = NULL;
}
//==============================================================
int insertBSTNode(BSTNode *&root, BSTNode* p)
{//Chèn vào cuối BSTree
	if (p == NULL)
		return 0;
	if (!root)//Mặc định ở đầu và cuối nếu BSTNode đầu tiên
		root = p;
	else if (root->Info == p->Info)
	{
		return 0;
	}
	else if (root->Info > p->Info)
	{
		insertBSTNode(root->Left, p);
	}
	else
	{
		insertBSTNode(root->Right, p);
	}
	return 1;
}
//==============================================================
void createBSTree_InputByHand(BSTree& bst)
{//tạo thủ công BSTree
	initBSTree(bst);
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
		BSTNode* p = createBSTNode(x);
		int kq = insertBSTNode(bst.Root, p);
		if (kq == 1) i++;
	}
}
//==============================================================
void createBSTree_Random(BSTree& bst)
{//Chèn ngẫu nhiên BSTree
	initBSTree(bst);
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
		BSTNode* p = createBSTNode(x);
		int kq;
		kq = insertBSTNode(bst.Root, p);
		if (kq == 1) i++;
	}
}
//==============================================================
void createBSTree_FromArray(BSTree& bst, ItemType a[], int n)
{//Chèn từ mảng vào BSTree
	initBSTree(bst);
	int i = 0;
	while (i < n)
	{
		ItemType x;
		x = a[i];
		BSTNode* p = createBSTNode(x);
		int kq = insertBSTNode(bst.Root, p);
		if (kq == 1) i++;
	}
}
//==============================================================
void createBSTree_FromTextFile(BSTree& bst, char inputFileName[])
{//Chèn từ file Text vào BSTree
	initBSTree(bst);
	int n;
	FILE* fi = fopen(inputFileName, "rt");
	if (fi == NULL)
	{
		printf("Loi mo file : %s", inputFileName);
		return;
	}
	fscanf(fi, "%d\n", &n);
	int i = 0;
	while (i < n)
	{
		ItemType x;
		fscanf(fi, "%d", &x);
		BSTNode* p = createBSTNode(x);
		int kq = insertBSTNode(bst.Root, p);
		if (kq == 1) i++;
	}
	fclose(fi);
}
//==============================================================
void swap(ItemType& x, ItemType& y)
{//Hoán đổi 2 giá trị
	ItemType tmp;
	tmp = x;
	x = y;
	y = tmp;
}
//==============================================================
void traverseNRL(BSTNode *root)
{//Hiển thị BSTree
	if (!root)
	{
		return;
	}
	showBSTNode(root);
	traverseNRL(root->Right);
	traverseNRL(root->Left);
}
//==============================================================
void traverseNLR(BSTNode *root)
{//Hiển thị BSTree
	if (!root)
	{
		return;
	}
	showBSTNode(root);
	traverseNLR(root->Left);
	traverseNLR(root->Right);
}
//==============================================================
void traverseLNR(BSTNode *root)
{//Hiển thị BSTree
	if (!root)
	{
		return;
	}
	traverseLNR(root->Left);
	showBSTNode(root);
	traverseLNR(root->Right);
}
//==============================================================
void traverseRNL(BSTNode *root)
{//Hiển thị BSTree
	if (!root)
	{
		return;
	}
	traverseLNR(root->Right);
	showBSTNode(root);
	traverseLNR(root->Left);
}
//==============================================================
void traverseLRN(BSTNode *root)
{//Hiển thị BSTree
	if (!root)
	{
		return;
	}
	traverseNLR(root->Left);
	traverseNLR(root->Right);
	showBSTNode(root);
}
//==============================================================
void traverseRLN(BSTNode *root)
{//Hiển thị BSTree
	if (!root)
	{
		return;
	}
	traverseNLR(root->Right);
	traverseNLR(root->Left);
	showBSTNode(root);
}
//==============================================================
int hightree(BSTNode *root)
{
	if (!root) return 0;
	int hl = hightree(root->Left);
	int hr = hightree(root->Right);
	return 1 + (hl > hr ? hl : hr);
}
//==============================================================
int countBSTNodeLeaf(BSTNode *root)
{
	if (!root) return 0;
	if (!root->Left && !root->Right) return 1;
	int countL = countBSTNodeLeaf(root->Left);
	int countR = countBSTNodeLeaf(root->Right);
	return countL + countR;
}
//==============================================================
int sumBSTNodeLeaf(BSTNode *root)
{
	if (!root) return 0;
	if (!root->Left && !root->Right) return root->Info;
	int sumL = sumBSTNodeLeaf(root->Left);
	int sumR = sumBSTNodeLeaf(root->Right);
	return sumL + sumR;
}
//==============================================================
int sumBSTNode(BSTNode *root)
{
	if (!root) return 0;
	int sumL = sumBSTNode(root->Left);
	int sumR = sumBSTNode(root->Right);
	return sumL + sumR + root->Info;
}
//==============================================================
BSTNode* findBSTNode(BSTNode *root, ItemType x)
{// Tìm BSTNode
	if (!root)
	{
		return NULL;
	}
	if (root->Info == x)
		return root;
	else if (root->Info > x)
		return findBSTNode(root->Left, x);
	else
		return findBSTNode(root->Right, x);
}
//==============================================================
BSTNode *findBSTNodeReplace(BSTNode *&p)
{
	BSTNode *f = p;
	BSTNode *q = p->Right;
	while (q->Left != NULL)
	{
		f = q;
		q = q->Left;
	}
	p->Info = q->Info;
	if (f == p)
		f->Right = q->Right;
	else
		f->Left = q->Right;
	return q;
}
//==============================================================
int deleteBSTNodeX(BSTNode *&root, ItemType x)
{
	if (!root)
		return 0;
	if (root->Info > x)
		return deleteBSTNodeX(root->Left, x);
	else if (root->Info < x)
		return deleteBSTNodeX(root->Right, x);
	else
	{
		BSTNode *p = root;
		if (root->Left == NULL)
		{
			root = root->Right;
			delete p;
		}
		else if (root->Right == NULL)
		{
			root = root->Left;
			delete p;
		}
		else
		{
			BSTNode *q = findBSTNodeReplace(p);
			delete p;
		}
	}
	return 1;
}
//==============================================================
void showMenu()
{
	printf("\n******************************************************************");
	printf("\n*                              MENU                              *");
	printf("\n******************************************************************");
	printf("\n* 0. Thoat chuong trinh                                          *");
	printf("\n* 1. Nhap - Xuat 1 Node                                          *");
	printf("\n* 2. Nhap Cay truc tiep tu ban phim                              *");
	printf("\n* 3. Tao Cay phat sinh ngau nhien                                *");
	printf("\n* 4. Tao Cay tu mang 1 chieu                                     *");
	printf("\n* 5. Tao Cay tu text file                                        *");
	printf("\n* 6. Them 1 node moi vao dau Cay                                 *");
	printf("\n* 7. Xoa phan tu trong Cay                                       *");
	printf("\n* 8. Tim phan tu x trong Cay ?                                   *");
	printf("\n* 9. Xem cay hien tai                                            *");
	printf("\n* 10.Tinh chieu cao cua cay hien tai                             *");
	printf("\n* 11.Tinh not la cua cay hien tai                                *");
	printf("\n* 12.Tinh tong gia tri not la cua cay hien tai                   *");
	printf("\n* 13.Tinh tong gia tri not cua cay hien tai                      *");
	printf("\n******************************************************************");
}
//==============================================================
void process()
{
	int luaChon, kq;
	BSTNode* P, *Q;
	BSTree bst;
	ItemType X, Y;
	ItemType A[] = { 15, -27, 43, 23, -35, 48, 97, -76, 91, 13 };
	int N = 10;
	char tenFile[] = "inputFile_SoNguyen.txt";
	do
	{
		showMenu();
		printf("\nBan hay lua chon mot chuc nang : ");
		scanf("%d", &luaChon);
		switch (luaChon)
		{
		case 1:
			printf("Ban hay nhap mot so nguyen bat ky : ");
			scanf("%d", &X);
			P = createBSTNode(X);
			showBSTNode(P);
			break;
		case 2:
			createBSTree_InputByHand(bst);
			printf("\nNOI DUNG Cay VUA NHAP LA : \n");
			traverseNLR(bst.Root);
			break;
		case 3:
			createBSTree_Random(bst);
			printf("\nNOI DUNG Cay VUA TAO NGAU NHIEN LA : \n");
			traverseNLR(bst.Root);
			break;
		case 4:
			createBSTree_FromArray(bst, A, N);
			printf("\nNOI DUNG Cay VUA TAO TU MANG MOT CHIEU LA : \n");
			traverseNLR(bst.Root);
			break;
		case 5:
			createBSTree_FromTextFile(bst, tenFile);
			printf("\nNOI DUNG Cay VUA TAO TU FILE TEXT LA : \n");
			traverseNLR(bst.Root);
			break;
		case 6:
			printf("Ban hay cho biet gia tri node muon them vao dau Cay : ");
			scanf("%d", &X);
			P = createBSTNode(X);
			kq = insertBSTNode(bst.Root, P);
			if (kq == 1)
			{
				printf("\nNOI DUNG Cay SAU KHI THEM %d VAO DAU LA : \n", X);
				traverseNLR(bst.Root);
			}
			else
			{
				printf("\nKhong the them %d vao dau Cay.", X);
			}
			break;
		case 7:
			printf("Nhap x can xoa : "); scanf("%d", &X);
			kq = deleteBSTNodeX(bst.Root, X);
			if (kq == 1)
			{
				printf("\nNOI DUNG Cay SAU KHI XOA %d TRONG CAY LA : \n",X);
				traverseNLR(bst.Root);
			}
			else
			{
				printf("\nKhong the xoa phan tu %d.",X);
			}
			break;
		case 8:
			printf("Ban hay cho biet gia tri node can tim trong Cay : ");
			scanf("%d", &X);
			P = findBSTNode(bst.Root, X);
			if (P == NULL)
				printf("Khong tim thay %d trong Cay.", X);
			else
				printf("Da tim thay %d trong Cay tai dia chi %d", X, P);
			break;
		case 9:
			printf("\nDuyet cay theo NLR : \n");
			traverseNLR(bst.Root);
			printf("\nDuyet cay theo LNR : \n");
			traverseLNR(bst.Root);
			break;
		case 10 :
			printf("Chieu cao cua cay : %d",hightree(bst.Root));
			break;
		case 11:
			printf("So node la cua cay : %d", countBSTNodeLeaf(bst.Root));
			break;
		case 12:
			printf("Tong node la cua cay : %d", sumBSTNodeLeaf(bst.Root));
			break;
		case 13:
			printf("Tong node cua cay : %d", sumBSTNode(bst.Root));
			break;
		}
	} while (luaChon != 0);
}
//==============================================================
void main()
{
	process();
}