#include "BangBam_TrucTiep_SV.h"

void menu()
{
	printf("\n*************************************************\n");
	printf("* 1. Them mot sinh vien vao bang bam              *\n");
	printf("* 2. Them sinh vien vao bang bam bang text        *\n");
	printf("* 3. Xoa mot sinh vien cua bang bam               *\n");
	printf("* 4. Xoa bang bam                                 *\n");
	printf("* 5. Duyet bang bam                               *\n");
	printf("* 6. Tim kiem mot sinh vien trong bang bam        *\n");
	printf("* 0. Thoat chuong trinh                           *\n");
	printf("***************************************************\n");
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
			loadTTSV(HashTable, "dsSinhVien.txt");
			if (isEmptyHashTable(HashTable))
				printf("Bang bam rong");
			else
			{
				printf("Duyet bang bam : \n");
				xuatDanhSachSV(HashTable);
			}
			break;
		case 3:
			printf("Nhap ma so sinh vien can xoa : ");
			fflush(stdin); gets(Key.MSSV);
			remove(HashTable, Key.MSSV);
			break;
		case 4:
			clear(HashTable);
			break;
		case 5:
			if (isEmptyHashTable(HashTable))
				printf("Bang bam rong");
			else
			{
				printf("Duyet bang bam : ");
				xuatDanhSachSV(HashTable);
			}
			break;
		case 6:
			printf("Nhap ma so sinh vien can tim : ");
			fflush(stdin); gets(Key.MSSV);
			Key = Search_Item(HashTable, Key.MSSV);
			if (strcmp(Key.MSSV,"")==0)
				printf("Khong tim thay");
			else
			{
				printf("Da tim thay trong bang bam\n");
				xuatTTSV(Key);
			}
			break;

		}
	} while (SelectFunction != 0);
}

void main()
{
	process();
}