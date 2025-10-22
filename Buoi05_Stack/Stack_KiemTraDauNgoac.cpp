/*
Họ và tên : Nguyễn Lê Anh Khoa
Lớp :		THCTDL&GT - SL4 - A211
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef char ItemType;
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
bool stack_kiemTraDauNgoac(char strExp[])
{
	Stack ST;
	initStack(ST);
	int len = strlen(strExp);
	ItemType x, y;
	int i = 0, Mo, Dong;
	Mo = Dong = 0;
	while (i < len)
	{
		x = strExp[i];
		if (x == '(' || x == '{' || x == '[')
		{
			StackNode *p = createStackNode(x);
			push(ST, p);
			Mo++;
		}
		else if (x != ' ')
		{
			if (pop(ST, y) == 1)
			{
				if (x == ')' && y != '(') return false;
				if (x == '}' && y != '{') return false;
				if (x == ']' && y != '[') return false;
			}
			Dong++;
		}
		i++;
	}
	if (Mo == Dong)
		return true;
	else
		return false;
}
//==============================================================
void showMenu()
{
	printf("\n******************************************************************");
	printf("\n*                              MENU                              *");
	printf("\n******************************************************************");
	printf("\n* 0. Thoat chuong trinh                                          *");
	printf("\n* 1. Kiem tra dau ngoac                                          *");
	printf("\n******************************************************************");
}
//==============================================================
void process()
{
	int luaChon, kq;
	StackNode* P;
	ItemType X, Y;
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
			char str[] = "()((())){()}[{{()]}]";
			if (stack_kiemTraDauNgoac(str))
				printf("%s : Dung", str);
			else
				printf("%s : Sai", str);
		}
	} while (luaChon != 0);
}
//==============================================================
void main()
{
	process();
}