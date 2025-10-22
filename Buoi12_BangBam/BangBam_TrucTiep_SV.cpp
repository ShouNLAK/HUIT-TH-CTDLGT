#include "BangBam_TrucTiep_SV.h"

HashNode *createHashNode(ItemType x)
{
	HashNode *p = new HashNode;
	if (!p)
	{
		printf("Khong the cap phat HashNode moi!");
		getch();
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}
//============================================
void deleteHashNode(HashNode *p)
{
	delete p;
}
//============================================
int hashFunction(KeyType key)
{
	int n = strlen(key);
	int sum = 0;
	while (n--) sum = sum + *key++;
	return (sum % KEYSIZE);
}
//============================================
int hashFunction(int key)
{
	return (key % 10);
}
//============================================
void initHashTable(HashTable_DirectChaining &ht)
{
	for (int b = 0; b < KEYSIZE; b++)
		ht.bucket[b] = NULL;
}
//============================================
int isEmptyBucket(HashTable_DirectChaining ht, int b)
{
	if (ht.bucket[b] == NULL)
		return TRUE;
	else
		return FALSE;
}
//============================================
int isEmptyHashTable(HashTable_DirectChaining ht)
{
	for (int b = 0; b < KEYSIZE; b++)
	if (isEmptyBucket(ht, b) != NULL)
		return FALSE;
	return TRUE;
}
//============================================
int push(HashTable_DirectChaining &ht, int b, ItemType x)
{
	HashNode *p = createHashNode(x);
	if (!p) return FALSE;
	p->Next = ht.bucket[b];
	ht.bucket[b] = p;
	return TRUE;
}
//============================================
int insertAfter(HashNode *p, ItemType x)
{
	if (!p)
	{
		printf("Khong them vao HAshNode moi duoc!");
		return 0;
	}
	else
	{
		HashNode *q = createHashNode(x);
		if (!q) return FALSE;
		q->Next = p->Next;
		p->Next = q;
	}
	return TRUE;
}
//============================================
int place(HashTable_DirectChaining &ht, int b, ItemType x)
{
	HashNode *p, *q;
	q = NULL;
	for (p = ht.bucket[b]; p != NULL && strcmp(x.MSSV, p->Info.MSSV) > 0; p = p->Next)
		q = p;
	if (q == NULL)
		push(ht, b, x);
	else
		insertAfter(q, x);
	return 0;
}
//============================================
void insert(HashTable_DirectChaining &ht, ItemType x)
{
	int b;
	b = hashFunction(x.MSSV);
	place(ht, b, x);
}
//============================================
ItemType Search_Item(HashTable_DirectChaining ht, KeyType key)
{
	int b = hashFunction(key);
	HashNode *p = ht.bucket[b];
	while (p != NULL && strcmp(key,p->Info.MSSV) > 0)
		p = p->Next;
	if (p == NULL || strcmp(key, p->Info.MSSV) != 0)
		return{ { "" }, { "" }, 0, 0 };
	else
		return p->Info;
}
//============================================
ItemType pop(HashTable_DirectChaining &ht, int b)
{
	if (isEmptyBucket(ht, b))
	{
		printf("Bucket %d bi rong, khong xoa duoc", b);
		return{ { "" }, { "" }, 0, 0 };
	}
	HashNode *p = ht.bucket[b];
	ItemType key = p->Info;
	ht.bucket[b] = p->Next;
	deleteHashNode(p);
	return key;
}
//============================================
ItemType deleteAfter(HashNode *p)
{
	HashNode *q;
	ItemType k;
	if (p == NULL || p->Next == NULL)
	{
		printf("Khong xoa HashNode duoc");
		return{ { "" }, { "" }, 0, 0 };
	}
	q = p->Next;
	k = q->Info;
	p->Next = q->Next;
	deleteHashNode(q);
	return k;
}
//============================================
int remove(HashTable_DirectChaining &ht, KeyType key)
{
	ItemType x;
	HashNode* p, *q;
	int b = hashFunction(key);
	p = ht.bucket[b];
	q = p;
	while (p != NULL && strcmp(key, p->Info.MSSV) != 0)
	{
		q = p;
		p = p->Next;
	}
	if (p == NULL)
	{
		printf("\nKhong tim thay");
		return FALSE;
	}
	else if (p == ht.bucket[b])
		pop(ht, b);
	else
		deleteAfter(q);
	return TRUE;
}
//============================================
void clearBucket(HashTable_DirectChaining &ht, int b)
{
	HashNode *q = NULL;
	HashNode *p = ht.bucket[b];
	while (p != NULL)
	{
		q = p;
		p = p->Next;
		deleteHashNode(q);
	}
	ht.bucket[b] = NULL;
}
//============================================
void clear(HashTable_DirectChaining &ht)
{
	for (int b = 0; b < KEYSIZE; b++)
		clearBucket(ht, b);
}
//============================================
void traverseBucket(HashTable_DirectChaining ht, int b)
{
	int stt = 1;
	HashNode *p = ht.bucket[b];
	while (p != NULL)
	{
		printf("\n                  %-5d -> ", stt++);
		xuatTTSV(p->Info);
		p = p->Next;
	}
}
//============================================
void traverseHashTable(HashTable_DirectChaining ht)
{
	for (int b = 0; b < KEYSIZE; b++)
	{
		printf("\nBucket [%d] = ", b);
		traverseBucket(ht, b);
	}
}
//============================================
void nhapTTSV(ItemType &x)
{
	printf("Nhap ma so sinh vien : "); fflush(stdin); gets(x.MSSV);
	printf("Nhap ho ten sinh vien : "); fflush(stdin); gets(x.HoVaTen);
	printf("Nhap nam sinh sinh vien : "); scanf("%d", &x.namSinh);
	printf("Nhap diem sinh vien : "); scanf("%d", &x.diem);
}
//============================================
void docTTSV(FILE *fi, ItemType &x)
{
	char strNamSinh[10], strDiem[10];
	fscanf(fi, "%[^#]%*c%[^#]%*c%[^#]%*c%[^\n]%*c\n", &x.MSSV, &x.HoVaTen, strNamSinh, strDiem);
	x.namSinh = atoi(strNamSinh);
	x.diem = atoi(strDiem);
	strcpy(strNamSinh, "");
	strcpy(strDiem, "");
}
//============================================
void xuatTTSV(ItemType x)
{
	printf("%-15s%-30s%8d%15d", x.MSSV, x.HoVaTen, x.namSinh, x.diem);
}
//============================================
void loadTTSV(HashTable_DirectChaining &ht, char fName[])
{
	FILE *fi;
	fi = fopen(fName, "rt");
	if (!fi)
	{
		printf("Loi mo file doc");
		return;
	}
	initHashTable(ht);
	int n;
	fscanf(fi, "%d\n", &n);
	for (int i = 1; i <= n; i++)
	{
		ItemType sv;
		docTTSV(fi, sv);
		insert(ht, sv);
	}
	fclose(fi);
}
//============================================
void xuatDanhSachSV(HashTable_DirectChaining &ht)
{
	printf("                  %-9s%-15s%-30s%-15s%8s", "STT", "MA SO SV", "HO TEN SV", "NAM SINH", "DIEM");
	traverseHashTable(ht);
}