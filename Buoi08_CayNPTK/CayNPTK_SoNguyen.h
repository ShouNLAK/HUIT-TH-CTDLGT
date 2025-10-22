/*
Họ và tên : Nguyễn Lê Anh Khoa
Lớp :		THCTDL&GT - ST4 - A211
*/

#ifndef CayNPTK_SoNguyen_h
#define CayNPTK_SoNguyen_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>

typedef int ItemType;
struct BSTNode
{//Tạo 1 node
	ItemType Info;
	BSTNode* Left;
	BSTNode* Right;
};
//==============================================================
struct BSTree
{//Tạo 1 danh sách các Node
	BSTNode *Root;
};
//==============================================================
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
BSTNode* createBSTNode(ItemType x);
void showBSTNode(BSTNode* p);
void showBSTree(BSTNode *p);
void initBSTree(BSTree& bst);
int insertBSTNode(BSTNode *&root, BSTNode* p);
void createBSTree_InputByHand(BSTree& bst);
void createBSTree_Random(BSTree& bst);
void createBSTree_FromArray(BSTree& bst, ItemType a[], int n);
void createBSTree_FromTextFile(BSTree& bst, char inputFileName[]);
void swap(ItemType& x, ItemType& y);
void traverseNRL(BSTNode *root);
void traverseNLR(BSTNode *root);
void traverseLNR(BSTNode *root);
void traverseRNL(BSTNode *root);
void traverseLRN(BSTNode *root);
void traverseRLN(BSTNode *root);
int hightree(BSTNode *root);
int countBSTNodeLeaf(BSTNode *root);
int sumBSTNodeLeaf(BSTNode *root);
int sumBSTNode(BSTNode *root);
BSTNode* findBSTNode(BSTNode *root, ItemType x);
BSTNode *findBSTNodeReplace(BSTNode *&p);
int deleteBSTNodeX(BSTNode *&root, ItemType x);
int isLeaf(BSTNode *T);
int deleteBSTNodeLeft(BSTNode *T, ItemType &x);
int deleteBSTNodeRight(BSTNode *T, ItemType &x);
int count_bigger_than_x(BSTNode *root, ItemType &x);
int count_smaller_than_x(BSTNode *root, ItemType &x);
int count_between_x_y(BSTNode *root, ItemType &x, ItemType &y);
int countBSTNode(BSTNode *root);
int countBSTNodeHaveTwoChild(BSTNode *root);
int countBSTNodeHaveOneChild(BSTNode *root);
int countBSTNodeHaveChildIsLeaf(BSTNode *root);
int Max_BSTree(BSTNode *root);
int Min_BSTree(BSTNode *root);
void showBSTNodeOfLevelK(BSTNode *root, int k);
void showBSTNodeIsLeafOfLevelK(BSTNode *root, int k);
int countBSTNodeOfLevelK(BSTNode *root, int k);
int countBSTNodeIsLeafOfLevelK(BSTNode *root, int k);
int minDistance(BSTNode *root, ItemType x);
int maxDistance(BSTNode *root, ItemType x);
int sumNegative(BSTNode *root);
int sumPositive(BSTNode *root);
int isPrime(int n);
int isPerfect(int n);
int checkSTV(int n);
int checkSY(int n);
int sumPrime(BSTNode *root);
int sumSquare(BSTNode *root);
int sumPerfect(BSTNode *root);
int sumSTV(BSTNode *root);
int sumSY(BSTNode *root);
void deleteTree(BSTNode*&root);
void showTreeByLevel(BSTNode *root);
int countBSTNodeIsLeaf_Chan(BSTNode *root);
int countBSTNodeHaveOneChild_Prime(BSTNode *root);
int countBSTNodeHaveTwoChild_Square(BSTNode *root);
int countBSTNodeBelowK(BSTNode *root, int k);
int countBSTNodeAboveK(BSTNode*root, int k);
int sumBSTNodeHaveOneLeaf(BSTNode *root);
int sumBSTNodeHaveTwoLeaf(BSTNode *root);
int sumBSTree_Le(BSTNode *root);
int sumBSTNodeHaveOneChild_Prime(BSTNode *root);
int sumBSTNodeHaveTwoChild_Square(BSTNode *root);

#endif