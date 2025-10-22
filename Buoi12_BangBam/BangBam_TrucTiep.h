#ifndef HashTable_TrucTiep_h
#define HashTable_TrucTiep_h

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

typedef int KeyType;
typedef int ItemType;

#define TRUE 1
#define FALSE 0
#define KEYSIZE 10

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
int pop(HashTable_DirectChaining &ht, int b);
int deleteAfter(HashNode *p);
int remove(HashTable_DirectChaining &ht, KeyType k);
void clearBucket(HashTable_DirectChaining &ht, int b);
void clear(HashTable_DirectChaining &ht);
void traverseBucket(HashTable_DirectChaining ht, int b);
void traverseHashTable(HashTable_DirectChaining ht);
void loadFileText(HashTable_DirectChaining &ht, char fName[]);

#endif