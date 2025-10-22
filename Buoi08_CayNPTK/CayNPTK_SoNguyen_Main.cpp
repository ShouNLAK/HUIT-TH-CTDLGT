#include "CayNPTK_SoNguyen.h"
//==============================================================
void showMenu()
{
	printf("\n******************************************************************");
	printf("\n*                              MENU                              *");
	printf("\n******************************************************************");
	printf("\n* 0. Thoat chuong trinh                                          *");
	printf("\n* 1. Nhap - Xuat 1 Node                                          *");
	printf("\n* 2. Nhap Cay truc tiep tu ban phim                              *");
	printf("\n* 3. Tao Cay phat sinh ngau nhien                                *");
	printf("\n* 4. Tao Cay tu mang 1 chieu                                     *");
	printf("\n* 5. Tao Cay tu text file                                        *");
	printf("\n* 6. Them 1 node moi vao dau Cay                                 *");
	printf("\n* 7. Xoa phan tu trong Cay                                       *");
	printf("\n* 8. Tim phan tu x trong Cay ?                                   *");
	printf("\n* 9. Xem cay hien tai                                            *");
	printf("\n* 10.Tinh chieu cao cua cay hien tai                             *");
	printf("\n* 11.Tinh not la cua cay hien tai                                *");
	printf("\n* 12.Tinh tong gia tri not la cua cay hien tai                   *");
	printf("\n* 13.Tinh tong gia tri not cua cay hien tai                      *");
	printf("\n*********************CHUC NANG BO SUNG****************************");
	printf("\n* 14. Xuat cay dang do thi                                       *");
	printf("\n* 15. Xoa nut con trai cua T                                     *");
	printf("\n* 16. Xoa nut con phai cua T                                     *");
	printf("\n* 17. Xuat cac phan tu theo chieu giam dan                       *");
	printf("\n* 18. Dem so nut lon hon / nho hon x                             *");
	printf("\n* 19. Dem so nut nam trong khoang [x,y]                          *");
	printf("\n* 20. Dem so nut va so nut con cua cay                           *");
	printf("\n* 21. Dem so nut co 1 nut con / 2 nut con / co nut la            *");
	printf("\n* 22. Max - Min cua cay                                          *");
	printf("\n* 23. Xuat ra cac nut o muc k                                    *");
	printf("\n* 24. Xuat ra cac nut la o muc k                                 *");
	printf("\n* 25. Dem so nut va nut la o muc k                               *");
	printf("\n* 26. Tim phan tu co khoang cach gan nhat voi x                  *");
	printf("\n* 27. Tim phan tu co khoang cach xa nhat voi x                   *");
	printf("\n* 28. Tong gia tri duong - am cua cay                            *");
	printf("\n* 29. Tong S. Ng to / Ch phuong / Hoan thien / Thinh vuong / Yeu *");
	printf("\n* 30. Xoa cay                                                    *");
	printf("\n* 31. Xuat cac nut thuoc level K cua cay                         *");
	printf("\n* 32. Xuat cac nut theo thu tu tren cay                          *");
	printf("\n* 33. Dem so luong nut la ma tai do la so chan                   *");
	printf("\n* 34. Dem nut co 1 con va la so nguyen to                        *");
	printf("\n* 35. Dem nut co 2 con va la so chinh phuong                     *");
	printf("\n* 36. Dem so luong nut o tang cao hon / thap hon cua cay         *");
	printf("\n* 37. Tong cac nut / nut la tren cay                             *");
	printf("\n* 38. Tong cac nut co 1 nut con / 2 nut con                      *");
	printf("\n* 39. Tong cac nut co gia tri le                                 *");
	printf("\n* 40. Tong cac nut co 1 con va la so nguyen to                   *");
	printf("\n* 41. Tong cac nut co 2 con va la so chinh phuong                *");
	printf("\n******************************************************************");
}
//==============================================================
void process()
{
	int luaChon, kq, x;
	BSTNode* P, *Q;
	BSTree bst;
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
			printf("Ban hay nhap mot so nguyen bat ky : ");
			scanf("%d", &X);
			P = createBSTNode(X);
			showBSTNode(P);
			break;
		case 2:
			createBSTree_InputByHand(bst);
			printf("\nNOI DUNG Cay VUA NHAP LA : \n");
			traverseNLR(bst.Root);
			break;
		case 3:
			createBSTree_Random(bst);
			printf("\nNOI DUNG Cay VUA TAO NGAU NHIEN LA : \n");
			traverseNLR(bst.Root);
			break;
		case 4:
			createBSTree_FromArray(bst, A, N);
			printf("\nNOI DUNG Cay VUA TAO TU MANG MOT CHIEU LA : \n");
			traverseNLR(bst.Root);
			break;
		case 5:
			createBSTree_FromTextFile(bst, tenFile);
			printf("\nNOI DUNG Cay VUA TAO TU FILE TEXT LA : \n");
			traverseNLR(bst.Root);
			break;
		case 6:
			printf("Ban hay cho biet gia tri node muon them vao dau Cay : ");
			scanf("%d", &X);
			P = createBSTNode(X);
			kq = insertBSTNode(bst.Root, P);
			if (kq == 1)
			{
				printf("\nNOI DUNG Cay SAU KHI THEM %d VAO DAU LA : \n", X);
				traverseNLR(bst.Root);
			}
			else
			{
				printf("\nKhong the them %d vao dau Cay.", X);
			}
			break;
		case 7:
			printf("Nhap x can xoa : "); scanf("%d", &X);
			kq = deleteBSTNodeX(bst.Root, X);
			if (kq == 1)
			{
				printf("\nNOI DUNG Cay SAU KHI XOA %d TRONG CAY LA : \n", X);
				traverseNLR(bst.Root);
			}
			else
			{
				printf("\nKhong the xoa phan tu %d.", X);
			}
			break;
		case 8:
			printf("Ban hay cho biet gia tri node can tim trong Cay : ");
			scanf("%d", &X);
			P = findBSTNode(bst.Root, X);
			if (P == NULL)
				printf("Khong tim thay %d trong Cay.", X);
			else
				printf("Da tim thay %d trong Cay tai dia chi %d", X, P);
			break;
		case 9:
			printf("\nDuyet cay theo NLR : \n");
			traverseNLR(bst.Root);
			printf("\nDuyet cay theo LNR : \n");
			traverseLNR(bst.Root);
			break;
		case 10:
			printf("Chieu cao cua cay : %d", hightree(bst.Root));
			break;
		case 11:
			printf("So node la cua cay : %d", countBSTNodeLeaf(bst.Root));
			break;
		case 12:
			printf("Tong node la cua cay : %d", sumBSTNodeLeaf(bst.Root));
			break;
		case 13:
			printf("Tong node cua cay : %d", sumBSTNode(bst.Root));
			break;
		case 14 :
			showBSTree(bst.Root);
			break;
		case 15:
			printf("Nhap gia tri node T muon xoa nut con ben trai : "); scanf("%d", &X);
			P = findBSTNode(bst.Root,X);
			if (deleteBSTNodeLeft(P, x))
				printf("Da xoa nut con ben trai cua node T");
			else
				printf("Khong the xoa nut con ben trai cua node T");
			break;
		case 16:
			printf("Nhap gia tri node T muon xoa nut con ben phai : "); scanf("%d", &X);
			P = findBSTNode(bst.Root, X);
			if (deleteBSTNodeRight(P, x))
				printf("Da xoa nut con ben phai cua node T");
			else
				printf("Khong the xoa nut con ben phai cua node T");
			break;
		case 17:
			traverseRNL(bst.Root);
			break;
		case 18:
			printf("Nhap gia tri x : "); scanf("%d", &X);
			printf("So node co gia tri lon hon x la : %d\n", count_bigger_than_x(bst.Root, X));
			printf("So node co gia tri nho hon x la : %d\n", count_smaller_than_x(bst.Root, X));
			break;
		case 19:
			printf("Nhap gia tri x : "); scanf("%d", &X);
			printf("Nhap gia tri y : "); scanf("%d", &Y);
			printf("So node co gia tri trong khoang [x,y] la : %d", count_between_x_y(bst.Root, X,Y));
			break;
		case 20:
			printf("Tong so nut cua cay la : %d\n", countBSTNode(bst.Root));
			printf("Tong so nut con cua cay la : %d\n", countBSTNodeLeaf(bst.Root));
			break;
		case 21:
			printf("Tong so nut co 2 nut con la : %d\n", countBSTNodeHaveTwoChild(bst.Root));
			printf("Tong so nut co 1 nut con la : %d\n", countBSTNodeHaveOneChild(bst.Root));
			printf("Tong so nut co con la nut la cua cay la : %d\n", countBSTNodeHaveChildIsLeaf(bst.Root));
			break;
		case 22:
			printf("Gia tri lon nhat trong cay la : %d\n", Max_BSTree(bst.Root));
			printf("Gia tri nho nhat trong cay la : %d\n", Min_BSTree(bst.Root));
			break;
		case 23:
			printf("Nhap muc k trong cay : "); scanf("%d", &X);
			showBSTNodeOfLevelK(bst.Root, X);
			break;
		case 24:
			printf("Nhap muc k trong cay : "); scanf("%d", &X);
			showBSTNodeIsLeafOfLevelK(bst.Root, X);
			break;
		case 25:
			printf("Nhap muc k trong cay : "); scanf("%d", &X);
			printf("So nut o muc k la : %d\n", countBSTNodeOfLevelK(bst.Root, X));
			printf("So nut la o muc k la : %d\n", countBSTNodeIsLeafOfLevelK(bst.Root, X));
		case 26:
			printf("Nhap gia tri phan tu X : "); scanf("%d", &X);
			printf("Gia tri nut co khoang cach gan nhat voi %d la %d", X, minDistance(bst.Root, X));
			break;
		case 27:
			printf("Nhap gia tri phan tu X : "); scanf("%d", &X);
			printf("Gia tri nut co khoang cach xa nhat voi %d la %d", X, maxDistance(bst.Root, X));
			break;
		case 28:
			printf("Tong gia tri duong la : %d\n", sumPositive(bst.Root));
			printf("Tong gia tri duong la : %d\n", sumNegative(bst.Root));
			break;
		case 29:
			printf("Tong gia tri cua cac nut chua so nguyen to : %d\n", sumPrime(bst.Root));
			printf("Tong gia tri cua cac nut chua so chinh phuong : %d\n", sumSquare(bst.Root));
			printf("Tong gia tri cua cac nut chua so hoan thien : %d\n", sumPerfect(bst.Root));
			printf("Tong gia tri cua cac nut duoc xem co chua so thinh vuong : %d\n", sumSTV(bst.Root));
			printf("Tong gia tri cua cac nut duoc xem co chua so yeu : %d\n", sumSY(bst.Root));
			break;
		case 30:
			deleteTree(bst.Root);
			break;
		case 31:
			printf("Nhap muc k trong cay : "); scanf("%d", &X);
			showBSTNodeOfLevelK(bst.Root, X);
			break;
		case 32:
			showTreeByLevel(bst.Root);
			break;
		case 33:
			printf("Co %d nut la ma tai do la so chan",countBSTNodeIsLeaf_Chan(bst.Root));
			break;
		case 34:
			printf("Co %d nut co 1 con va la so nguyen to", countBSTNodeHaveOneChild_Prime(bst.Root));
			break;
		case 35:
			printf("Co %d nut co 2 con va la so chinh phuong", countBSTNodeHaveTwoChild_Square(bst.Root));
			break;
		case 36:
			printf("Nhap muc k trong cay : "); scanf("%d", &X);
			printf("Co %d nut o tang cao hon tang %d trong cay\n", countBSTNodeAboveK(bst.Root, X),X);
			printf("Co %d nut o tang thap hon tang %d trong cay\n", countBSTNodeAboveK(bst.Root, X),X);
			break;
		case 37:
			printf("Tong gia tri cac nut : %d\n", sumBSTNode(bst.Root));
			printf("Tong gia tri cac nut la : %d\n", sumBSTNodeLeaf(bst.Root));
			break;
		case 38:
			printf("Tong gia tri cac nut co 1 nut con : %d\n", sumBSTNodeHaveOneLeaf(bst.Root));
			printf("Tong gia tri cac nut co 2 nut con : %d\n", sumBSTNodeHaveTwoLeaf(bst.Root));
			break;
		case 39:
			printf("Tong cac nut co gia tri le : %d", sumBSTree_Le(bst.Root));
			break;
		case 40 : 
			printf("Tong cac nut co 1 con va la so nguyen to : %d", sumBSTNodeHaveOneChild_Prime(bst.Root));
			break;
		case 41:
			printf("Tong cac nut co 2 nut con va la so chinh phuong : %d", sumBSTNodeHaveTwoChild_Square(bst.Root));
			break;
		}
	} while (luaChon != 0);
}
//==============================================================
void main()
{
	process();
}