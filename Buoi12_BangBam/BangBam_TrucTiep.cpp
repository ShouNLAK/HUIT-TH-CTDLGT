#include "BangBam_TrucTiep.h"

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
int hashFunction(KeyType Info)
{
	return (Info % KEYSIZE);
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
	if (Search_Item(ht, x) != -1) return 0;
	HashNode *p, *q;
	q = NULL;
	for (p = ht.bucket[b]; p != NULL && x > p->Info; p = p->Next)
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
	b = hashFunction(x);
	place(ht, b, x);
}
//============================================
ItemType Search_Item(HashTable_DirectChaining ht, KeyType k)
{
	int b = hashFunction(k);
	HashNode *p = ht.bucket[b];
	while (p != NULL && k > p->Info)
		p = p->Next;
	if (p == NULL || k != p->Info)
		return -1;
	else
		return p->Info;
}
//============================================
int pop(HashTable_DirectChaining &ht, int b)
{
	if (isEmptyBucket(ht, b))
	{
		printf("Bucket %d bi rong, khong xoa duoc", b);
		return -1;
	}
	HashNode *p = ht.bucket[b];
	ItemType k = p->Info;
	ht.bucket[b] = p->Next;
	deleteHashNode(p);
	return k;
}
//============================================
int deleteAfter(HashNode *p)
{
	HashNode *q;
	ItemType k;
	if (p == NULL || p->Next == NULL)
	{
		printf("Khong xoa HashNode duoc");
		return FALSE;
	}
	q = p->Next;
	k = q->Info;
	p->Next = q->Next;
	deleteHashNode(q);
	return TRUE;
}
//============================================
int remove(HashTable_DirectChaining &ht, KeyType k)
{
	ItemType x;
	HashNode* p, *q;
	int b = hashFunction(k);
	p = ht.bucket[b];
	q = p;
	while (p != NULL && k != p->Info)
	{
		q = p;
		p = p->Next;
	}
	if (p == NULL)
	{
		printf("\nKhong tim thay khoa la %d", b);
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
	HashNode *p = ht.bucket[b];
	while (p != NULL)
	{
		printf("%d -> ", p->Info);
		p = p->Next;
	}
	printf("NULL");
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
void loadFileText(HashTable_DirectChaining &ht, char fName[])
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
	for (int i = 1; i <= n;i++)
	{
		ItemType X;
		fscanf(fi, "%d", &X);
		insert(ht, X);
	}
	fclose(fi);
}