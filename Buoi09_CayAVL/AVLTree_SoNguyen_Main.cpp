#include "AVLTree_SoNguyen.h"
//==============================================================
void showMenu()
{
	printf("\n******************************************************************");
	printf("\n*                              MENU                              *");
	printf("\n******************************************************************");
	printf("\n* 0. Thoat chuong trinh                                          *");
	printf("\n* 1. Nhap - Xuat 1 Node                                          *");
	printf("\n* 2. Nhap Cay AVL truc tiep tu ban phim                          *");
	printf("\n* 3. Tao Cay AVL phat sinh ngau nhien                            *");
	printf("\n* 4. Tao Cay AVL tu mang 1 chieu                                 *");
	printf("\n* 5. Ve cay AVL hien tai                                         *");
	printf("\n* 6. Chen them phan tu vao cay AVL                               *");
	printf("\n* 7. Xoa phan tu trong cay AVL                                   *");
	printf("\n* 8. Tim kiem phan tu trong cay AVL                              *");
	printf("\n* 9. Duyet cay AVL theo ca 6 cach                                *");
	printf("\n* 10. Xoa toan bo cay                                            *");
	printf("\n******************************************************************");
}
//==============================================================
void process()
{
	int luaChon, kq, x;
	AVLNode* P, *Q;
	AVLTree avl;
	ItemType X, Y;
	ItemType A[] = { 15, -27, 43, 23, -35, 48, 97, -76, 91, 13 };
	int N = 10;
	char tenFile[] = "inputFile_SoNguyen.txt";
	do
	{
		showMenu();
		printf("\nBan hay lua chon mot chuc nang : ");
		scanf("%d", &luaChon);
		switch (luaChon)
		{
		case 1:
			printf("Nhap gia tri cua node : "); scanf("%d", &X);
			P = createAVLNode(X);
			showAVLNode(P);
			break;
		case 2:
			createAVLTree_ByHand(avl);
			break;
		case 3:
			createAVLTree_Random(avl);
			break;
		case 4:
			createAVLTree_FromArray(avl, A, N);
			break;
		case 5:
			printAVLTree(avl.Root);
			break;
		case 6:
			printf("Nhap gia tri cua node : "); scanf("%d", &X);
			P = createAVLNode(X);
			kq = insertAVLNode(avl.Root, P);
			if (kq)
				printf("Da them phan tu %d vao cay AVL", X);
			else
				printf("Khong the them phan tu %d vao cay AVL", X);
			break;
		case 7:
			printf("Nhap gia tri cua node : "); scanf("%d", &X);
			kq = deleteAVLNode(avl.Root, X);
			if (kq)
				printf("Da xoa phan tu %d khoi cay AVL", X);
			else
				printf("Khong the xoa phan tu %d khoi cay AVL", X);
			break;
		case 8:
			printf("Nhap gia tri cua node : "); scanf("%d", &X);
			P = findAVLNode(avl.Root, X);
			if (P != NULL)
				printf("Tim thay %d tai %d", X, P);
			else
				printf("Khong tim thay %d", X);
			break;
		case 9:
			printf("Duyet theo NLR : "); traverseNLR(avl.Root); printf("\n");
			printf("Duyet theo NRL : "); traverseNRL(avl.Root); printf("\n");
			printf("Duyet theo LNR : "); traverseLNR(avl.Root); printf("\n");
			printf("Duyet theo LRN : "); traverseLRN(avl.Root); printf("\n");
			printf("Duyet theo RNL : "); traverseRNL(avl.Root); printf("\n");
			printf("Duyet theo RLN : "); traverseRLN(avl.Root); printf("\n");
			break;
		case 10:
			kq = deleteAVLTree(avl.Root);
			if (kq)
				printf("Da xoa toan bo cay");
			else
				printf("Khong the xoa toan bo cay");
			break;
		}
	} while (luaChon != 0);
}

void main()
{
	process();
}