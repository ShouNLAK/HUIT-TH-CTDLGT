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

struct BaiHat
{
	char TenBH[51], TenTG[51], TenCS[51];
	int ThoiLuong;
};
typedef BaiHat ItemType;
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
void nhapThongTinBH(ItemType &x)
{
	printf("Nhap ten bai hat : "); fflush(stdin); gets(x.TenBH);
	printf("Nhap ten tac gia : "); fflush(stdin); gets(x.TenTG);
	printf("Nhap ten ca si : "); fflush(stdin); gets(x.TenCS);
	printf("Nhap thoi luong (Giay) : "); scanf("%d", &x.ThoiLuong);
}
//==============================================================
void loadThongTinBH(FILE *fi,ItemType &x)
{
	fscanf(fi, "%[^#]%*c%[^#]%*c%[^#]%*c%d\n", x.TenBH, x.TenTG, x.TenCS, &x.ThoiLuong);
}
//==============================================================
void xuatThongTinBH(ItemType x)
{
	printf("%-30s%-30s%-30s%-10d (giay)", x.TenBH, x.TenTG, x.TenCS, x.ThoiLuong);
}
//==============================================================
void saveThongTinBH(FILE *fo,ItemType x)
{
	fprintf(fo,"%s#%s#%s#%d\n", x.TenBH, x.TenTG, x.TenCS, x.ThoiLuong);
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
	xuatThongTinBH(p->Info);
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
	p->Next = q;
	for (SNode* k = sl.Head; k != NULL; k = k->Next)
	{
		if (k->Next == q)
		{
			k->Next = p;
			break;
		}
	}
	if (sl.Head == q) // Trường hợp nó chèn ở Head
		sl.Head = p;
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
		nhapThongTinBH(x);
		SNode* p = createSNode(x);
		int kq = insertTail(sl, p);
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
	int i = 0;
	while (i < n)
	{
		ItemType x;
		loadThongTinBH(fi, x);
		SNode* p = createSNode(x);
		int kq = insertTail(sl, p);
		if (kq == 1) i++;
	}
	fclose(fi);
	
}
//==============================================================
int countSNode(SList sl)
{
	int count = 0;
	for (SNode *p = sl.Head; p != NULL; p = p->Next)
		count++ ;
	return count;
}
//==============================================================
void saveSList_ToTextFile(SList& sl, char inputFileName[])
{
	int n;
	FILE* fo = fopen(inputFileName, "wt");
	if (fo == NULL)
	{
		printf("Loi mo file : %s", inputFileName);
		return;
	}
	n = countSNode(sl);
	fprintf(fo, "%d\n", n);
	int i = 0;
	for (SNode *p = sl.Head; p != NULL; p = p->Next)
		saveThongTinBH(fo,p->Info);
	fclose(fo);

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
void interchangeSort_Ascending_SList_TheoTenBH(SList sl)
{//Sắp xếp tăng dần
	for (SNode* p = sl.Head; p->Next != NULL; p = p->Next)
	{
		for (SNode* q = p->Next; q != NULL; q = q->Next)
		{
			if (stricmp(p->Info.TenBH, q->Info.TenBH) > 0)
			{
				swap(p->Info, q->Info);
			}
		}
	}
}
//==============================================================
void selectionSort_SList_Decending_TheoTenCS(SList sl)
{// Sắp xếp giảm dần
	if (isEmpty(sl) == 1 || sl.Head == sl.Tail) return;
	for (SNode *p = sl.Head; p != NULL; p = p->Next)
	{
		SNode *min = p;
		for (SNode *q = p->Next; q != NULL; q = q->Next)
			if (stricmp(p->Info.TenCS, q->Info.TenCS) < 0)
				min = q;
		if (min != p)
			swap(min->Info, p->Info);
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
	printf("%-5s%-30s%-30s%-30s%-10s\n", "STT", "TEN BAI HAT", "TEN TAC GIA", "TEN CA SY", "THOI LUONG");
	int stt = 1;
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		printf("\n%-5d", stt++);
		showSNode(p);
	}
}
//==============================================================
SNode* findSNode_TheoTenBH(SList sl,char tenBH[] )
{// Tìm SNode
	for (SNode* p = sl.Head; p != NULL; p = p->Next)
	{
		if (stricmp(p->Info.TenBH,tenBH) == 0)
			return p;
	}
	return NULL;
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
int deleteTail(SList &sl, ItemType &x)
{
	if (isEmpty(sl) == 1)
		return 0;
	SNode *q = sl.Head;
	SNode *p = sl.Tail;
	if (q == p)
		sl.Head = sl.Tail = NULL;
	while (q->Next != p)
		q = q->Next;
	sl.Tail = q;
	sl.Tail->Next = NULL;
	x = p->Info;
	delete p;
	return 1;
}
//==============================================================
int deleteBefore(SList &sl, SNode *q, ItemType &x)
{
	if (isEmpty(sl) == 1)
		return 0;
	if (q == NULL)
		return 0;
	if (q == sl.Head)
		return 0;
	if (sl.Head->Next == q)
		return deleteHead(sl, x);
	SNode *r = sl.Head;
	SNode *p = r->Next;
	while (p->Next != q)
	{
		r = p;
		p = p->Next;
	}
	r->Next = q;
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
int deleteSNodeX(SList &sl, ItemType x)
{
	if (isEmpty(sl) == 1)
		return 0;
	SNode *p = sl.Head;
	SNode *q = NULL;
	while ((p != NULL) && (stricmp(p->Info.TenBH , x.TenBH)))
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
int Time_SList(SList sl)
{
	int sum = 0;
	for (SNode *p = sl.Head; p != NULL; p = p->Next)
		sum += p->Info.ThoiLuong;
	return sum;
}
//==============================================================
int pushTop_SList(SList &sl, SNode* p)
{
	if (p == NULL)
		return 0;
	if (p == sl.Head)
		return 1;
	for (SNode *q = sl.Head; q != NULL; q = q->Next)
		if (stricmp(q->Next->Info.TenBH, p->Info.TenBH) == 0)
		{
			q->Next = p->Next;
			break;
		}
	p->Next = sl.Head;
	sl.Head = p;
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
	printf("\n* 2. Nhap danh sach truc tiep tu ban phim                        *");
	printf("\n* 3. Lay thong tin 1 bai hat tu text file                        *");
	printf("\n* 4. Lay danh sach bai hat tu text file                          *");
	printf("\n* 5. Xem danh sach bai hat                                       *");
	printf("\n* 6. Luu danh sach bai hat                                       *");
	printf("\n* 7. Them mot bai hat moi vao cuoi danh sach                     *");
	printf("\n* 8. Them mot bai hat moi vao dau danh sach                      *");
	printf("\n* 9. Tim ten bai hat trong danh sach                             *");
	printf("\n* 10. Sap xep danh sach ten bai hat tang dan                     *");
	printf("\n* 11. Sap xep bai hat theo ten ca sy trong danh sach giam dan    *");
	printf("\n* 12. Tinh tong thoi luong cac bai hat                           *");
	printf("\n* 13. Xoa 1 bai hat trong danh sach                              *");
	printf("\n* 14. Dua mot bai hat co san len dau danh sach                   *");
	printf("\n******************************************************************");
}
//==============================================================
void process()
{
	FILE*fi;
	int luaChon, kq;
	SNode* P, *Q;
	SList SL;
	ItemType X, Y;
	char tenBaiHat[51];
	char inputFileName[] = "inputFile_1BaiHat.txt";
	char inputFileName_ds[] = "inputFile_dsBaiHat.txt";
	char tenFile[] = "inputFile_SoNguyen.txt";
	do
	{
		showMenu();
		printf("\nBan hay lua chon mot chuc nang : ");
		scanf("%d", &luaChon);
		switch (luaChon)
		{
		case 1:
			nhapThongTinBH(X);
			P = createSNode(X);
			showSNode(P);
			break;
		case 2:
			createSList_InputByHand(SL);
			printf("\nNOI DUNG DANH SACH VUA NHAP LA : \n");
			showSList(SL);
			break;
		case 3:
			fi = fopen(inputFileName, "rt");
			if (fi == NULL)
			{
				printf("Khong the mo file!\n");
				return;
			}
			loadThongTinBH(fi, X);
			P = createSNode(X);
			printf("THONG TIN BAI HAT DUOC NHAP TU TEXT FILE :\n");
			showSNode(P);
			fclose(fi);
			break;
		case 4:
			createSList_FromTextFile(SL, inputFileName_ds);
			showSList(SL);
			break;
		case 5:
			printf("NOI DUNG DANH SACH LA \n");
			showSList(SL);
			break;
		case 6:
			saveSList_ToTextFile(SL, inputFileName_ds);
			printf("Luu thanh cong");
			break;
		case 7:
			nhapThongTinBH(X);
			P = createSNode(X);
			showSNode(P);
			kq = insertTail(SL, P);
			if (kq == 0)
				printf("Khong the them bai hat moi");
			else
			{
				printf("NOI DUNG DANH SACH VUA SAU KHI THEM 1 BAI HAT MOI (VAO CUOI) LA :\n");
				showSList(SL);
			}
			break;
		case 8:
			nhapThongTinBH(X);
			P = createSNode(X);
			showSNode(P);
			kq = insertHead(SL, P);
			if (kq == 0)
				printf("Khong the them bai hat moi");
			else
			{
				printf("NOI DUNG DANH SACH VUA SAU KHI THEM 1 BAI HAT MOI (VAO DAU) LA :\n");
				showSList(SL);
			}
			break;
		case 9:
			printf("Ban hay cho biet ten bai hat can tim trong danh sach : ");
			fflush(stdin);
			gets(tenBaiHat);
			P = findSNode_TheoTenBH(SL, tenBaiHat);
			if (P == NULL)
				printf("Khong tim thay ten bai hat : %s trong danh sach.",tenBaiHat);
			else
			{
				printf("Da tim thay ten bai hat : %s trong danh sach\n", tenBaiHat);
				showSNode(P);
			}
			break;
		case 10:
			interchangeSort_Ascending_SList_TheoTenBH(SL);
			printf("\nNOI DUNG DANH SACH SAU KHI SAP XEP TANG DAN THEO TEN BAI HAT LA : \n");
			showSList(SL);
			break;
		case 11:
			selectionSort_SList_Decending_TheoTenCS(SL);
			printf("\nNOI DUNG DANH SACH SAU KHI SAP XEP GIAM DAN THEO TEN CA SY LA : \n");
			showSList(SL);
			break;
		case 12:
			kq = Time_SList(SL);
			printf("Tong thoi luong danh sach bai hat : %d", kq);
			break;
		case 13:
			printf("Nhap gia tri ten bai hat muon xoa : ");
			fflush(stdin);
			gets(X.TenBH);
			kq = deleteSNodeX(SL,X);
			if (kq == 1)
			{
				printf("\nNOI DUNG DANH SACH SAU KHI XOA BAI HAT : %s TRONG DANH SACH LA : \n", X.TenBH);
				showSList(SL);
			}
			else
				printf("\nKhong the xoa bai hat : %s trong danh sach.", X.TenBH);
			break;
		case 14:
			printf("Nhap gia tri ten bai hat chen len dau : ");
			fflush(stdin);
			gets(tenBaiHat);
			Q = findSNode_TheoTenBH(SL,tenBaiHat);
			kq = pushTop_SList(SL, Q);
			if (kq == 1)
			{
				printf("\nNOI DUNG DANH SACH SAU KHI CHEN BAI HAT : %s DAU DANH SACH LA : \n", tenBaiHat);
				showSList(SL);
			}
			else
				printf("\nKhong the chen bai hat : %s dau danh sach.",tenBaiHat);
			break;
			
			}
		} while (luaChon != 0);
	}
	//==============================================================
	void main()
	{
		process();
	}