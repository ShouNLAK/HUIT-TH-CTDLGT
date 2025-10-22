#ifndef _AVLTREE_SONGUYEN_H
#define _AVLTREE_SONGUYEN_H
//==============================================================
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//==============================================================
#define LH -1
#define EH 0
#define RH 1
//==============================================================
typedef int ItemType;
struct AVLNode
{
	int balFactor;
	ItemType Info;
	AVLNode* Left;
	AVLNode* Right;
};
struct AVLTree
{
	AVLNode *Root;
};
//==============================================================
AVLNode* createAVLNode(ItemType x);
void initAVLTree(AVLTree& avl);
void rotateLL(AVLNode *&T);
void rotateRR(AVLNode *&T);
void rotateLR(AVLNode *&T);
void rotateRL(AVLNode *&T);
int balanceLeft(AVLNode *&T);
int balanceRight(AVLNode *&T);
int insertAVLNode(AVLNode *&T, AVLNode *p);
int searchStandFor(AVLNode *&p, AVLNode *&q);
int deleteAVLNode(AVLNode *&T, ItemType x);
AVLNode *findAVLNode(AVLNode *root, ItemType x);
int deleteAVLTree(AVLNode *&root);
void createAVLTree_ByHand(AVLTree& avl);
void createAVLTree_Random(AVLTree& avl);
void createAVLTree_FromArray(AVLTree& avl, ItemType a[], int n);
void traverseNLR(AVLNode *root);
void traverseNRL(AVLNode *root);
void traverseLNR(AVLNode *root);
void traverseLRN(AVLNode *root);
void traverseRLN(AVLNode *root);
void traverseRNL(AVLNode *root);
void showAVLNode(AVLNode* p);
void printAVLTree(AVLNode *p);

#endif