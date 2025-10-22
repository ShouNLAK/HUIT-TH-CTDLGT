#include "AVLTree.h"
#include "ASCII_Node.h"
#include "Dictionary.h"
#define fioName "dic.txt"
//==============================================================
void showMenu()
{
	printf("\n******************************************************************");
	printf("\n*                              MENU                              *");
	printf("\n******************************************************************");
	printf("\n* 0. Thoat chuong trinh                                          *");
	printf("\n* 1. Tra cuu nghia cua tu                                        *");
	printf("\n* 2. Them mot tu moi                                             *");
	printf("\n* 3. Xoa mot tu                                                  *");
	printf("\n* 4. Xuat noi dung cay tu dien                                   *");
	printf("\n******************************************************************");
}
//==============================================================
void process()
{
	int luaChon, CountWord, Flag;
	AVLNode* P;
	AVLTree avl;
	ItemType X;
	initAVLTree(avl);
	LoadDictionary(fioName, avl, CountWord);
	do
	{
		showMenu();
		printf("\nBan hay lua chon mot chuc nang : ");
		scanf("%d", &luaChon);
		switch (luaChon)
		{
		case 1:
			printf("\nBan hay nhap tu muon tra nghia : "); flushall(); gets(X.Word);
			strcpy(X.Meaning, "");
			P = findAVLNode(avl.Root,X);
			if (P)
			{
				strcpy(X.Meaning, P->Info.Meaning);
				printf("Nghia cua tu %s : %s", X.Word, X.Meaning);
			}
			break;
		case 2:
			printf("\nBan hay nhap tu muon them : "); flushall(); gets(X.Word);
			printf("\nBan hay nhap nghia cua tu : "); flushall(); gets(X.Meaning);
			UpperTheFirstCharater(X.Word);
			UpperTheFirstCharater(X.Meaning);
			P = createAVLNode(X);
			insertAVLNode(avl.Root, P);
			WriteAddDictionary(fioName, X);
			++CountWord;
			break;
		case 3:
			printf("\nBan hay nhap tu muon xoa : "); flushall(); gets(X.Word);
			UpperTheFirstCharater(X.Word);
			strcpy(X.Meaning, "");
			deleteAVLNode(avl.Root, X);
			WriteDictionary(fioName, avl);
			--CountWord;
			break;
		case 4:
			print_ascii_tree(avl.Root);

			printf("Tu dien co %d tu", CountWord);
			break;
		}
	} while (luaChon != 0);
}

void main()
{
	process();
}