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
struct QueueNode
{//Tạo 1 node
	ItemType Info;
	QueueNode* Next;
};
//==============================================================
struct Queue
{//Tạo 1 danh sách các Node
	QueueNode *Head;
	QueueNode *Tail;
};
//==============================================================
QueueNode* createQueueNode(ItemType x)
{//Tạo 1 node mới
	QueueNode* p = new QueueNode;
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
void showQueueNode(QueueNode* p)
{//Hiển thị 1 Node
	printf("%d", p->Info);
}
//==============================================================
void initQueue(Queue& qu)
{//Set địa chỉ Head - Tail
	qu.Head = NULL;
	qu.Tail = NULL;
}
//==============================================================
int isEmpty(Queue qu)
{// Check Queue rỗng hay không 
	//C1 : return qu.Head == NULL ? 1 : 0;
	//C2 :
	if (qu.Head == NULL)
		return 1; // Có
	else
		return 0; // Không
}
//==============================================================
int insert(Queue& qu, QueueNode* p)
{//Chèn vào cuối Queue
	if (p == NULL)
		return 0;
	if (isEmpty(qu) == 1)//Mặc định ở đầu và cuối nếu QueueNode đầu tiên
	{
		qu.Head = p;
		qu.Tail = p;
	}
	else
	{
		qu.Tail->Next = p;
		qu.Tail = p;
	}
	return 1;
}
//==============================================================
void createQueue_InputByHand(Queue& qu)
{//tạo thủ công Queue
	initQueue(qu);
	int n;
	do
	{
		printf("Nhap so luong phan tu cua HANG DOI : ");
		scanf("%d", &n);
		if (n <= 0) printf("Nhap sai roi! Vui long nhap lai.\n");
	} while (n <= 0);
	int i = 0;
	while (i < n)
	{
		ItemType x;
		printf("Nhap gia tri cho Node thu %d: ", i + 1);
		scanf("%d", &x);
		QueueNode* p = createQueueNode(x);
		int kq = insert(qu, p);
		if (kq == 1) i++;
	}
}
//==============================================================
void createQueue_Random(Queue& qu)
{//Chèn ngẫu nhiên Queue
	initQueue(qu);
	int n;
	do
	{
		printf("Nhap so luong phan tu cua HANG DOI : ");
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
		QueueNode* p = createQueueNode(x);
		int kq;
		kq = insert(qu, p);
		if (kq == 1) i++;
	}
}
//==============================================================
void createQueue_FromArray(Queue& qu, ItemType a[], int n)
{//Chèn từ mảng vào Queue
	initQueue(qu);
	int i = 0;
	while (i < n)
	{
		ItemType x;
		x = a[i];
		QueueNode* p = createQueueNode(x);
		int kq = insert(qu, p);
		if (kq == 1) i++;
	}
}
//==============================================================
void createQueue_FromTextFile(Queue& qu, char inputFileName[])
{//Chèn từ file Text vào Queue
	initQueue(qu);
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
		QueueNode* p = createQueueNode(x);
		int kq = insert(qu, p);
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
void interchangeSort_Ascending_Queue(Queue qu)
{//Sắp xếp tăng dần
	for (QueueNode* p = qu.Head; p->Next != NULL; p = p->Next)
	{
		for (QueueNode* q = p->Next; q != NULL; q = q->Next)
		{
			if (p->Info > q->Info)
			{
				swap(p->Info, q->Info);
			}
		}
	}
}
//==============================================================
void selectionSort_Queue_Decending(Queue qu)
{// Sắp xếp giảm dần
	if (isEmpty(qu) == 1 || qu.Head == qu.Tail) return;
	for (QueueNode *p = qu.Head; p != NULL; p = p->Next)
	{
		QueueNode *min = p;
		for (QueueNode *q = p->Next; q != NULL; q = q->Next)
		if (min->Info < q->Info)
			min = q;
		if (min != p)
			swap(min->Info, p->Info);
	}
}
//==============================================================
void showQueue(Queue qu)
{//Hiển thị Queue
	if (isEmpty(qu) == 1)
	{
		printf("HANG DOI rong !");
		return;
	}
	printf("HEAD -> ");
	for (QueueNode* p = qu.Head; p != NULL; p = p->Next)
	{
		showQueueNode(p);
		printf(" -> ");
	}
	printf("NULL");
}
//==============================================================
QueueNode* findQueueNode(Queue qu, ItemType x)
{// Tìm QueueNode
	if (isEmpty(qu) == 1)
	{
		return NULL;
	}
	for (QueueNode* p = qu.Head; p != NULL; p = p->Next)
	{
		if (p->Info == x)
			return p;
	}
	return NULL;
}
//==============================================================
int remove(Queue &qu, ItemType &x)
{
	if (isEmpty(qu) == 1)
		return 0;
	QueueNode *p = qu.Head;
	qu.Head = qu.Head->Next;
	if (qu.Head == NULL)
		qu.Tail = NULL;
	x = p->Info;
	delete p;
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
	printf("\n* 2. Nhap HANG DOI truc tiep tu ban phim                         *");
	printf("\n* 3. Tao HANG DOI phat sinh ngau nhien                           *");
	printf("\n* 4. Tao HANG DOI tu mang 1 chieu                                *");
	printf("\n* 5. Tao HANG DOI tu text file                                   *");
	printf("\n* 6. Them 1 node moi vao dau HANG DOI                            *");
	printf("\n* 7. Xoa phan tu dau tien cua HANG DOI                           *");
	printf("\n* 8. Tim phan tu x trong HANG DOI ?                              *");
	printf("\n* 9. Xem danh sach hien tai                                      *");
	printf("\n******************************************************************");
}
//==============================================================
void process()
{
	int luaChon, kq;
	QueueNode* P, *Q;
	Queue qu;
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
			P = createQueueNode(X);
			showQueueNode(P);
			break;
		case 2:
			createQueue_InputByHand(qu);
			printf("\nNOI DUNG HANG DOI VUA NHAP LA : \n");
			showQueue(qu);
			break;
		case 3:
			createQueue_Random(qu);
			printf("\nNOI DUNG HANG DOI VUA TAO NGAU NHIEN LA : \n");
			showQueue(qu);
			break;
		case 4:
			createQueue_FromArray(qu, A, N);
			printf("\nNOI DUNG HANG DOI VUA TAO TU MANG MOT CHIEU LA : \n");
			showQueue(qu);
			break;
		case 5:
			createQueue_FromTextFile(qu, tenFile);
			printf("\nNOI DUNG HANG DOI VUA TAO TU FILE TEXT LA : \n");
			showQueue(qu);
			break;
		case 6:
			printf("Ban hay cho biet gia tri node muon them vao dau HANG DOI : ");
			scanf("%d", &X);
			P = createQueueNode(X);
			kq = insert(qu, P);
			if (kq == 1)
			{
				printf("\nNOI DUNG HANG DOI SAU KHI THEM %d VAO DAU LA : \n", X);
				showQueue(qu);
			}
			else
			{
				printf("\nKhong the them %d vao dau HANG DOI.", X);
			}
			break;
		case 7:
			kq = remove(qu, X);
			if (kq == 1)
			{
				printf("\nNOI DUNG HANG DOI SAU KHI XOA PHAN TU DAU HANG DOI LA : \n");
				showQueue(qu);
			}
			else
			{
				printf("\nKhong the xoa phan tu dau HANG DOI.");
			}
			break;
		case 8:
			printf("Ban hay cho biet gia tri node can tim trong HANG DOI : ");
			scanf("%d", &X);
			P = findQueueNode(qu, X);
			if (P == NULL)
				printf("Khong tim thay %d trong HANG DOI.", X);
			else
				printf("Da tim thay %d trong HANG DOI tai dia chi %d", X, P);
			break;
		case 9:
			showQueue(qu);
			break;
		}
	} while (luaChon != 0);
}
//==============================================================
void main()
{
	process();
}