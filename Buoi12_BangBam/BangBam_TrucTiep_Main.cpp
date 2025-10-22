#include "BangBam_TrucTiep.h"

void menu()
{
	printf("\n*********************************************\n");
	printf("* 1. Them mot nut vao bang bam              *\n");
	printf("* 2. Them ngau nhien nhieu nut vao bang bam *\n");
	printf("* 3. Them nut vao bang bam bang text        *\n");
	printf("* 4. Xoa mot nut cua bang bam               *\n");
	printf("* 5. Xoa bang bam                           *\n");
	printf("* 6. Duyet bang bam                         *\n");
	printf("* 7. Tim kiem mot nut trong bang bam        *\n");
	printf("* 0. Thoat chuong trinh                     *\n");
	printf("*********************************************\n");
}
//============================================
void process()
{
	int b, i, n, SelectFunction;
	char c;
	ItemType Key;
	HashTable_DirectChaining HashTable;
	initHashTable(HashTable);
	do
	{
		menu();
		printf("Moi ban cho chuc nang : "); scanf("%d", &SelectFunction);
		switch (SelectFunction)
		{
		case 1:
			printf("Nhap gia tri cua node duoc them : ");
			scanf("%d", &Key);
			insert(HashTable, Key);
			break;
		case 2:
			printf("Nhap so luong nut : "); scanf("%d", &n);
			srand(unsigned(time(NULL)));
			for (int i = 0; i < n;i++)
			{
				Key = rand() % 100;
				insert(HashTable, Key);
			}
			break;
		case 3:
			loadFileText(HashTable, "dsSoNguyen.txt");
			if (isEmptyHashTable(HashTable))
				printf("Bang bam rong");
			else
			{
				printf("Duyet bang bam : ");
				traverseHashTable(HashTable);
			}
			break;
		case 4:
			printf("Nhap gia tri cua node can xoa : ");
			scanf("%d", &Key);
			remove(HashTable, Key);
			break;
		case 5:
			clear(HashTable);
			break;
		case 6:
			if (isEmptyHashTable(HashTable))
				printf("Bang bam rong");
			else
			{
				printf("Duyet bang bam : ");
				traverseHashTable(HashTable);
			}
			break;
		case 7:
			printf("Nhap gia tri cua node can tim : ");
			scanf("%d", &Key);
			b = Search_Item(HashTable, Key);
			if (b == -1)
				printf("Khong tim thay");
			else
				printf("Tim thay trong bucket %d", b);
			break;

			}
	} while (SelectFunction != 0);
}

void main()
{
	process();
}