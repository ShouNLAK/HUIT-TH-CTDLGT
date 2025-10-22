/*
Họ và tên : Nguyễn Lê Anh Khoa
Lớp :		THCTDL&GT - SL4 - A211
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>

typedef int ItemType;
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
StackNode* createStackNode(ItemType x)
{//Tạo 1 node mới
	StackNode* p = new StackNode;
	if (p == NULL)
	{
		printf("Khong the cap phat bo nho !");
		getch();
		return NULL;
	}
	p->Info = x; // Gán giá trị 
	p->Next = NULL;// Giá địa chỉ (mặc dịnh là node)
	return p;
}
//==============================================================
void showStackNode(StackNode* p)
{//Hiển thị 1 Node
	printf("%d", p->Info);
}
//==============================================================
void initStack(Stack& st)
{//Set địa chỉ Top - Tail
	st.Top = NULL;
}
//==============================================================
int isEmpty(Stack st)
{// Check Stack rỗng hay không 
	return st.Top == NULL ? 1 : 0;
}
//==============================================================
int push(Stack& st, StackNode* p)
{//Chèn lên đầu Stack
	if (p == NULL)
		return 0;
	if (isEmpty(st) == 1) //Mặc định ở đầu và cuối nếu StackNode đầu tiên
	{
		st.Top = p;
	}
	else
	{
		p->Next = st.Top;
		st.Top = p;
	}
	return 1;
}
//==============================================================
int pop(Stack &st, ItemType &x)
{
	if (isEmpty(st) == 1)
		return 0;
	StackNode *p = st.Top;
	st.Top = st.Top->Next;
	x = p->Info;
	delete p;
	return 1;
}
//==============================================================
int getTop(Stack &st, ItemType &x)
{
	if (isEmpty(st) == 1)
		return 0;
	x = st.Top->Info;
	return 1;
}
//==============================================================
void createStack_InputByHand(Stack& st)
{//tạo thủ công Stack
	initStack(st);
	int n;
	do
	{
		printf("Nhap so luong phan tu cua ngan xep : ");
		scanf("%d", &n);
		if (n <= 0) printf("Nhap sai roi! Vui long nhap lai.\n");
	} while (n <= 0);
	int i = 0;
	while (i < n)
	{
		ItemType x;
		printf("Nhap gia tri cho Node thu %d: ", i + 1);
		scanf("%d", &x);
		StackNode* p = createStackNode(x);
		int kq = push(st, p);
		if (kq == 1) i++;
	}
}
//==============================================================
void createStack_Random(Stack& st)
{//Chèn ngẫu nhiên Stack
	initStack(st);
	int n;
	do
	{
		printf("Nhap so luong phan tu cua ngan xep : ");
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
		StackNode* p = createStackNode(x);
		int kq;
		kq = push(st, p);
		if (kq == 1) i++;
	}
}
//==============================================================
void createStack_FromArray(Stack& st, ItemType a[], int n)
{//Chèn từ mảng vào Stack
	initStack(st);
	int i = 0;
	while (i < n)
	{
		ItemType x;
		x = a[i];
		StackNode* p = createStackNode(x);
		int kq = push(st, p);
		if (kq == 1) i++;
	}
}
//==============================================================
void createStack_FromTextFile(Stack& st, char inputFileName[])
{//Chèn từ file Text vào Stack
	initStack(st);
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
		StackNode* p = createStackNode(x);
		int kq = push(st, p);
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
void showStack(Stack st)
{//Hiển thị Stack
	if (isEmpty(st) == 1)
	{
		printf("Danh sach rong !");
		return;
	}
	printf("\nNOI DUNG CUA NGAN XEP LA : \nTop -> ");

	for (StackNode* p = st.Top; p != NULL; p = p->Next)
	{
		showStackNode(p);
		printf(" -> ");
	}
	printf("NULL");
}
//==============================================================
StackNode* findStackNode(Stack st, ItemType x)
{// Tìm StackNode
	if (isEmpty(st) == 1)
	{
		return NULL;
	}
	for (StackNode* p = st.Top; p != NULL; p = p->Next)
	{
		if (p->Info == x)
			return p;
	}
	return NULL;
}
//==============================================================
void showMenu()
{
	printf("\n******************************************************************");
	printf("\n*                              MENU                              *");
	printf("\n******************************************************************");
	printf("\n* 0. Thoat chuong trinh                                          *");
	printf("\n* 1. Nhap - Xuat 1 Node                                          *");
	printf("\n* 2. Nhap ngan xep truc tiep tu ban phim                         *");
	printf("\n* 3. Tao ngan xep phat sinh ngau nhien                           *");
	printf("\n* 4. Tao ngan xep tu mang 1 chieu                                *");
	printf("\n* 5. Tao ngan xep tu text file                                   *");
	printf("\n* 6. Them 1 node moi vao dau ngan xep                            *");
	printf("\n* 7. Xem noi dung o dinh ngan xep                                *");
	printf("\n* 8. Xoa mot node moi vao dau cua ngan xep                       *");
	printf("\n* 9. Tim phan tu x trong ngan xep ?                              *");
	printf("\n* 10. Xem noi dung ngan xep                                      *");
	printf("\n******************************************************************");
}
//==============================================================
void process()
{
	int luaChon, kq;
	StackNode* P;
	Stack ST;
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
			P = createStackNode(X);
			showStackNode(P);
			break;
		case 2:
			createStack_InputByHand(ST);
			printf("\nNOI DUNG NGAN XEP VUA NHAP LA : \n");
			showStack(ST);
			break;
		case 3:
			createStack_Random(ST);
			printf("\nNOI DUNG NGAN XEP VUA TAO NGAU NHIEN LA : \n");
			showStack(ST);
			break;
		case 4:
			createStack_FromArray(ST, A, N);
			printf("\nNOI DUNG NGAN XEP VUA TAO TU MANG MOT CHIEU LA : \n");
			showStack(ST);
			break;
		case 5:
			createStack_FromTextFile(ST, tenFile);
			printf("\nNOI DUNG NGAN XEP VUA TAO TU FILE TEXT LA : \n");
			showStack(ST);
			break;
		case 6:
			printf("Ban hay cho biet gia tri node muon them vao dau ngan xep : ");
			scanf("%d", &X);
			P = createStackNode(X);
			kq = push(ST, P);
			if (kq == 1)
			{
				printf("\nNOI DUNG NGAN XEP SAU KHI THEM %d VAO DAU LA : \n", X);
				showStack(ST);
			}
			else
			{
				printf("\nKhong the them %d vao dau ngan xep.", X);
			}
			break;
		case 7:
			kq = getTop(ST, X);
			if (kq == 1)
			{
				printf("\nNOI DUNG CUA NODE O DINH NGAN XEP LA : %d\n", X);
				showStack(ST);
			}
			else
			{
				printf("\nKhong the xem noi dung node o dinh ngan xep.");
			}
			break;
		case 8:
			kq = pop(ST, X);
			if (kq == 1)
			{
				printf("\nNOI DUNG NGAN XEP SAU KHI XOA %d O DINH LA : \n",X);
				showStack(ST);
			}
			else
			{
				printf("\nKhong the xoa phan tu o dinh ngan xep.");
			}
			break;
		case 9:
			printf("Ban hay cho biet gia tri node can tim trong ngan xep : ");
			scanf("%d", &X);
			P = findStackNode(ST, X);
			if (P == NULL)
				printf("Khong tim thay %d trong ngan xep.", X);
			else
				printf("Da tim thay %d trong ngan xep tai dia chi %d", X, P);
			break;
		case 10:
			showStack(ST);
			break;
		}
	} while (luaChon != 0);
}
//==============================================================
void main()
{
	process();
}