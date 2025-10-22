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
{//Set địa chỉ Top
	st.Top = NULL;
}
//==============================================================
int isEmpty(Stack st)
{// Check Stack rỗng hay không 
	return st.Top == NULL ? 1 : 0;
}
//==============================================================
int push(Stack& st, StackNode* p)
{//Chèn lên đầu Stack của Stack
	if (p == NULL)
		return 0;
	if (isEmpty(st) == 1)
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
{ // (Trước đây là DeleteHead)
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
{ // Lấy thông tin của Head
	if (isEmpty(st) == 1)
		return 0;
	x = st.Top->Info;
	return 1;
}
//==============================================================
void Stack_DoiCoSo(Stack& st)
{//tạo thủ công Stack
	initStack(st);
	int n,a;
	do
	{
		printf("Nhap gia tri cua n ( n > 0 ) trong he 10 : ");
		scanf("%d", &n);
		if (n <= 0) printf("Nhap sai roi! Vui long nhap lai.\n");
	} while (n <= 0); // Khai báo giá trị cần chuyển đổi
	do
	{
		printf("Ban hay cho biet co so a ( 2 < a <  16 ) : ");
		scanf("%d", &a);
		if (a < 2 || a > 16) printf("Co so a khong hop le. Vui long thu lai");
	} while (a < 2 || a > 16); // Khai báo hệ số chuyển đổi 
	int temp = n; // Giữ giá trị (Không bắt buộc)
	while (n > 0)
	{
		ItemType sodu = n % a; // Số dư chính là kết quả và được đọc ngược lại
		StackNode* p = createStackNode(sodu);
		push(st, p); // Liên tục đẩy đầu
		n /= a;
	}
	ItemType x;
	printf("Ket qua doi tu %d tu he 10 sang he a = %d la : ", temp, a);
	while (pop(st, x))
	{
		switch (x)
		{
		case 10: printf("A"); break;
		case 11: printf("B"); break;
		case 12: printf("C"); break;
		case 13: printf("D"); break;
		case 14: printf("E"); break;
		case 15: printf("F"); break;
		default: printf("%d", x); break;
		}
	}
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
void showMenu()
{
	printf("\n******************************************************************");
	printf("\n*                              MENU                              *");
	printf("\n******************************************************************");
	printf("\n* 0. Thoat chuong trinh                                          *");
	printf("\n* 1. Doi co so tu he 10 sang he a ( 2 < a < 16 )                 *");
	printf("\n* 2. Xem noi dung ngan xep                                       *");
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
			Stack_DoiCoSo(ST);
			break;
		case 2:
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