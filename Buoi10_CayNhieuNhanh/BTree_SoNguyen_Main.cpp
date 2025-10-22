#include "BTree_SoNguyen.h"
//==============================================================
void showMenu()
{
	printf("\n******************************************************************");
	printf("\n*                              MENU                              *");
	printf("\n******************************************************************");
	printf("\n* 0. Thoat chuong trinh                                          *");
	printf("\n******************************************************************");
}
//==============================================================
void process()
{
	BTree bt;
	initBTree(bt);
	ItemType a[] = { 1, 12, 8, 2, 25, 5, 14, 28, 17, 7, 52, 16, 48, 68, 3, 26, 29, 53, 55, 45 };
	int n = 20;
	int blanks = 0;
	ItemType key;
	int LuaChon;


	printf("Creation of B-Tree for node %d\n", M);
	initBTree(bt);
	for (int i = 0; i < n; i++) {
		key = a[i];
		insert(bt.Root, key);
		printf("B-Tree is added value %d:\n", key);
		displayBTree(bt.Root, blanks);
		getch();
	}

	printf("B-Tree is:\n");
	displayBTree(bt.Root, blanks);

	printf("Enter the key want to delete: ");
	scanf("%d", &key);
	deleteNode(bt.Root, key);

	printf("Enter the key want to search: ");
	scanf("%d", &key);
	search(bt.Root, key);

	printf("\n---");
	getch();
}

void main()
{
	process();
}