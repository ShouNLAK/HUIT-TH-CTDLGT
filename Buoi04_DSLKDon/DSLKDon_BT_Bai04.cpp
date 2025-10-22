/*
Họ và tên : Nguyễn Lê Anh Khoa
Lớp :		THCTDL&GT - ST4 - A211
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <string.h>

struct DiemHP
{
	float DTL,DGK, DCK;
	float diemHP;
};
struct HocPhan
{
	char MaHP[11], TenHP[50];
	int TinChi;
	struct DiemHP Diem;
};
//==============================================================
struct SNodeKQ_HP
{
	HocPhan Info;
	SNodeKQ_HP* Next;
};
struct SListKQ_HP
{
	SNodeKQ_HP *Head;
	SNodeKQ_HP *Tail;
};
//==============================================================

struct SinhVien
{
	char MSSV[11], Ho[26], Ten[9];
	int namSinh;
	SListKQ_HP diemKQ;
};
//==============================================================
typedef SinhVien ItemType;
struct SNode
{//Tạo 1 node
	ItemType Info;
	SNode* Next;
};
struct SList
{//Tạo 1 danh sách các Node
	SNode *Head;
	SNode *Tail;
};
//==============================================================
SNodeKQ_HP* createBSTNodeKQ(HocPhan x)
{//Tạo 1 node mới
	SNodeKQ_HP* p = new SNodeKQ_HP;
	if (p == NULL)
	{
		printf("Khong the cap phat bo nho !");
		getch();
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
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
void initSListKQ(SListKQ_HP& sl)
{//Set địa chỉ Head - Tail
	sl.Head = NULL;
	sl.Tail = NULL;
}
//==============================================================
int isEmptyKQ(SListKQ_HP sl)
{// Check SList rỗng hay không 
	//C1 : return sl.Head == NULL ? 1 : 0;
	//C2 :
	if (sl.Head == NULL)
		return 1; // Có
	else
		return 0; // Không
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
	//C1 : return sl.Head == NULL ? 1 : 0;
	//C2 :
	if (sl.Head == NULL)
		return 1; // Có
	else
		return 0; // Không
}
//==============================================================
int insertTailSListKQ(SListKQ_HP& sl, SNodeKQ_HP* p)
{//Chèn vào cuối SList
	if (p == NULL)
		return 0;
	if (isEmptyKQ(sl) == 1)//Mặc định ở đầu và cuối nếu SNode đầu tiên
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
void nhapDuLieuHP_SV(HocPhan &x)
{
	printf("Nhap Ma hoc phan : "); fflush(stdin); gets(x.MaHP);
	printf("Nhap Ten hoc phan : "); fflush(stdin); gets(x.TenHP);
	srand((unsigned)time(NULL));
	x.TinChi = rand() % 5 + 1;
	printf("So tin chi : %d", x.TinChi);
	//printf("Nhap so tin chi : ");scanf("%d",&x.TinChi);
	x.Diem.DTL = rand() % 101 * 0.1;
	x.Diem.DCK = rand() % 101 * 0.1;
	if (x.TinChi <= 2)
	{
		x.Diem.DGK = 0;
		x.Diem.diemHP = x.Diem.DTL *0.3 + x.Diem.DCK * 0.7;
	}
	else
	{
		x.Diem.DGK = rand() % 101 * 0.1;
		x.Diem.diemHP = x.Diem.DTL *0.2 + x.Diem.DCK*0.3 + x.Diem.DCK * 0.5;
	}
	printf("\n Diem hoc phan : %.2f\n", x.Diem.diemHP);

}
//==============================================================
void nhapDiemSV(SListKQ_HP &sl)
{
	initSListKQ(sl);
	int sm, kq;
	do
	{
		printf("Nhap so luong mon hoc : ");
		scanf("%d", &sm);
	} while (sm <= 0);
	for (int i = 0; i < sm; i++)
	{
		HocPhan X;
		nhapDuLieuHP_SV(X);
		SNodeKQ_HP *p = createBSTNodeKQ(X);
		kq = insertTailSListKQ(sl, p);
		if (kq == 0) printf("Khong the them hoc phan nay !");
	}
}
//==============================================================
void nhapThongTinSV(ItemType &x)
{
	printf("Nhap Ma sinh vien : "); fflush(stdin); gets(x.MSSV);
	printf("Nhap Ho dem cua sinh vien : "); fflush(stdin); gets(x.Ho);
	printf("Nhap Ten sinh vien : "); fflush(stdin); gets(x.Ten);
	printf("Nhap nam sinh cua sinh vien : "); scanf("%d", &x.namSinh);
	nhapDiemSV(x.diemKQ);
}
//==============================================================
float tinhDTB(SListKQ_HP sl)
{
	int TinChi = 0;
	float TongDiem = 0;
	for (SNodeKQ_HP *p = sl.Head; p; p = p->Next)
	{
		HocPhan x = p->Info;
		TinChi += x.TinChi;
		TongDiem += x.Diem.diemHP * x.TinChi;
	}
	return (TinChi > 0) ? (float)(TongDiem / TinChi) : 0;
}
//==============================================================
void xuatKQ(HocPhan x)
{
	printf("%-12s%-35s%-10d%-8.1f%-8.1f%-8.1f%-8.1f|", x.MaHP, x.TenHP, x.TinChi, x.Diem.DTL, x.Diem.DCK, x.Diem.DCK, x.Diem.diemHP);
}
//==============================================================
void xuatDiem(SListKQ_HP sl)
{
	printf("\n\tKet qua hoc tap :");
	printf("\n|-----------------------------------------------------------------------------------------------------|");
	printf("\n|\t%-5s%-12s%-35s%-10s%-8s%-8s%-8s%-8s|", "STT", "MA HP", "TEN HOC PHAN", "SO TC", "DTL", "DGK", "DCK", "DTB");
	int i = 1;
	for (SNodeKQ_HP *p = sl.Head; p != NULL; p = p->Next)
	{
		printf("\n|\t%-5d", i++);
		xuatKQ(p->Info);
	}
}
//==============================================================
void xuatThongTinSV(SinhVien x)
{
	float DTB = tinhDTB(x.diemKQ);
	printf("%-12s%-23s%-10s%10.1f\n", x.MSSV, x.Ho, x.Ten, DTB);
	printf("|-----------------------------------------------------------------------------------------------------|");
	xuatDiem(x.diemKQ);
	printf("\n|-----------------------------------------------------------------------------------------------------|\n\n\n");
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
void createSList_InputByHand(SList& sl)
{//tạo thủ công SList
	initSList(sl);
	int n;
	do
	{
		printf("Nhap so luong sinh vien cua danh sach : ");
		scanf("%d", &n);
		if (n <= 0) printf("Nhap sai roi! Vui long nhap lai.\n");
	} while (n <= 0);
	int i = 0;
	while (i < n)
	{
		ItemType x;
		nhapThongTinSV(x);
		SNode* p = createSNode(x);
		//int kq = insertHead(sl, p);
		int kq = insertTail(sl, p);
		if (kq == 1) i++;
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
	int i = 1;
	//printf("\nNOI DUNG CUA DANH SACH LA : \n");
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		printf("\n|-----------------------------------------------------------------------------------------------------|");
		printf("\n\t\t%-5d",i++);
		xuatThongTinSV(p->Info);
	}
}
//==============================================================
int timThongTinSV(SList sl)
{
	char MSSV[11];
	printf("Nhap ma so sinh vien can tim : "); fflush(stdin); gets(MSSV);
	for (SNode *p = sl.Head; p != NULL; p = p->Next)
	{
		if (strcmp(p->Info.MSSV, MSSV) == 0)
		{
			printf("Da tim thay thong tin ve sinh vien \n");
			xuatThongTinSV(p->Info);
			return 1;
		}
	}
	return 0;
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
void interchangeSort_Ascending_SList_MSSV(SList sl)
{//Sắp xếp tăng dần
	for (SNode* p = sl.Head; p->Next != NULL; p = p->Next)
	{
		for (SNode* q = p->Next; q != NULL; q = q->Next)
		{
			if (strcmp(p->Info.MSSV,q->Info.MSSV) > 0)
			{
				swap(p->Info, q->Info);
			}
		}
	}
}
//==============================================================
void selectionSort_SList_Ascending_TenSV(SList sl)
{
	if (isEmpty(sl) == 1 || sl.Head == sl.Tail) return;
	for (SNode *p = sl.Head; p != NULL; p = p->Next)
	{
		SNode *max = p;
		for (SNode *q = p->Next; q != NULL; q = q->Next)
		if (strcmp(max->Info.Ten, q->Info.Ten) < 0)
			max = q;
		if (max != p)
			swap(max->Info, p->Info);
	}
}
//==============================================================
void add_SV(SList sl)
{
	interchangeSort_Ascending_SList_MSSV(sl);
	ItemType x;
	nhapThongTinSV(x);
	for (SNode *p = sl.Head; p != NULL; p = p->Next)
	{
		if (stricmp(p->Info.MSSV, x.MSSV) == 0)
			return;
	}
	SNode *p = createSNode(x);
	insertTail(sl, p);
}
//==============================================================
int deleteHead(SList &sl, ItemType &x)
{
	if (isEmpty(sl) == 1)
		return 0;
	SNode *p = sl.Head;
	sl.Head = sl.Head->Next;
	if (sl.Head == NULL)
		sl.Tail = NULL;
	x = p->Info;
	delete p;
	return 1;
}
//==============================================================
int deleteAfter(SList &sl, SNode *q, ItemType &x)
{
	if (q == NULL || q->Next == NULL)
		return 0;
	SNode *p = q->Next;
	q->Next = p->Next;
	if (sl.Tail == p)
		sl.Tail = q;
	x = p->Info;
	delete p;
	return 1;
}
//==============================================================
int deleteTTSV_MSSV(SList &sl, ItemType x)
{
	if (isEmpty(sl) == 1)
		return 0;
	SNode *p = sl.Head;
	SNode *q = NULL;
	while ((p != NULL) && (stricmp(p->Info.MSSV, x.MSSV)))
	{
		q = p;
		p = p->Next;
	}
	if (p == NULL)
		return 0;
	if (p == sl.Head)
		deleteHead(sl, x);
	else
		deleteAfter(sl, q, x);
	return 1;
}
//==============================================================
int deleteTTSV_Ten(SList &sl, ItemType x)
{
	if (isEmpty(sl) == 1)
		return 0;
	SNode *p = sl.Head;
	SNode *q = NULL;
	while ((p != NULL) && (stricmp(p->Info.Ten, x.Ten) == 0))
	{
		q = p;
		p = p->Next;
		if (q == sl.Head)
			deleteHead(sl, x);
		else if (q != NULL)
			deleteAfter(sl, q, x);
	}
	if (p == NULL)
		return 0;
	return 1;
}
//==============================================================
void taoDS_Diem_Decreasing(SList sl)
{//Danh sách chẵn - lẻ
	SList DiemGD;
	initSList(DiemGD);
	for (SNode *p = sl.Head; p != NULL; p = p->Next)
	{
		SNode *q = createSNode(p->Info);
		insertTail(DiemGD, q);
	}
	for (SNode* p = DiemGD.Head; p->Next != NULL; p = p->Next)
		for (SNode* q = p->Next; q != NULL; q = q->Next)
		if (tinhDTB(p->Info.diemKQ) < tinhDTB(q->Info.diemKQ))
			swap(p->Info, q->Info);
	printf("\nNOI DUNG DANH SACH SINH VIEN CO DIEM GIAM DAN : \n");
	showSList(DiemGD);
}
//==============================================================
void DS_SV_Kha(SList sl)
{
	for (SNode *p = sl.Head; p != NULL; p = p->Next)
	{
		int DTB = tinhDTB(p->Info.diemKQ);
		if (DTB >= 7.0 && DTB < 8.5)
			xuatThongTinSV(p->Info);
	}
}
//==============================================================
void SV_Max_Min(SList sl)
{
	for (SNode* p = sl.Head; p->Next != NULL; p = p->Next)
		for (SNode* q = p->Next; q != NULL; q = q->Next)
			if (tinhDTB(p->Info.diemKQ) < tinhDTB(q->Info.diemKQ))
				swap(p->Info, q->Info);
}
//==============================================================
void SV_Gioi_Min(SList sl)
{
	SList Gioi;
	initSList(Gioi);
	for (SNode *p = sl.Head; p != NULL; p = p->Next)
	{
		if (tinhDTB(p->Info.diemKQ) >= 8.5)
		{
			SNode *q = createSNode(p->Info);
			insertTail(Gioi, q);
		}
	}
	SV_Max_Min(Gioi);
	SNode *p = Gioi.Tail;
	if (p == NULL)
		printf("Khong co sinh vien nao");
	else
		printf("Sinh vien gioi co ket qua thap nhat la : \n"); xuatThongTinSV(p->Info);
}
//==============================================================
void near_DTB(SList sl)
{
	int DTB;
	printf("Nhap diem trung binh ban can tim : "); scanf("%.1f", &DTB);
	SV_Max_Min(sl);
	for (SNode *p = sl.Head; p != NULL; p = p->Next)
	{

	}

}
//==============================================================
void showMenu()
{
	printf("\n******************************************************************");
	printf("\n*                              MENU                              *");
	printf("\n******************************************************************");
	printf("\n* 0. Thoat chuong trinh                                          *");
	printf("\n* 1. Nhap thong tin sinh vien va diem                            *");
	printf("\n* 2. Xuat thong tin sinh vien va diem                            *");
	printf("\n* 3. Tim thong tin sinh vien                                     *");
	printf("\n* 4. Sap xep sinh vien tang dan theo MSSV                        *");
	printf("\n* 5. Sap xep sinh vien tang dan theo Ten                         *");
	printf("\n* 6. Them sinh vien ma van giu tang dan cua ma                   *");
	printf("\n* 7. Xoa thong tin sinh vien theo MSSV                           *");
	printf("\n* 8. Xoa thong tin sinh vien theo Ten                            *");
	printf("\n* 9. Danh sach sinh vien theo diem giam dan                      *");
	printf("\n* 10. Danh sach sinh vien xep loai kha                           *");
	printf("\n* 11. Sinh vien co ket qua hoc tap cao nhat - thap nhat          *");
	printf("\n* 12. Sinh vien gioi co ket qua hoc tap thap nhat                *");
	printf("\n******************************************************************");
}
//==============================================================
void process()
{
	ItemType X, Y;
	SNode* p, q;
	int Chon, kq;
	SList SL;
	initSList(SL);
	do
	{
		showMenu();
		printf("\n Chon mot chuc nang : ");
		scanf("%d", &Chon);
		switch (Chon)
		{
		case 1:
			createSList_InputByHand(SL);
			showSList(SL);
			break;
		case 2:
			showSList(SL);
			break;
		case 3:
			kq = timThongTinSV(SL);
			if (kq == 0) printf("Khong tim thay sinh vien nao");
			break;
		case 4:
			interchangeSort_Ascending_SList_MSSV(SL);
			showSList(SL);
			break;
		case 5:
			selectionSort_SList_Ascending_TenSV(SL);
			showSList(SL);
			break;
		case 6:
			add_SV(SL);
			break;
		case 7:
			printf("Nhap ma so sinh vien can xoa : "); fflush(stdin); gets(X.MSSV);
			deleteTTSV_MSSV(SL, X);
			showSList(SL);
			break;
		case 8:
			printf("Nhap ten sinh vien can xoa : "); fflush(stdin); gets(X.Ten);
			deleteTTSV_Ten(SL, X);
			showSList(SL);
			break;
		case 9:
			taoDS_Diem_Decreasing(SL);
			break;
		case 10:
			DS_SV_Kha(SL);
			break;
		case 11:
			SV_Max_Min(SL);
			printf("Sinh vien co ket qua hoc tap cao nhat : \n"); xuatThongTinSV(SL.Head->Info);
			printf("Sinh vien co ket qua hoc tap thap nhat : \n"); xuatThongTinSV(SL.Tail->Info);
			break;
		case 12:
			SV_Gioi_Min(SL);
			break;
		}
	} while (Chon != 0);
}
//==============================================================

void main()
{
	process();
}