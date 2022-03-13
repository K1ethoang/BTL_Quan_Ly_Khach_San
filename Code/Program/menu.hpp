#include "RoomRenters.hpp"

void menu()
{
    int choose;
    bool exit = false;
    RoomRenters roomRenters;
    createList(roomRenters);
    printf("\n");
    do
    {
        system("cls");
        printf("%50c###########################################\n");
        printf("%50c##           QUAN LY KHACH SAN           ##\n");
        printf("%50c## ------------------------------------- ##\n");
        printf("%50c##      1. Them nguoi thue               ##\n");
        printf("%50c##      2. Xem danh sach nguoi thue      ##\n");
        printf("%50c##      3. Chinh sua nguoi thue          ##\n");
        printf("%50c##      4. Thanh toan                    ##\n");
        printf("%50c##      5. Xem tinh trang phong          ##\n");
        printf("%50c##      6. Sap xep danh sach theo ten    ##\n");
        printf("%50c##      7. Tim kiem nguoi thue theo ten  ##\n");
        printf("%50c## ------------------------------------- ##\n");
        printf("%50c##         0. Thoat chuong trinh         ##\n");
        printf("%50c###########################################\n");
        printf("%50c   Lua chon cua ban -> ");
        scanf("%d", &choose);
        fflush(stdin);
        switch (choose)
        {
        case 1:
        {
            system("cls");
            printf("\n\t%50c1. THEM NGUOI THUE\n");
            printf("\n\t%50c(*) Nhap thong tin nguoi thue (*)\n");
            system("pause");
            addARoomRenter(roomRenters);
            break;
        }
        case 2:
        {
            system("cls");
            RoomRenter r;
            printf("\n\t%50c2. XEM DANH SACH NGUOI THUE\n");
            if (roomRenters.pHead == NULL)
                printf("\n\t%50c(*) Danh sach nguoi thue trong (*)\n\a", ' ');
            else
                outputRoomRenters(roomRenters);
            system("pause");
            break;
        }
        case 3:
        {
            system("cls");
            printf("\n\t%50c3. CHINH SUA NGUOI THUE\n");
            if (roomRenters.pHead == NULL)
                printf("\n\t%50c(*) Danh sach nguoi thue trong (*)\n\a", ' ');
            else
            {
                char phoneNumber[15];
                printf("\n%50cNhap SDT cua nguoi thue can sua: ");
                fflush(stdin);
                gets(phoneNumber);
                UpdateRoomRenter(roomRenters, phoneNumber);
            }
            system("pause");
            break;
        }
        case 4:
        {
            system("cls");
            printf("\n\t%50c4. THANH TOAN\n");
            if (roomRenters.pHead == NULL)
                printf("\n\t%50c(*) Danh sach nguoi thue trong (*)\n\a", ' ');
            else
            {
                char phoneNumber[15];
                printf("\n%50cNhap SDT cua nguoi thue can thanh toan: ");
                fflush(stdin);
                gets(phoneNumber);
                deleteARoomRenter(roomRenters, phoneNumber);
            }
            system("pause");
            break;
        }
        case 5:
        {
            system("cls");
            printf("%50c###########################################\n");
            printf("%50c##            TINH TRANG PHONG           ##\n");
            printf("%50c## ------------------------------------- ##\n");
            printf("%50c##      1. Phong trong                   ##\n");
            printf("%50c##      2. Phong day                     ##\n");
            printf("%50c##      3. Tat ca                        ##\n");
            printf("%50c## ------------------------------------- ##\n");
            printf("%50c##              0. Tro ve                ##\n");
            printf("%50c###########################################\n");
            printf("%50c   Lua chon cua ban -> ");
        }
        default:
            printf("\n\t%50c(!) Lua chon khong hop le (!)\n\a");
            system("pause");
            break;
        case 0:
            exit = true;
            break;
        }
    } while (!exit);
    system("pause");
}