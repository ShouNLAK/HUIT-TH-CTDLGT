#include "CayNPTK_SoNguyen.h"
#include "asciinode.h"
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
void showBSTree(BSTNode *p)
{
	print_ascii_tree(p);
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
int isLeaf(BSTNode *T)
{
	if (T == NULL) return 0;
	if (T->Left != NULL || T->Right != NULL) return 0;
	return 1;
}
//==============================================================
int deleteBSTNodeLeft(BSTNode *T, ItemType &x)
{
	if (T == NULL) return 0;
	BSTNode *p = T->Left;
	if (p == NULL) return 0;
	if (!isLeaf(p)) return 0;
	T->Left = NULL;
	x = p->Info;
	delete p;
	return 1;
}
//==============================================================
int deleteBSTNodeRight(BSTNode *T, ItemType &x)
{
	if (T == NULL) return 0;
	BSTNode *p = T->Right;
	if (p == NULL) return 0;
	if (!isLeaf(p)) return 0;
	T->Right = NULL;
	x = p->Info;
	delete p;
	return 1;
}
//==============================================================
int count_bigger_than_x(BSTNode *root, ItemType &x)
{
	if (root == NULL) return 0;
	int countL = count_bigger_than_x(root->Left, x);
	int countR = count_bigger_than_x(root->Right, x);
	return (root->Info > x ? 1 : 0) + countL + countR;
}
//==============================================================
int count_smaller_than_x(BSTNode *root, ItemType &x)
{
	if (root == NULL) return 0;
	int countL = count_smaller_than_x(root->Left, x);
	int countR = count_smaller_than_x(root->Right, x);
	return (root->Info < x ? 1 : 0) + countL + countR;
}
//==============================================================
int count_between_x_y(BSTNode *root, ItemType &x,ItemType &y)
{
	if (x > y) swap(x, y);
	if (root == NULL) return 0;
	int countL = count_between_x_y(root->Left, x, y);
	int countR = count_between_x_y(root->Right, x, y);
	return ((root->Info >= x && root->Info <= y) ? 1 : 0) + countL + countR;
}
//==============================================================
int countBSTNode(BSTNode *root)
{
	if (root == NULL) return 0;
	int countL = countBSTNode(root->Left);
	int countR = countBSTNode(root->Right);
	return 1 + countL + countR;
}
//==============================================================
int countBSTNodeHaveTwoChild(BSTNode *root)
{
	if (!root) return 0;
	int nl = countBSTNodeHaveTwoChild(root->Left);
	int nr = countBSTNodeHaveTwoChild(root->Right);
	if (root->Left && root->Right)
		return 1 + nl + nr;
	return nl + nr;
}
//==============================================================
int countBSTNodeHaveOneChild(BSTNode *root)
{
	if (!root) return 0;
	int nl = countBSTNodeHaveOneChild(root->Left);
	int nr = countBSTNodeHaveOneChild(root->Right);
	if ((root->Left && !root->Right) || (!root->Left && root->Right))
		return 1 + nl + nr;
	return nl + nr;
}
//==============================================================
int countBSTNodeHaveChildIsLeaf(BSTNode *root)
{
	if (!root) return 0;
	int nl = countBSTNodeHaveChildIsLeaf(root->Left);
	int nr = countBSTNodeHaveChildIsLeaf(root->Right);
	if (isLeaf(root->Left) || isLeaf(root->Right))
		return 1 + nr + nl;
	return nr + nl;
}
//==============================================================
int Max_BSTree(BSTNode *root)
{
	if (!root) return NULL;
	int MaxL = Max_BSTree(root->Left);
	int MaxR = Max_BSTree(root->Right);
	if (root->Info < MaxL || root->Info < MaxR)
		return MaxL > MaxR ? MaxL : MaxR;
	return root->Info;
}
//==============================================================
int Min_BSTree(BSTNode *root)
{
	if (!root) return NULL;
	int MinL = Min_BSTree(root->Left);
	int MinR = Min_BSTree(root->Right);
	if (root->Info > MinL || root->Info > MinR)
		return MinL > MinR ? MinR : MinL;
	return root->Info;
}
//==============================================================
void showBSTNodeOfLevelK(BSTNode *root, int k)
{
	if (!root) return;
	if (k == 0)
		showBSTNode(root);
	k--;
	showBSTNodeOfLevelK(root->Left, k);
	showBSTNodeOfLevelK(root->Right, k);
}
//==============================================================
void showBSTNodeIsLeafOfLevelK(BSTNode *root, int k)
{
	if (!root) return;
	if (k == 0 && !root->Left && !root->Right)
		showBSTNode(root);
	k--;
	showBSTNodeIsLeafOfLevelK(root->Left, k);
	showBSTNodeIsLeafOfLevelK(root->Right, k);
}
//==============================================================
int countBSTNodeOfLevelK(BSTNode *root, int k)
{
	if (!root) return 0;
	if (k == 0)
		return 1;
	k--;
	int nl = countBSTNodeOfLevelK(root->Left, k);
	int nr = countBSTNodeOfLevelK(root->Right, k);
	return nl + nr;
}
//==============================================================
int countBSTNodeIsLeafOfLevelK(BSTNode *root, int k)
{
	if (!root) return 0;
	if (k == 0 && !root->Left && !root->Right)
		return 1;
	k--;
	int nl = countBSTNodeIsLeafOfLevelK(root->Left, k);
	int nr = countBSTNodeIsLeafOfLevelK(root->Right, k);
	return nl + nr;
}
//==============================================================
int minDistance(BSTNode *root, ItemType x)
{
	if (!root) return -1;
	int min = root->Info;
	int mindis = abs(x - min);
	while (root != NULL)
	{
		if (root->Info == x)
			return x;
		if (mindis > abs(x - root->Info))
		{
			min = root->Info;
			mindis = abs(x - min);
		}
		if (x > root->Info)
			root = root->Right;
		else
			root = root->Left;
	}
	return min;
}
//==============================================================
int maxDistance(BSTNode *root, ItemType x)
{
	if (!root) return -1;
	BSTNode *minLeft = root;
	while (minLeft->Left != NULL)
		minLeft = minLeft->Left;
	BSTNode *maxRight = root;
	while (maxRight->Right != NULL)
		maxRight = maxRight->Right;
	int dis1 = abs(x - minLeft->Info);
	int dis2 = abs(x - maxRight->Info);
	if (dis1 > dis2)
		return minLeft->Info;
	else
		return maxRight->Info;
}
//==============================================================
int sumPositive(BSTNode *root)
{
	if (!root) return 0;
	int sumL = sumPositive(root->Left);
	int sumR = sumPositive(root->Right);
	return (root->Info > 0 ? root->Info : 0) + sumL + sumR;
}
//==============================================================
int sumNegative(BSTNode *root)
{
	if (!root) return 0;
	int sumL = sumNegative(root->Left);
	int sumR = sumNegative(root->Right);
	return (root->Info < 0 ? root->Info : 0) + sumL + sumR;
}
//==============================================================
int isPrime(int n)
{
	if (n <= 1) return 0;
	for (int i = 2; i <= sqrt((float)n);i++)
	if (n % i == 0) return 0;
	return 1;
}
//==============================================================
int isSquare(int n)
{
	int Square = sqrt((float)n);
	if (Square * Square == n) return 1;
	return 0;
}
//==============================================================
int isPerfect(int n)
{
	int sum = 0;
	for (int i = 1; i < n; i++)
	if (n % i == 0)
		sum += i;
	if (sum == n)
		return 1;
	return 0;
}
//==============================================================
int checkSTV(int n)
{//Check số thịnh vượng
	int sum = 0;
	for (int i = 1; i < n; i++)
	if (n % i == 0)
		sum += i;
	if (sum > n)
		return 1;
	return 0;
}
//==============================================================
int checkSY(int n)
{//Check số yếu
	int sum = 0;
	for (int i = 1; i < n; i++)
	if (n % i == 0)
		sum += i;
	if (sum < n)
		return 1;
	return 0;
}
//==============================================================
int sumPrime(BSTNode *root)
{
	if (!root) return 0;
	int sumL = sumPrime(root->Left);
	int sumR = sumPrime(root->Right);
	return (isPrime(root->Info) ? root->Info : 0) + sumL + sumR;
}
//==============================================================
int sumSquare(BSTNode *root)
{
	if (!root) return 0;
	int sumL = sumSquare(root->Left);
	int sumR = sumSquare(root->Right);
	return (isSquare(root->Info) ? root->Info : 0) + sumL + sumR;
}
//==============================================================
int sumPerfect(BSTNode *root)
{
	if (!root) return 0;
	int sumL = sumPerfect(root->Left);
	int sumR = sumPerfect(root->Right);
	return (isPerfect(root->Info) ? root->Info : 0) + sumL + sumR;
}
//==============================================================
int sumSTV(BSTNode *root)
{//Tổng số thịnh vượng
	if (!root) return 0;
	int sumL = sumSTV(root->Left);
	int sumR = sumSTV(root->Right);
	return (checkSTV(root->Info) ? root->Info : 0) + sumL + sumR;
}
//==============================================================
int sumSY(BSTNode *root)
{//Tổng số yếu
	if (!root) return 0;
	int sumL = sumSY(root->Left);
	int sumR = sumSY(root->Right);
	return (checkSY(root->Info) ? root->Info : 0) + sumL + sumR;
}
//==============================================================
void deleteTree(BSTNode*&root)
{
	if (root == NULL) return;
	deleteTree(root->Left);
	deleteTree(root->Right);
	delete root;
}
//=============================================================
void showTreeByLevel(BSTNode *root)
{
	if (!root) return;
	int h = hightree(root);
	for (int i = 0; i < h; i++)
	{
		printf("\nCac phan tu tren tang thu %d : ", i);
		showBSTNodeOfLevelK(root, i);
	}
}
//=============================================================
int countBSTNodeIsLeaf_Chan(BSTNode *root)
{
	if (!root) return 0;
	int cl = countBSTNodeIsLeaf_Chan(root->Left);
	int cr = countBSTNodeIsLeaf_Chan(root->Right);
	if (root->Info % 2 == 0)
	{
		showBSTNode(root);
		printf("\n");
		return 1 + cl + cr;
	}
	else
		return cl + cr;
}
//=============================================================
int countBSTNodeHaveOneChild_Prime(BSTNode *root)
{
	if (!root) return 0;
	int nl = countBSTNodeHaveOneChild_Prime(root->Left);
	int nr = countBSTNodeHaveOneChild_Prime(root->Right);
	if ((root->Left && !root->Right) || (!root->Left && root->Right))
		if (isPrime(root->Info))
			return 1 + nl + nr;
	return nl + nr;
}
//=============================================================
int countBSTNodeHaveTwoChild_Square(BSTNode *root)
{
	if (!root) return 0;
	int nl = countBSTNodeHaveTwoChild_Square(root->Left);
	int nr = countBSTNodeHaveTwoChild_Square(root->Right);
	if (root->Left && root->Right)
		if (isSquare(root->Info))
			return 1 + nl + nr;
	return nl + nr;
}
//=============================================================
int countBSTNodeBelowK(BSTNode *root, int k)
{
	if (!root) return 0;
	int h = hightree(root);
	if (k >= h) return 0;
	return countBSTNodeOfLevelK(root, k + 1) + countBSTNodeOfLevelK(root->Left, k) + countBSTNodeOfLevelK(root->Right, k);
}
//=============================================================
int countBSTNodeAboveK(BSTNode*root, int k)
{
	if (!root)  return 0;
	int count = 0;
	for (int i = 0; i < k; i++)
		count += countBSTNodeOfLevelK(root, i);
	return count;
}
//=============================================================
int sumBSTree_Le(BSTNode *root)
{
	if (!root)
		return 0;
	if (root->Info % 2 != 0)
		return root->Info + sumBSTree_Le(root->Left) + sumBSTree_Le(root->Right);
	else
		return sumBSTree_Le(root->Left) + sumBSTree_Le(root->Right);
}
//=============================================================
int sumBSTNodeHaveOneLeaf(BSTNode *root)
{
	if (!root)
		return 0;
	int nl = sumBSTNodeHaveOneLeaf(root->Left);
	int nr = sumBSTNodeHaveOneLeaf(root->Right);
	if ((root->Left && !root->Right) || (!root->Left && root->Right))
		return root->Info + nl + nr;
	return nl + nr;
}
//==============================================================
int sumBSTNodeHaveTwoLeaf(BSTNode *root)
{
	if (!root)
		return 0;
	int nl = sumBSTNodeHaveTwoLeaf(root->Left);
	int nr = sumBSTNodeHaveTwoLeaf(root->Right);
	if (root->Left && root->Right)
		return root->Info + nl + nr;
	return nl + nr;
}
//==============================================================
int sumBSTNodeHaveOneChild_Prime(BSTNode *root)
{
	if (!root)
		return 0;
	int sl = sumBSTNodeHaveOneChild_Prime(root->Left);
	int sr = sumBSTNodeHaveOneChild_Prime(root->Right);
	if ((root->Left&&!root->Right) || (!root->Left&&root->Right))
		if (isPrime(root->Info))
			return root->Info + sl + sr;
	return sl + sr;
}
//==============================================================
int sumBSTNodeHaveTwoChild_Square(BSTNode *root)
{
	if (!root)
		return 0;
	int sl = sumBSTNodeHaveTwoChild_Square(root->Left);
	int sr = sumBSTNodeHaveTwoChild_Square(root->Right);
	if (root->Left && root->Right)
		if (isSquare(root->Info))
			return root->Info + sl + sr;
	return sl + sr;
}