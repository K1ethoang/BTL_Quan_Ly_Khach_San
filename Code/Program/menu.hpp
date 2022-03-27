#include "RoomRenters.hpp"
#include "Rooms.hpp"
#include <windows.h>

void menu();
void loading();
void information();
void importRooms(Room rooms[], int &n);
void importRoomRenters(RoomRenters &roomRenters, Room rooms[], int n);
void saveFile(RoomRenters roomRenters, Room rooms[], int n);

void menu()
{
    int choose, n;
    bool exit = false, fileSaved = false;
    Room *rooms = (Room *)calloc(100, sizeof(Room)); // tạo mảng động với 100 phần tử
    RoomRenters roomRenters;
    importRooms(rooms, n);
    importRoomRenters(roomRenters, rooms, n);
    printf("\n");
    do
    {
        system("cls");
        printf("%50c####################################################\n", ' ');
        printf("%50c##                QUAN LY KHACH SAN               ##\n", ' ');
        printf("%50c##------------------------------------------------##\n", ' ');
        printf("%50c##      1. Them nguoi thue                        ##\n", ' ');
        printf("%50c##      2. Xem danh sach nguoi thue               ##\n", ' ');
        printf("%50c##      3. Chinh sua nguoi thue                   ##\n", ' ');
        printf("%50c##      4. Thanh toan                             ##\n", ' ');
        printf("%50c##      5. Xem tinh trang phong                   ##\n", ' ');
        printf("%50c##      6. Sap xep danh sach tang dan theo CCCD   ##\n", ' ');
        printf("%50c##      7. Tim kiem nguoi thue theo ten           ##\n", ' ');
        printf("%50c##      8. In danh sach nguoi thue                ##\n", ' ');
        printf("%50c##      9. Luu thay doi                           ##\n", ' ');
        printf("%50c##------------------------------------------------##\n", ' ');
        printf("%50c##            0. Thoat chuong trinh               ##\n", ' ');
        printf("%50c####################################################\n", ' ');
        printf("%50c   Lua chon cua ban -> ", ' ');
        scanf("%d", &choose);
        fflush(stdin);
        switch (choose)
        {
        case 1:
        {
            system("cls");
            if (outOfRooms(rooms, n)) // nếu hết phòng
            {
                system("cls");
                printf("\n\t%50c (!) Het phong (!)\n\a", ' ');
            }
            else
            {
                addARoomRenter(roomRenters, rooms, n);
                outputRoomRenters(roomRenters);
            }
            system("pause");
            break;
        }
        case 2:
        {
            system("cls");
            RoomRenter r;
            printf("\n\t%50c2. XEM DANH SACH NGUOI THUE\n", ' ');
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
            printf("\n\t%50c3. CHINH SUA NGUOI THUE\n", ' ');
            if (roomRenters.pHead == NULL)
                printf("\n\t%50c(*) Danh sach nguoi thue trong (*)\n\a", ' ');
            else
            {
                char phoneNumber[15];
                printf("\n%50cNhap SDT cua nguoi thue can sua: ", ' ');
                scanf("%s", &phoneNumber);
                UpdateRoomRenter(roomRenters, rooms, n, phoneNumber);
                outputRoomRenters(roomRenters);
            }
            system("pause");
            break;
        }
        case 4:
        {
            system("cls");
            printf("\n\t%50c4. THANH TOAN\n", ' ');
            if (roomRenters.pHead == NULL)
                printf("\n\t%50c(*) Danh sach nguoi thue trong (*)\n\a", ' ');
            else
            {
                char phoneNumber[15];
                printf("\n%50cNhap SDT cua nguoi thue can thanh toan: ", ' ');
                scanf("%s", &phoneNumber);
                deleteARoomRenter(roomRenters, phoneNumber);
                outputRoomRenters(roomRenters);
            }
            system("pause");
            break;
        }
        case 5:
        {
            int choose;
            bool exit = false;
            do
            {
                system("cls");
                printf("%50c###########################################\n", ' ');
                printf("%50c##            TINH TRANG PHONG           ##\n", ' ');
                printf("%50c##---------------------------------------##\n", ' ');
                printf("%50c##      1. Phong trong                   ##\n", ' ');
                printf("%50c##      2. Phong day                     ##\n", ' ');
                printf("%50c##      3. Tat ca                        ##\n", ' ');
                printf("%50c##---------------------------------------##\n", ' ');
                printf("%50c##              0. Tro ve                ##\n", ' ');
                printf("%50c###########################################\n", ' ');
                printf("%50c   Lua chon cua ban -> ", ' ');
                scanf("%d", &choose);
                switch (choose)
                {
                case 1:
                {
                    system("cls");
                    printf("\n\t%50c1. PHONG TRONG\n", ' ');
                    outputRoomsAreEmtpy(rooms, n);
                    system("pause");
                    break;
                }
                case 2:
                {
                    system("cls");
                    printf("\n\t%50c2. PHONG DAY\n", ' ');
                    outputRoomsAreWorking(rooms, n);
                    system("pause");
                    break;
                }
                case 3:
                {
                    system("cls");
                    printf("\n\t%50c3. TAT CA\n", ' ');
                    outputRooms(rooms, n);
                    system("pause");
                    break;
                }
                case 0:
                    exit = true;
                    break;
                default:
                    printf("\n\t%50c(!) Lua chon khong hop le (!)\n\a", ' ');
                    system("pause");
                    break;
                }
            } while (!exit);
            break;
        }
        case 6:
        {
            system("cls");
            printf("\n\t%50c6. SAP XEP DANH SACH TANG DAN THEO CCCD\n");
            printf("\nChua co code\n");
            system("pause");
            break;
        }
        case 7:
        {
            system("cls");
            printf("\n\t%50c7. TIM KIEM NGUOI THUE THEO TEN\n", ' ');
            printf("\nChua co code\n");
            system("pause");
            break;
        }
        case 8:
        {
            system("cls");
            printf("\n\t%50c8. IN DANH SACH NGUOI THUE\n", ' ');
            system("pause");
            break;
        }
        case 9:
        {
            system("cls");
            printf("\n\t%50c9. LUU THAY DOI\n", ' ');
            saveFile(roomRenters, rooms, n);
            fileSaved = true;
            system("pause");
            break;
        }
        case 0:
        {
            if (fileSaved)
            {
                information();
                printf("\n\t%50c(*) Thoat chuong trinh 5s (*)\n", ' ');
                Sleep(5000);
                exit = true;
            }
            else
            {
                system("cls");
                printf("\n\t%50c0. THOAT CHUONG TRINH\n", ' ');
                char c;
                printf("\n%50c(!) Ban chua luu thay doi (!)\n", ' ');
                do
                {
                    fflush(stdin);
                    printf("\n%50c(?) Xac nhan thoat ma khong luu thay doi (y/n) (?): ", ' ');
                    scanf("%c", &c);
                    if (c != 'y' && c != 'n')
                        printf("\n%50c(!) Lua chon khong hop le (!) - Nhap lai (!)", ' ');
                    else
                    {
                        if (c == 'y')
                        {
                            information();
                            printf("\n\t%50c(*) Thoat chuong trinh sau 5s (*)\n", ' ');
                            Sleep(5000);
                            exit = true;
                        }
                        else
                            break;
                    }
                } while (c != 'y' && c != 'n');
            }
            break;
        }
        default:
            printf("\n\t%50c(!) Lua chon khong hop le (!)\n\a", ' ');
            system("pause");
            break;
        }
    } while (!exit);               // exit == true
    free(rooms);                   // giải phóng bộ nhớ của ds phòng
    clearRoomRenters(roomRenters); // giải phóng bộ nhớ của ds người thuê
}

void loading()
{
    char c[60] = "###############################################";
    printf("\n%46c[", ' ');
    for (int i = 0; i < strlen(c); i++)
    {
        Sleep(50); // delay 0.05s
        printf("%c", c[i]);
    }
    printf("]\n");
    printf("\n%50c(*) Dang nhap thanh cong (*)\n");
    Sleep(1000);
}

void information()
{
    system("cls");
    printf("%50c###########################################\n", ' ');
    printf("%50c##              GIANG VIEN               ##\n", ' ');
    printf("%50c##       Tran Thi Dung                   ##\n", ' ');
    printf("%50c##---------------------------------------##\n", ' ');
    printf("%50c##              THANH VIEN               ##\n", ' ');
    printf("%50c##       Hoang Gia Kiet (Truong nhom)    ##\n", ' ');
    printf("%50c##       Nguyen Thi Thanh Nhu            ##\n", ' ');
    printf("%50c##       Le Trung Quyen                  ##\n", ' ');
    printf("%50c##       Vo Thi Tuong Vi                 ##\n", ' ');
    printf("%50c##---------------------------------------##\n", ' ');
    printf("%50c##             XIN CAM ON                ##\n", ' ');
    printf("%50c###########################################\n", ' ');
}

void importRooms(Room rooms[], int &n)
{
    system("cls");
    printf("\n\t%40c(*) Dang nhap du lieu danh sach phong (*)\n", ' ');
    Sleep(2000); // delay 2s
    readRooms(rooms, n);
}

void importRoomRenters(RoomRenters &roomRenters, Room rooms[], int n)
{
    createList(roomRenters);
    system("cls");
    printf("\n\t%40c(*) Dang nhap du lieu danh sach nguoi thue (*)\n", ' ');
    Sleep(2000); // delay 2s
    readRoomRenters(roomRenters, rooms, n);
}

void saveFile(RoomRenters roomRenters, Room rooms[], int n)
{
    printf("\n\t%40c(*) Dang luu du lieu cac phong (*)\n", ' ');
    Sleep(2000); // delay 2s
    writeRooms(rooms, n);
    printf("\n\t%40c(*) Dang luu du lieu cac nguoi thue (*)\n", ' ');
    Sleep(2000); // delay 2s
    writeRoomRenters(roomRenters);
}