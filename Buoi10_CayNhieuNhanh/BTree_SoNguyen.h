#ifndef BTree_SoNguyen_h
#define BTree_SoNguyen_h


#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define M 3
#define Distance 10

typedef int ItemType;

struct BNode
{
	int numTree;
	ItemType Keys[M - 1];
	BNode* Branch[M];
};

struct BTree
{
	BNode* Root;
};
typedef BNode* NodePtr;
enum KeyStatus{Duplicate,SearchFailure,Success,InsertIt,LessKeys};

NodePtr createBNode(NodePtr root, ItemType upKey, NodePtr newNode);
void initBTree(BTree &bt);
void insert(NodePtr &root, ItemType key);
KeyStatus insertNode(NodePtr pCurrent, ItemType key, ItemType *upKey, NodePtr *newNode);
void showBTreeNode(NodePtr pCurrent, int pos);
void displayBTree(NodePtr pRoot, int blanks);
int searchPosition(ItemType key, ItemType* keyArray, int numTree);
NodePtr searchNode(NodePtr root, ItemType key);
void search(NodePtr root, ItemType key);
KeyStatus remove(NodePtr &root, NodePtr pCurrent, ItemType key);
void deleteNode(NodePtr &root, ItemType key);

#endif