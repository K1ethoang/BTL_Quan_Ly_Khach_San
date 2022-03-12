#pragma once
#include <stdio.h>
#include <string.h>

struct Room
{
    int number;    // số phòng
    char type[20]; // loại phòng: thường or cao cấp
    bool isActive; // tình trạng phòng - 0:trống   1:đầy
};
void chooseRoomType(Room *room);         // chọn loại phòng
bool chooseRoomStatus();                 // chọn tình trạng phòng
const char *getStatus(bool isActive);    // lấy chuỗi tình trạng phòng
void inputARoom(Room *room);             // nhập 1 phòng
void outputARoomByVertical(Room room);   // in 1 phòng theo chiều dọc
void outputARoomByHorizontal(Room room); // in 1 phòng theo chiều dọc
void outputRooms(Room room[], int n);    // in danh sách các phòng hiện có - mảng
void removeEnterChar(char *s);           // xoá kí tự \n
void readARoom(Room *room);
void writeARoom(Room room);

void chooseRoomType(Room *room)
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
            strcpy(room->type, "Thuong");
            exit = true;
            break;
        case 2:
            strcpy(room->type, "Cao cap");
            exit = true;
            break;
        default:
            printf("\n\t%40c(!) Loai phong khong hop le - Nhap lai (!)\n\a", ' ');
            break;
        }
    } while (!exit);
}

bool chooseRoomStatus()
{
    int choose;
    bool exit = false, isActive;
    do
    {
        printf("\n%50c  1. Phong trong", ' ');
        printf("\n%50c  2. Phong day", ' ');
        printf("\n%50cNhap lua chon: ", ' ');
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            isActive = 0;
            exit = true;
            break;
        case 2:
            isActive = 1;
            exit = true;
            break;
        default:
            printf("\n\t%40c(!) Tinh trang phong khong hop le (!)\n\a", ' ');
            break;
        }
    } while (!exit);
    return isActive;
}

const char *getStatus(bool isActive)
{
    if (isActive) // isActive = 1
        return "Phong day";
    else // isActive = 1
        return "Phong trong";
}

void inputARoom(Room *room)
{
    system("cls");
    printf("\n%50c(?) Nhap so phong: ", ' ');
    scanf("%d", &room->number);
    system("cls");
    printf("\n%40c(*) Loai phong (*)", ' ');
    fflush(stdin);
    chooseRoomType(room);
    system("cls");
    printf("\n%40c(*) Tinh trang (*)", ' ');
    room->isActive = chooseRoomStatus();
}

void outputARoomByVertical(Room room)
{
    printf("\n%50cSo phong: %d", ' ', room.number);
    printf("\n%50cLoai phong: %s", ' ', room.type);
    printf("\n%50cTinh trang: %s", ' ', getStatus(room.isActive));
}

void outputARoomByHorizontal(Room room)
{
    printf("| %-.3d|   %-20s|    %-20s|\n", room.number, room.type, getStatus(room.isActive));
}

void outputRooms(Room room[], int n); // in danh sách các phòng hiện có - mảng

void removeEnterChar(char *s)
{
    size_t length = strlen(s);
    // kiet\n\0 -> kiet\0\0
    if (s[length - 1] == '\n')
        s[length - 1] = '\0';
}

void readARoom(Room *room)
{
    FILE *fileIn = fopen("../File/room_in.txt", "r");
    if (fileIn == NULL)
        printf("\n\t%40c (!) Loi khi mo file (!)\n\a", ' ');
    else
    {
        fscanf(fileIn, "%d", &room->number);
        fgetc(fileIn);
        fgets(room->type, sizeof(room->type), fileIn);
        removeEnterChar(room->type);
        fscanf(fileIn, "%d", &room->isActive);
    }
    fclose(fileIn);
}

void writeARoom(Room room)
{
    FILE *fileOut = fopen("../File/room_out.txt", "w");
    fprintf(fileOut, "%d\n", room.number);
    fprintf(fileOut, "%s\n", room.type);
    fprintf(fileOut, "%d\n", room.isActive);
    fclose(fileOut);
}