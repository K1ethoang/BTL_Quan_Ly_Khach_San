#pragma once
#include <stdio.h>
#include <string.h>

struct Room
{
    int number;    // số phòng
    char type[10]; // loại phòng: thường or cao cấp
    bool isActive; // tình trạng phòng - 0:trống   1:đầy
};
void chooseRoomType(Room &room);           // chọn loại phòng
void chooseRoomStatus(Room &room);         // chọn tình trạng phòng
void inputARoom(Room *room);               // nhập 1 phòng
void outputARoomByVertical(Room room);     // in 1 phòng theo chiều dọc
void outputARoomByHorizontal(Room room);   // in 1 phòng theo chiều ngang
void outputRooms(Room room[], int n);      // xuất danh sách các phòng
void removeEnterChar(char *s);             // xoá kí tự \n
void readARoom(FILE *fileIn, Room &room);  // đọc 1 phòng từ file
void writeARoom(FILE *fileOut, Room room); // ghi 1 phòng
void readRooms(Room room[], int &n);       // đọc danh sách các phòng

void chooseRoomType(Room &room)
{
    int choose;
    bool exit = false;
    do
    {
        printf("\n%50c  1. Thuong", ' ');
        printf("\n%50c  2. Cao cap", ' ');
        printf("\n%50cNhap lua chon: ", ' ');
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            strcpy(room.type, "Thuong");
            exit = true;
            break;
        case 2:
            strcpy(room.type, "Cao cap");
            exit = true;
            break;
        default:
            printf("\n\t%40c(!) Loai phong khong hop le - Nhap lai (!)\n\a", ' ');
            break;
        }
    } while (!exit);
}

void chooseRoomStatus(Room &room)
{
    int choose;
    bool exit = false;
    do
    {
        printf("\n%50c  1. Phong trong", ' ');
        printf("\n%50c  2. Phong day", ' ');
        printf("\n%50cNhap lua chon: ", ' ');
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            room.isActive = 0;
            exit = true;
            break;
        case 2:
            room.isActive = 1;
            exit = true;
            break;
        default:
            printf("\n\t%40c(!) Tinh trang phong khong hop le (!)\n\a", ' ');
            break;
        }
    } while (!exit);
}

void inputARoom(Room &room)
{
    system("cls");
    printf("\n%50c(?) Nhap so phong: ", ' ');
    scanf("%d", &room.number);
    system("cls");
    printf("\n%50c(*) Loai phong (*)", ' ');
    fflush(stdin);
    chooseRoomType(room);
    system("cls");
    printf("\n%50c(*) Tinh trang (*)", ' ');
    chooseRoomStatus(room);
}

void outputARoomByVertical(Room room)
{
    fflush(stdin);
    printf("\n%50cSo phong: %d", ' ', room.number);
    printf("\n%50cLoai phong: %s", ' ', room.type);
    char roomStatus[20];
    if (room.isActive) // isActive = 1
        strcpy(roomStatus, "Day");
    else // isActive = 1
        strcpy(roomStatus, "Trong");
    printf("\n%50cTinh trang: %s", ' ', roomStatus);
}

void outputARoomByHorizontal(Room room)
{
    char roomStatus[20];
    if (room.isActive) // isActive = 1
        strcpy(roomStatus, "Day");
    else // isActive = 1
        strcpy(roomStatus, "Trong");
    printf("|    %-3d     |    %-11s |    %-11s |\n", room.number, room.type, roomStatus);
}

void removeEnterChar(char *s)
{
    size_t length = strlen(s);
    // kiet\n\0 -> kiet\0\0
    if (s[length - 1] == '\n')
        s[length - 1] = '\0';
}

void outputRooms(Room room[], int n)
{
    int count = 1;
    printf("\n");
    printf("%50c+ ----- + ---------- + -------------- + -------------- +\n", ' ');
    printf("%50c|  STT  |  So phong  |   Loai phong   |   Tinh trang   |\n", ' ');
    printf("%50c+ ----- + ---------- + -------------- + -------------- +\n", ' ');
    for (int i = 0; i < n; i++)
    {
        printf("%50c|   %d   ", ' ', count++);
        outputARoomByHorizontal(room[i]);
    }
    printf("%50c+ ----- + ---------- + -------------- + -------------- +\n", ' ');
}

void readARoom(FILE *fileIn, Room &room)
{
    fscanf(fileIn, "%d", &room.number);
    fgetc(fileIn);
    fgets(room.type, sizeof(room.type), fileIn);
    removeEnterChar(room.type);
    fscanf(fileIn, "%d", &room.isActive);
}

void writeARoom(FILE *fileOut, Room room)
{
    fprintf(fileOut, "%d\n", room.number);
    fprintf(fileOut, "%s\n", room.type);
    fprintf(fileOut, "%d\n", room.isActive);
}

void readRooms(Room room[], int &n)
{
    FILE *fileIn = fopen("../File/room/room.in", "r");
    if (fileIn == NULL)
        printf("\n%50c(!) Loi khi mo file (!)\n\a");
    else
    {
        n = 0;
        while (!feof(fileIn))
        {
            Room r;
            readARoom(fileIn, r);
            room[n++] = r; // đưa phòng vừa đọc vào mảng
        }
    }
    fclose(fileIn);
}