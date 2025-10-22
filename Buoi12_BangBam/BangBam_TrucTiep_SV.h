#ifndef HashTable_TrucTiep_SV_h
#define HashTable_TrucTiep_SV_h

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef char KeyType[11];

#define TRUE 1
#define FALSE 0
#define KEYSIZE 10

struct SinhVien
{
	KeyType MSSV;
	char HoVaTen[30];
	int namSinh;
	int diem;
};

typedef SinhVien ItemType;

struct HashNode
{
	ItemType Info;
	HashNode* Next;
};

struct HashTable_DirectChaining
{
	HashNode *bucket[KEYSIZE];
};

HashNode *createHashNode(ItemType x);
void deleteHashNode(HashNode *p);
int hashFunction(KeyType Info);
void initHashTable(HashTable_DirectChaining &ht);
int isEmptyBucket(HashTable_DirectChaining ht, int b);
int isEmptyHashTable(HashTable_DirectChaining ht);
int push(HashTable_DirectChaining &ht, int b, ItemType x);
int insertAfter(HashNode *p, ItemType x);
int place(HashTable_DirectChaining &ht, int b, ItemType x);
void insert(HashTable_DirectChaining &ht, ItemType x);
ItemType Search_Item(HashTable_DirectChaining ht, KeyType k);
ItemType pop(HashTable_DirectChaining &ht, int b);
ItemType deleteAfter(HashNode *p);
int remove(HashTable_DirectChaining &ht, KeyType k);
void clearBucket(HashTable_DirectChaining &ht, int b);
void clear(HashTable_DirectChaining &ht);
void traverseBucket(HashTable_DirectChaining ht, int b);
void traverseHashTable(HashTable_DirectChaining ht);
void loadTTSV(HashTable_DirectChaining &ht, char fName[]);
void nhapTTSV(ItemType &x);
void docTTSV(FILE *fi, ItemType &x);
void xuatTTSV(ItemType x);
void xuatDanhSachSV(HashTable_DirectChaining &ht);

#endif