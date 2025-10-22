#include "BTree_SoNguyen.h"
//================================================================
NodePtr createBNode(NodePtr root, ItemType upKey, NodePtr newNode)
{//Tạo 1 node mới
	NodePtr p = new BNode;
	if (p == NULL)
	{
		printf("Khong the cap phat bo nho !");
		getch();
		return NULL;
	}
	p->numTree = 1;
	p->Keys[0] = upKey;
	p->Branch[0] = root;
	p->Branch[1] = newNode;
	return p;
}
//================================================================
void initBTree(BTree &bt)
{
	bt.Root = NULL;
}
//================================================================
void insert(NodePtr &root, ItemType key)
{
	NodePtr newNode;
	ItemType upKey;
	KeyStatus result;
	result = insertNode(root, key, &upKey, &newNode);
	if (result == Duplicate)
		printf("Da co sang trong BTree");
	else if (result == InsertIt)
	{
		root = createBNode(root, upKey, newNode);
	}
}
//================================================================
KeyStatus insertNode(NodePtr pCurrent, ItemType key, ItemType *upKey, NodePtr *newNode) 
{
	NodePtr newPtr, lastPtr;
	int pos, i, numTree, splitPos;
	ItemType newKey, lastKey;
	KeyStatus result;
	if (pCurrent == NULL) {
		*newNode = NULL;
		*upKey = key;
		return InsertIt;
	}
	numTree = pCurrent->numTree;
	pos = searchPosition(key, pCurrent->Keys, numTree);
	if (pos < numTree && key == pCurrent->Keys[pos])
		return Duplicate;
	result = insertNode(pCurrent->Branch[pos], key, &newKey, &newPtr);
	if (result != InsertIt)
		return result;
	if (numTree < M - 1) {
		pos = searchPosition(newKey, pCurrent->Keys, numTree);
		for (i = numTree; i > pos; i--) {
			pCurrent->Keys[i] = pCurrent->Keys[i - 1];
			pCurrent->Branch[i + 1] = pCurrent->Branch[i];
		}
		pCurrent->Keys[pos] = newKey;
		pCurrent->Branch[pos + 1] = newPtr;
		++pCurrent->numTree;
		return Success;
	}
	if (pos == M - 1) {
		lastKey = newKey;
		lastPtr = newPtr;
	}
	else {
		lastKey = pCurrent->Keys[M - 2];
		lastPtr = pCurrent->Branch[M - 1];
		for (i = M - 2; i > pos; i--) {
			pCurrent->Keys[i] = pCurrent->Keys[i - 1];
			pCurrent->Branch[i + 1] = pCurrent->Branch[i];
		}
		pCurrent->Keys[pos] = newKey;
		pCurrent->Branch[pos + 1] = newPtr;
	}
	splitPos = (M - 1) / 2;
	(*upKey) = pCurrent->Keys[splitPos];
	(*newNode) = new BNode;
	pCurrent->numTree = splitPos;
	(*newNode)->numTree = M - 1 - splitPos;
	for (i = 0; i < (*newNode)->numTree; i++) {
		(*newNode)->Branch[i] = pCurrent->Branch[i + splitPos + 1];
		if (i < (*newNode)->numTree - 1)
			(*newNode)->Keys[i] = pCurrent->Keys[i + splitPos + 1];
		else
			(*newNode)->Keys[i] = lastKey;
	}
	(*newNode)->Branch[(*newNode)->numTree] = lastPtr;
	return InsertIt;
}
//================================================================
void showBTreeNode(NodePtr pCurrent, int pos)
{
	printf("%3d", pCurrent->Keys[pos]);
}
//================================================================
void displayBTree(NodePtr pRoot, int blanks)
{
	if (pRoot) {
		int i;
		for (i = 1; i <= blanks; i++)
			printf(" ");
		for (i = 0; i < pRoot->numTree; i++)
			showBTreeNode(pRoot, i);
		printf("\n");
		for (i = 0; i <= pRoot->numTree; i++)
			displayBTree(pRoot->Branch[i], blanks + Distance);
	}
}
//================================================================
int searchPosition(ItemType key, ItemType* keyArray, int numTree)
{
	int pos = 0;
	while (pos < numTree && key > keyArray[pos])
		pos++;
	return pos;
}
//================================================================
NodePtr searchNode(NodePtr root, ItemType key) 
{
	int pos, numTree;
	NodePtr pCurrent = root;
	while (pCurrent) {
		numTree = pCurrent->numTree;
		pos = searchPosition(key, pCurrent->Keys, numTree);
		if (pos < numTree && key == pCurrent->Keys[pos]) {
			return pCurrent;
		}
		pCurrent = pCurrent->Branch[pos];
	}
	return NULL;
}
//================================================================
void search(NodePtr root, ItemType key) 
{
	int pos, i, numTree;
	NodePtr pCurrent = root;
	printf("Search path:\n");
	while (pCurrent) {
		numTree = pCurrent->numTree;
		for (i = 0; i < pCurrent->numTree; i++)
			printf(" %d", pCurrent->Keys[i]);
		printf("\n");
		pos = searchPosition(key, pCurrent->Keys, numTree);
		if (pos < numTree && key == pCurrent->Keys[pos]) {
			printf("Key %d found in position %d of last displayed node\n", key, pos);
			return;
		}
		pCurrent = pCurrent->Branch[pos];
	}
	printf("Key %d is not available\n", key);
}
//================================================================
KeyStatus remove(NodePtr &root, NodePtr pCurrent, ItemType key)
{
	int pos, i, pivot, numTree, min;
	ItemType *keyArray;
	KeyStatus result;
	NodePtr *Branch, leftPtr, rightPtr;
	if (pCurrent == NULL)
		return SearchFailure;
	numTree = pCurrent->numTree;
	keyArray = pCurrent->Keys;
	Branch = pCurrent->Branch;
	min = (M - 1) / 2;
	pos = searchPosition(key, keyArray, numTree);
	if (Branch[0] == NULL) {
		if (pos == numTree || key < keyArray[pos])
			return SearchFailure;
		for (i = pos + 1; i < numTree; i++) {
			keyArray[i - 1] = keyArray[i];
			Branch[i] = Branch[i + 1];
		}
		return --pCurrent->numTree >= (pCurrent == root ? 1 : min) ? Success : LessKeys;
	}
	if (pos < numTree && key == keyArray[pos]) {
		NodePtr qp = Branch[pos], qp1;
		ItemType nkey;
		while (1) {
			nkey = qp->numTree;
			qp1 = qp->Branch[nkey];
			if (qp1 == NULL)
				break;
			qp = qp1;
		}
		keyArray[pos] = qp->Keys[nkey - 1];
		qp->Keys[nkey - 1] = key;
	}
	result = remove(root, Branch[pos], key);
	if (result != LessKeys)
		return result;
	if (pos > 0 && Branch[pos - 1]->numTree > min) {
		pivot = pos - 1;
		leftPtr = Branch[pivot];
		rightPtr = Branch[pos];
		rightPtr->Branch[rightPtr->numTree + 1] = rightPtr->Branch[rightPtr->numTree];
		for (i = rightPtr->numTree; i > 0; i--) {
			rightPtr->Keys[i] = rightPtr->Keys[i - 1];
			rightPtr->Branch[i] = rightPtr->Branch[i - 1];
		}
		rightPtr->numTree++;
		rightPtr->Keys[0] = keyArray[pivot];
		rightPtr->Branch[0] = leftPtr->Branch[leftPtr->numTree];
		keyArray[pivot] = leftPtr->Keys[leftPtr->numTree - 1];
		leftPtr->numTree--;
		return Success;
	}
	if (pos < numTree && Branch[pos + 1]->numTree > min) {
		pivot = pos;
		leftPtr = Branch[pivot];
		rightPtr = Branch[pivot + 1];
		leftPtr->Keys[leftPtr->numTree] = keyArray[pivot];
		leftPtr->Branch[leftPtr->numTree + 1] = rightPtr->Branch[0];
		keyArray[pivot] = rightPtr->Keys[0];
		leftPtr->numTree++;
		for (i = 0; i < rightPtr->numTree - 1; i++) {
			rightPtr->Keys[i] = rightPtr->Keys[i + 1];
			rightPtr->Branch[i] = rightPtr->Branch[i + 1];
		}
		rightPtr->Branch[rightPtr->numTree - 1] = rightPtr->Branch[rightPtr->numTree];
		rightPtr->numTree--;
		return Success;
	}
	if (pos == numTree)
		pivot = pos - 1;
	else
		pivot = pos;
	leftPtr = Branch[pivot];
	rightPtr = Branch[pivot + 1];
	leftPtr->Keys[leftPtr->numTree] = keyArray[pivot];
	leftPtr->Branch[leftPtr->numTree + 1] = rightPtr->Branch[0];
	for (i = 0; i < rightPtr->numTree; i++) {
		leftPtr->Keys[leftPtr->numTree + 1 + i] = rightPtr->Keys[i];
		leftPtr->Branch[leftPtr->numTree + 2 + i] = rightPtr->Branch[i + 1];
	}
	leftPtr->numTree = leftPtr->numTree + 1 + rightPtr->numTree;
	free(rightPtr);
	for (i = pos + 1; i < numTree; i++) {
		keyArray[i - 1] = keyArray[i];
		Branch[i] = Branch[i + 1];
	}
}
//================================================================
void deleteNode(NodePtr &root, ItemType key)
{
	NodePtr upRoot;
	KeyStatus result;
	result = remove(root, root, key);
	switch (result)
	{
	case SearchFailure:
		printf("Key %d is not available\n", key);
		break;
	case LessKeys:
		upRoot = root;
		root = root->Branch[0];
		free(upRoot);
		printf("\nBTree after removing the %d value:\n", key);
		displayBTree(root, 0);
		break;
	case Success:
		printf("\nBTree after removing the %d value:\n", key);
		displayBTree(root, 0);
		break;
	}
}