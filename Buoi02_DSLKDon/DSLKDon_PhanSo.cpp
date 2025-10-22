/*
Họ và tên : Nguyễn Lê Anh Khoa
Lớp :		THCTDL&GT - ST4 - A211
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
struct PhanSo
{
	int TuSo;
	int MauSo;
};
typedef PhanSo ItemType;
struct SNode
{//Tạo 1 node
	ItemType Info;
	SNode* Next;
};
//==============================================================
struct SList
{//Tạo 1 danh sách các Node
	SNode *Head;
	SNode *Tail;
};
//==============================================================
void doiDau(ItemType &ps)
{
	if (ps.MauSo < 0)
	{
		ps.TuSo *= -1;
		ps.MauSo *= -1;
	}
}
//==============================================================
int timUCLN(int a, int b)
{
	a = abs(a); b = abs(b);
	while (a != b)
	{
		if (a > b)
		{
			a -= b;
		}
		else
			b -= a;
	}
	return a;
}
//==============================================================
void rutGonPS(ItemType &ps)
{
	int tmp = timUCLN(ps.TuSo, ps.MauSo);
	ps.TuSo /= tmp;
	ps.MauSo /= tmp;
}
//==============================================================
void nhapPS(ItemType &ps)
{
	printf("\nNhap tu so : ");
	scanf("%d", &ps.TuSo);
	do
	{
		printf("Nhap mau so : ");
		scanf("%d", &ps.MauSo);
	} while (ps.MauSo == 0);
	doiDau(ps);
	rutGonPS(ps);
}
//==============================================================
void taoPS(ItemType &ps)
{
	ps.TuSo = rand() % 99 - 50;

	do
	{
		ps.MauSo = rand() % 99 - 50;
	} while (ps.MauSo == 0);
	doiDau(ps);
	rutGonPS(ps);
}
//==============================================================
void xuatPS(ItemType ps)
{
	printf("%d/%d", ps.TuSo, ps.MauSo);
}
//==============================================================
SNode* createSNode(ItemType x)
{//Tạo 1 node mới
	SNode* p = new SNode;
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
void showSNode(SNode* p)
{//Hiển thị 1 Node
	xuatPS(p->Info);
}
//==============================================================
void initSList(SList& sl)
{//Set địa chỉ Head - Tail
	sl.Head = NULL;
	sl.Tail = NULL;
}
//==============================================================
int isEmpty(SList sl)
{// Check SList rỗng hay không 
	return sl.Head == NULL ? 1 : 0;
}
//==============================================================
int insertHead(SList& sl, SNode* p)
{//Chèn lên đầu SList
	if (p == NULL)
		return 0;
	if (isEmpty(sl) == 1) //Mặc định ở đầu và cuối nếu SNode đầu tiên
	{
		sl.Head = p;
		sl.Tail = p;
	}
	else
	{
		p->Next = sl.Head;
		sl.Head = p;
	}
	return 1;
}
//==============================================================
int insertTail(SList& sl, SNode* p)
{//Chèn vào cuối SList
	if (p == NULL)
		return 0;
	if (isEmpty(sl) == 1)//Mặc định ở đầu và cuối nếu SNode đầu tiên
	{
		sl.Head = p;
		sl.Tail = p;
	}
	else
	{
		sl.Tail->Next = p;
		sl.Tail = p;
	}
	return 1;
}
//==============================================================
int insertAfter(SList& sl, SNode* q, SNode* p)
{//Chèn SNode vào sau
	if (q == NULL || p == NULL)
		return 0;
	p->Next = q->Next;
	q->Next = p;
	if (sl.Tail == q) // Trường hợp nó chèn ở Tail
		sl.Tail = p;
	return 1;
}
//==============================================================
int insertBefore(SList& sl, SNode* q, SNode* p)
{//Chèn SNode vào trước
	if (q == NULL || p == NULL)
		return 0;
	if (q == sl.Head)
	{
		insertHead(sl, p);
	}
	else
	{
		SNode* r = sl.Head;
		while (r->Next != q)
		{
			r = r->Next;
		}
		insertAfter(sl, r, p);
	}
	return 1;
}
//==============================================================
void createSList_InputByHand(SList& sl)
{//tạo thủ công SList
	initSList(sl);
	int n;
	do
	{
		printf("Nhap so luong phan tu cua danh sach : ");
		scanf("%d", &n);
		if (n <= 0) printf("Nhap sai roi! Vui long nhap lai.\n");
	} while (n <= 0);
	int i = 0;
	while (i < n)
	{
		ItemType x;
		nhapPS(x);
		SNode* p = createSNode(x);
		int kq;
		if (rand() % 2 == 0)
			kq = insertHead(sl, p);
		else
			kq = insertTail(sl, p);
		if (kq == 1) i++;
	}
}
//==============================================================
void createSList_Random(SList& sl)
{//Chèn ngẫu nhiên SList
	initSList(sl);
	int n;
	do
	{
		printf("Nhap so luong phan tu cua danh sach : ");
		scanf("%d", &n);
		if (n <= 0) printf("Nhap sai roi! Vui long nhap lai.\n");
	} while (n <= 0);
	srand((unsigned)time(NULL));
	int i = 0;
	while (i < n)
	{
		ItemType x;
		taoPS(x);
		SNode* p = createSNode(x);
		int kq;
		if (rand() % 2 == 0)
			kq = insertHead(sl, p);
		else
			kq = insertTail(sl, p);
		if (kq == 1) i++;
	}
}
//==============================================================
void createSList_FromArray(SList& sl, ItemType a[], int n)
{//Chèn từ mảng vào SList
	initSList(sl);
	int i = 0;
	while (i < n)
	{
		ItemType x;
		x = a[i];
		doiDau(x);
		rutGonPS(x);
		SNode* p = createSNode(x);
		int kq;
		if (rand() % 2 == 0)
			kq = insertHead(sl, p);
		else
			kq = insertTail(sl, p);
		if (kq == 1) i++;
	}
}
//==============================================================
void createSList_FromTextFile(SList& sl, char inputFileName[])
{//Chèn từ file Text vào SList
	initSList(sl);
	int n;
	FILE* fi = fopen(inputFileName, "rt");
	if (fi == NULL)
	{
		printf("Loi mo file : %s", inputFileName);
		return;
	}
	fscanf(fi, "%d\n", &n);
	//int i = 0;
	//while (i < n)
	//{
	//	ItemType x;
	//	fscanf(fi, "%d", &x);
	//	SNode* p = createSNode(x);
	//	//int kq = insertHead(sl, p);
	//	int kq = insertTail(sl, p);
	//	if (kq == 1) i++;
	//}
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
int soSanh2PS(ItemType ps1, ItemType ps2)
{
	double temp = ps1.TuSo * ps2.MauSo - ps2.TuSo * ps1.MauSo;
	if (temp > 0)
		return 1;
	else if (temp < 0)
		return -1;
	else
		return 0;
}
//==============================================================
void interchangeSort_Ascending_SList(SList sl)
{//Sắp xếp tăng dần
	for (SNode* p = sl.Head; p->Next != NULL; p = p->Next)
	{
		for (SNode* q = p->Next; q != NULL; q = q->Next)
		{
			if (soSanh2PS(p->Info, q->Info) == 1)
			{
				swap(p->Info, q->Info);
			}
		}
	}
}
//==============================================================
void selectionSort_SList_Decending(SList sl)
{// Sắp xếp giảm dần
	if (isEmpty(sl) == 1 || sl.Head == sl.Tail) return;
	for (SNode *p = sl.Head; p != NULL; p = p->Next)
	{
		SNode *min = p;
		/*for (SNode *q = p->Next; q != NULL; q = q->Next)
		if (min->Info < q->Info)
		min = q;
		if (min != p)
		swap(min->Info, p->Info);*/
	}
}
//==============================================================
void showSList(SList sl)
{//Hiển thị SList
	if (isEmpty(sl) == 1)
	{
		printf("Danh sach rong !");
		return;
	}
	//printf("\nNOI DUNG CUA DANH SACH LA : \n");
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		xuatPS(p->Info);
		printf(" -> ");
	}
	printf("NULL");
}
//==============================================================
SNode* findSNode(SList sl, ItemType x)
{// Tìm SNode
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		if (soSanh2PS(p->Info, x) == 0)
			return p;
	}
	return NULL;
}
//==============================================================
void Tong_SList(SList sl) {
	if (sl.Head == NULL) {
		printf("Danh sach rong\n");
		return;
	}
	ItemType Tong;
	Tong.TuSo = 0;
	Tong.MauSo = 1;
	for (SNode* p = sl.Head; p != NULL; p = p->Next) {
		Tong.TuSo = Tong.TuSo * (p->Info).MauSo + (p->Info).TuSo * Tong.MauSo;
		Tong.MauSo = Tong.MauSo * (p->Info).MauSo;
	}
	rutGonPS(Tong);
	printf("Tong cac phan so trong danh sach = %d/%d\n", Tong.TuSo, Tong.MauSo);
}
//==============================================================
void Tich_SList(SList sl) {
	if (sl.Head == NULL) {
		printf("Danh sach rong\n");
		return;
	}
	ItemType Tich;
	Tich.TuSo = 1;
	Tich.MauSo = 1;
	for (SNode* p = sl.Head; p != NULL; p = p->Next) {
		Tich.TuSo = Tich.TuSo * (p->Info).TuSo;
		Tich.MauSo = Tich.MauSo * (p->Info).MauSo;
	}
	rutGonPS(Tich);
	printf("Tich cac phan so trong danh sach = %d/%d\n", Tich.TuSo, Tich.MauSo);
}
//==============================================================
void Max_Min_SList(SList sl)
{ // Tìm Max - Min
	interchangeSort_Ascending_SList(sl);
	printf("Min = %d/%d\n", (sl.Head)->Info.TuSo, (sl.Head)->Info.MauSo);
	printf("Max = %d/%d\n", (sl.Tail)->Info.TuSo, (sl.Tail)->Info.MauSo);
}
//==============================================================
void Tang_1DV(SList& sl)
{
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		p->Info.TuSo += p->Info.MauSo;
		rutGonPS(p->Info);
	}
	showSList(sl);
}
//==============================================================
void DS_PS_LonHon1(SList sl)
{//Danh sách chẵn - lẻ
	SList LH1;
	initSList(LH1);
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		SNode* q = createSNode(p->Info);
		if (p->Info.TuSo > p->Info.MauSo)
			insertTail(LH1, q);
	}
	printf("\nNOI DUNG DANH SACH CAC PHAN SO LON HON 1 : \n");
	showSList(LH1);
}
//==============================================================
void showMenu()
{
	printf("\n******************************************************************");
	printf("\n*                              MENU                              *");
	printf("\n******************************************************************");
	printf("\n* 0. Thoat chuong trinh                                          *");
	printf("\n* 1. Nhap - Xuat 1 Node                                          *");
	printf("\n* 2. Nhap danh sach truc tiep tu ban phim                        *");
	printf("\n* 3. Tao danh sach phat sinh ngau nhien                          *");
	printf("\n* 4. Tao danh sach tu mang 1 chieu                               *");
	/*printf("\n* 5. Tao danh sach tu text file                                  *");
	printf("\n* 6. Them 1 node moi vao dau danh sach                           *");
	printf("\n* 7. Them 1 node moi vao cuoi danh sach                          *");*/
	printf("\n* 8. Them 1 node moi p vao sau q cua danh sach                   *");
	printf("\n* 9. Them 1 node moi p vao truoc q cua danh sach                 *");
	printf("\n* 10. Sap xep danh sach tang dan voi Interchange Sort            *");/*
																				   printf("\n* 11. Sap xep danh sach giam dan voi Selection Sort              *");*/
	printf("\n* 12. Tim phan tu x trong danh sach ?                            *");
	printf("\n* 13. Tinh tong / tich  trong danh sach                          *");
	printf("\n* 14. Xuat cac phan so lon hon 1                                 *");
	printf("\n* 15. Tim Max - Min trong danh sach                              *");
	printf("\n* 16. Tang moi phan so cua danh sach len 1 don vi                *");
	/*printf("\n* 17. Tao 2 danh sach Chan - Le                                  *");*/
	printf("\n******************************************************************");
}
//==============================================================
void process()
{
	int luaChon, kq;
	SNode* P, *Q;
	SList SL;
	ItemType X, Y;
	ItemType A[] = { { 15, -27 }, { 43, 23 }, { -35, 48 }, { 97, -76 }, { 91, 13 } };
	int N = 5;
	char tenFile[] = "inputFile_PhanSo.txt";
	do
	{
		showMenu();
		printf("\nBan hay lua chon mot chuc nang : ");
		scanf("%d", &luaChon);
		switch (luaChon)
		{
		case 1:
			nhapPS(X);
			P = createSNode(X);
			printf("\nNODE MOI VUA DUOC TAO LA : \n");
			xuatPS(P->Info);
			break;
		case 2:
			createSList_InputByHand(SL);
			printf("\nNOI DUNG DANH SACH VUA NHAP LA : \n");
			showSList(SL);
			break;
		case 3:
			createSList_Random(SL);
			printf("\nNOI DUNG DANH SACH VUA TAO NGAU NHIEN LA : \n");
			showSList(SL);
			break;
		case 4:
			createSList_FromArray(SL, A, N);
			printf("\nNOI DUNG DANH SACH VUA TAO TU MANG MOT CHIEU LA : \n");
			showSList(SL);
			break;
			/*case 5:
			createSList_FromTextFile(SL, tenFile);
			printf("\nNOI DUNG DANH SACH VUA TAO TU FILE TEXT LA : \n");
			showSList(SL);
			break;

			case 6:
			printf("Ban hay cho biet gia tri node muon them vao dau danh sach : ");
			scanf("%d", &X);
			P = createSNode(X);
			kq = insertHead(SL, P);
			if (kq == 1)
			{
			printf("\nNOI DUNG DANH SACH SAU KHI THEM %d VAO DAU LA : \n", X);
			showSList(SL);
			}
			else
			{
			printf("\nKhong the them %d vao dau danh sach.", X);
			}
			break;
			case 7:
			printf("Ban hay cho biet gia tri node muon them vao cuoi danh sach : ");
			scanf("%d", &X);
			P = createSNode(X);
			kq = insertTail(SL, P);
			if (kq == 1)
			{
			printf("\nNOI DUNG DANH SACH SAU KHI THEM %d VAO CUOI LA : \n", X);
			showSList(SL);
			}
			else
			{
			printf("\nKhong the them %d vao cuoi danh sach.", X);
			}
			break;
			*/
		case 8:
			printf("Ban hay cho biet gia tri node muon them vao danh sach : ");
			nhapPS(Y);
			P = createSNode(Y);
			printf("Ban hay cho biet gia tri node ke truoc trong danh sach : ");
			nhapPS(X);
			Q = findSNode(SL, X);
			kq = insertAfter(SL, Q, P);
			if (kq == 1)
			{
				printf("\nNOI DUNG DANH SACH SAU KHI THEM %d/%d VAO SAU %d/%d LA : \n", Y.TuSo, Y.MauSo, X.TuSo, X.MauSo);
				showSList(SL);
			}
			else
			{
				printf("\nKhong the them %d/%d vao sau %d/%d trong danh sach.", Y.TuSo, Y.MauSo, X.TuSo, X.MauSo);
			}
			break;
		case 9:
			printf("Ban hay cho biet gia tri node muon them vao danh sach : ");
			nhapPS(Y);
			P = createSNode(Y);
			printf("Ban hay cho biet gia tri node ke sau trong danh sach : ");
			nhapPS(X);
			Q = findSNode(SL, X);
			kq = insertBefore(SL, Q, P);
			if (kq == 1)
			{
				printf("\nNOI DUNG DANH SACH SAU KHI THEM %d/%d VAO TRUOC %d/%d LA : \n", Y.TuSo, Y.MauSo, X.TuSo, X.MauSo);
				showSList(SL);
			}
			else
			{
				printf("\nKhong the them %d/%d vao truoc %d/%d trong danh sach.", Y.TuSo, Y.MauSo, X.TuSo, X.MauSo);
			}
			break;

		case 10:
			interchangeSort_Ascending_SList(SL);
			printf("\nNOI DUNG DANH SACH SAU KHI SAP XEP TANG DAN VOI INTERCHANGE SORT LA : \n");
			showSList(SL);
			break;
			/*
			case 11:
			selectionSort_SList_Decending(SL);
			printf("\nNOI DUNG DANH SACH SAU KHI SAP XEP GIAM DAN VOI SELECTION SORT LA : \n");
			showSList(SL);
			break;
			*/
		case 12:
			printf("Ban hay cho biet gia tri node can tim trong danh sach : ");
			nhapPS(X);
			P = findSNode(SL, X);
			if (P == NULL)
				printf("Khong tim thay %d/%d trong danh sach.", X.TuSo, X.MauSo);
			else
				printf("Da tim thay %d/%d trong danh sach tai dia chi %d", X.TuSo, X.MauSo, P);
			break;
		case 13:
			Tong_SList(SL);
			Tich_SList(SL);
			break;
		case 14:
			DS_PS_LonHon1(SL);
			break;
		case 15:
			Max_Min_SList(SL);
			break;
		case 16:
			Tang_1DV(SL);
			break;
			/*case 17:
			tao2DSChanle(SL);
			break;*/
		}
	} while (luaChon != 0);
}
//==============================================================
void main()
{
	process();
}