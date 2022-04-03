#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Rooms.hpp"

struct Date
{
    int day, month, year;
};

struct RoomRenter
{
    char fullName[50];     // họ tên
    Date birthDay;         // ngày tháng năm sinh
    bool sex;              // 0:nu   1:nam
    char phoneNumber[15];  // số điện thoại
    char identityCard[15]; // CCMD/CCCD
    Room *room = NULL;     // trỏ đến phòng thuê
};

void formatString(char *s);                                                      // định dạng lại chuỗi
bool isValidDate(int day, int month, int year);                                  // kiểm tra xem ngày có hợp lệ hay không
void inputDate(int &day, int &month, int &year);                                 // nhập ngày tháng năm
void chooseSex(RoomRenter &roomRenter);                                          // chọn giới tính
bool isValidRoom(Room rooms[], int n, int roomNumber);                           // kiểm tra số phòng có hợp lệ không
void chooseRoom(RoomRenter &roomRenter, Room rooms[], int n);                    // chọn phòng
void inputARoomRenter(RoomRenter &roomRenter, Room rooms[], int n);              // nhập 1 người thuê
void outputARoomRenterByVertical(RoomRenter roomRenter);                         // in 1 người thuê theo chiều dọc
void outputARoomRenterByHorizontal(RoomRenter roomRenter);                       // in 1 người thuê theo chiều ngang - có định dạng in
void readARoomRenter(FILE *fileIn, RoomRenter &roomRenter, Room rooms[], int n); // đọc 1 người thuê từ file
void writeARoomRenter(FILE *fileOut, RoomRenter roomRenter);                     // ghi 1 người thuê ra file

void formatString(char *s)
{
    // vd: nGUyeN VAN a -> Nguyen Van A
    for (int i = 0; i < strlen(s); i++)
    {
        if (i == 0 || (i > 0 && s[i - 1] == ' '))
        {
            if (s[i] >= 'a' && s[i] <= 'z')
                s[i] = s[i] - 32;
        }
        else
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] + 32;
        }
    }
}

bool isValidDate(int day, int month, int year) // kiểm tra ngày nhập
{
    if (year <= 0 || month <= 0 || month > 12 || day <= 0 || day > 31 || year >= 2022)
        return 0;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (day <= 31)
            return 1;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day <= 30)
            return 1;
    }
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        if (day <= 29)
            return 1;
    }
    else
    {
        if (day <= 28)
            return 1;
    }
    return 0;
}

void inputDate(int &day, int &month, int &year)
{
    do
    {
        printf("\n\t%50c(?) Nhap ngay: ", ' ');
        scanf("%d", &day);
        printf("\n\t%50c(?) Nhap thang: ", ' ');
        scanf("%d", &month);
        printf("\n\t%50c(?) Nhap nam: ", ' ');
        scanf("%d", &year);
        if (!isValidDate(day, month, year))
            printf("\n\t%40c(!) Ngay sinh khong hop le - Nhap lai (!)\n\a", ' ');
    } while (!isValidDate(day, month, year));
}

void chooseSex(RoomRenter &roomRenter)
{
    int choose;
    bool exit = false;
    do
    {
        printf("\n%50c  1. Nu", ' ');
        printf("\n%50c  2. Nam", ' ');
        printf("\n%50cNhap lua chon: ", ' ');
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            roomRenter.sex = 0;
            exit = true;
            break;
        case 2:
            roomRenter.sex = 1;
            exit = true;
            break;
        default:
            printf("\n\t%40c(!) Gioi tinh khong hop le - Nhap lai (!)\n\a", ' ');
            break;
        }
    } while (!exit);
}

bool isValidRoom(Room rooms[], int n, int roomNumber)
{
    for (int i = 0; i < n; i++)
    {
        if (rooms[i].number == roomNumber && rooms[i].isActive == 0)
            return 1;
    }
    return 0;
}

void chooseRoom(RoomRenter &roomRenter, Room rooms[], int n)
{
    int roomNumber;
    do
    {
        system("cls");
        outputRoomsAreEmtpy(rooms, n);
        printf("\n%50c(?) Nhap so phong: ", ' ');
        scanf("%d", &roomNumber);
        if (!isValidRoom(rooms, n, roomNumber))
        {
            printf("\n\t%40c(!) So phong khong hop le - Nhap lai (!)\n\a", ' ');
            system("pause");
        }
        else
            roomRenter.room = getRoom(rooms, n, roomNumber); // hàm này trong file Rooms.hpp
    } while (!isValidRoom(rooms, n, roomNumber));
}

void inputARoomRenter(RoomRenter &roomRenter, Room rooms[], int n)
{
    system("cls");
    fflush(stdin);
    printf("\n%50c(?) Nhap ho va ten: ", ' ');
    gets(roomRenter.fullName);
    formatString(roomRenter.fullName);
    system("cls");
    printf("\n%50c(*) Ngay sinh (*)\n", ' ');
    inputDate(roomRenter.birthDay.day, roomRenter.birthDay.month, roomRenter.birthDay.year);
    system("cls");
    printf("\n%50c(*) Gioi tinh (*)", ' ');
    chooseSex(roomRenter);
    system("cls");
    fflush(stdin);
    do
    {
        printf("\n%50c(?) Nhap so dien thoai (10 so): ", ' ');
        scanf("%s", &roomRenter.phoneNumber);
        if (strlen(roomRenter.phoneNumber) <= 0 || strlen(roomRenter.phoneNumber) > 10 || strlen(roomRenter.phoneNumber) != 10)
            printf("\n\t%40c(!) So dien thoai khong hop le - Nhap lai (!)\n\a", ' ');
    } while (strlen(roomRenter.phoneNumber) <= 0 || strlen(roomRenter.phoneNumber) > 10 || strlen(roomRenter.phoneNumber) != 10);
    system("cls");
    do
    {
        printf("\n%50c(?) Nhap so CCCD (12 so): ", ' ');
        scanf("%s", &roomRenter.identityCard);
        if ((strlen(roomRenter.identityCard) <= 0 || strlen(roomRenter.identityCard) > 12) || strlen(roomRenter.identityCard) != 12)
            printf("\n\t%40c(!) So CCCD khong hop le - Nhap lai (!)\n\a", ' ');
    } while ((strlen(roomRenter.identityCard) <= 0 || strlen(roomRenter.identityCard) > 12) || strlen(roomRenter.identityCard) != 12);
    system("cls");
    chooseRoom(roomRenter, rooms, n);
    roomRenter.room->isActive = 1; // cập nhật lại tình trạng phòng -> 1 (phòng đầy)
    system("cls");
}

void outputARoomRenterByVertical(RoomRenter roomRenter)
{
    printf("\n%50cHo va ten: %s", ' ', roomRenter.fullName);
    printf("\n%50cNgay sinh: %d/%d/%d", ' ', roomRenter.birthDay.day, roomRenter.birthDay.month, roomRenter.birthDay.year);
    char sex[4];
    if (roomRenter.sex == 0) // kiếm tra giới tính để in ra dạng chữ
        strcpy(sex, "Nu");
    else
        strcpy(sex, "Nam");
    printf("\n%50cGioi tinh: %s", ' ', sex);
    printf("\n%50cSo dien thoai: %s", ' ', roomRenter.phoneNumber);
    printf("\n%50cSo CCCD: %s", ' ', roomRenter.identityCard);
    printf("\n%50cSo phong: %d\n", ' ', roomRenter.room->number);
}

void outputARoomRenterByHorizontal(RoomRenter roomRenter)
{
    char sex[4];
    if (roomRenter.sex == 0)
        strcpy(sex, "Nu");
    else
        strcpy(sex, "Nam");
    printf("| %-30s| %-.2d/%.-2d/%-.4d    | %-9s | %-15s | %-20s | %-10d |\n", roomRenter.fullName, roomRenter.birthDay.day, roomRenter.birthDay.month, roomRenter.birthDay.year, sex, roomRenter.phoneNumber, roomRenter.identityCard, roomRenter.room->number);
}

void readARoomRenter(FILE *fileIn, RoomRenter &roomRenter, Room rooms[], int n)
{
    int roomNumber = 0; // lưu tạm số phòng lúc đọc từ file
    fgets(roomRenter.fullName, sizeof(roomRenter.fullName), fileIn);
    removeEnterChar(roomRenter.fullName); // hàm này nằm trong file Room.hpp -> lấy kí tự '\n' cuối chuỗi khi đọc file
    fscanf(fileIn, "%d%d%d", &roomRenter.birthDay.day, &roomRenter.birthDay.month, &roomRenter.birthDay.year);
    fscanf(fileIn, "%d", &roomRenter.sex);
    fscanf(fileIn, "%s%s", &roomRenter.phoneNumber, &roomRenter.identityCard);
    fscanf(fileIn, "%d", &roomNumber);
    fgetc(fileIn);                                   // lấy kí tự '\n' -> tránh lỗi
    roomRenter.room = getRoom(rooms, n, roomNumber); // lấy số phòng lưu tạm để trả về phòng của số phòng đó
    // roomRenter.room->isActive = 1;                   // cập nhật lại tình trạng phòng -> 1 (phòng đầy)
}

void writeARoomRenter(FILE *fileOut, RoomRenter roomRenter)
{
    fprintf(fileOut, "\n%s", roomRenter.fullName);
    fprintf(fileOut, "\n%.2d %.2d %.4d", roomRenter.birthDay.day, roomRenter.birthDay.month, roomRenter.birthDay.year);
    fprintf(fileOut, "\n%d", roomRenter.sex);
    fprintf(fileOut, "\n%s\n%s", roomRenter.phoneNumber, roomRenter.identityCard);
    fprintf(fileOut, "\n%d", roomRenter.room->number);
}