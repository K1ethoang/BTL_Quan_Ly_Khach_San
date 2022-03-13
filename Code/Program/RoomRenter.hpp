#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Date
{
    int day = 0, month = 0, year = 0;
};

struct RoomRenter
{
    char fullName[50];      // họ tên
    Date birthDay;          // ngày tháng năm sinh
    bool sex;               // 0:nu   1:nam
    char phoneNumber[15];   // số điện thoại
    char identityCard[15];  // CCMD/CCCD
    int *roomNumber = NULL; // trỏ đến phòng thuê
};

bool validDate(int day, int month, int year);              // xem ngày có hợp lệ hay không
void inputDate(int &day, int &month, int &year);           // nhập ngày tháng năm
void chooseSex(RoomRenter &roomRenter);                    // chọn giới tính
void inputARoomRenter(RoomRenter &roomRenter);             // nhập 1 người thuê
void outputARoomRenterByVertical(RoomRenter roomRenter);   // in 1 người thuê theo chiều dọc
void outputARoomRenterByHorizontal(RoomRenter roomRenter); // in 1 người thuê theo chiều ngang - có định dạng in

bool validDate(int day, int month, int year) // kiểm tra ngày nhập
{
    if (year <= 0 || month <= 0 || month > 12 || day <= 0 || day > 31)
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
        printf("\n%50c(?) Nhap ngay: ", ' ');
        scanf("%d", &day);
        printf("\n%50c(?) Nhap thang: ", ' ');
        scanf("%d", &month);
        printf("\n%50c(?) Nhap nam: ", ' ');
        scanf("%d", &year);
        if (!validDate(day, month, year))
        {
            printf("\n\t%50c(!) Ngay sinh khong hop le - Nhap lai (!)\n\a", ' ');
        }
    } while (!validDate(day, month, year));
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

void inputARoomRenter(RoomRenter &roomRenter)
{
    system("cls");
    fflush(stdin);
    printf("\n%50c(?) Nhap ho va ten: ", ' ');
    gets(roomRenter.fullName);
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
        printf("\n%50c(?) Nhap so dien thoai: ", ' ');
        gets(roomRenter.phoneNumber);
        if (strlen(roomRenter.phoneNumber) <= 0 || strlen(roomRenter.phoneNumber) > 10 || strlen(roomRenter.phoneNumber) != 10)
            printf("\n\t%40c(!) So dien thoai khong hop le - Nhap lai (!)\n\a", ' ');
    } while (strlen(roomRenter.phoneNumber) <= 0 || strlen(roomRenter.phoneNumber) > 10 || strlen(roomRenter.phoneNumber) != 10);
    system("cls");
    do
    {
        printf("\n%50c(?) Nhap so CCCD: ", ' ');
        gets(roomRenter.identityCard);
        if ((strlen(roomRenter.identityCard) <= 0 || strlen(roomRenter.identityCard) > 12) || strlen(roomRenter.identityCard) != 12)
            printf("\n\t%40c(!) So CMND/CCCD khong hop le - Nhap lai (!)\n\a", ' ');
    } while ((strlen(roomRenter.identityCard) <= 0 || strlen(roomRenter.identityCard) > 12) || strlen(roomRenter.identityCard) != 12);
    system("cls");
}

void outputARoomRenterByVertical(RoomRenter roomRenter)
{
    printf("\n%50cHo va ten: %s", ' ', roomRenter.fullName);
    printf("\n%50cNgay sinh: %d/%d/%d", ' ', roomRenter.birthDay.day, roomRenter.birthDay.month, roomRenter.birthDay.year);
    char sex[4];
    if (sex == 0)
        strcpy(sex, "Nu");
    else
        strcpy(sex, "Nam");
    printf("\n%50cGioi tinh: %s", ' ', sex);
    printf("\n%50cSo dien thoai: %s", ' ', roomRenter.phoneNumber);
    printf("\n%50cSo CCCD: %s", ' ', roomRenter.identityCard);
    printf("\n%50cSo phong: %d\n", ' ', roomRenter.roomNumber);
}

void outputARoomRenterByHorizontal(RoomRenter roomRenter)
{
    char sex[4];
    if (sex == 0)
        strcpy(sex, "Nu");
    else
        strcpy(sex, "Nam");
    printf("| %-30s| %-.2d/%.-2d/%-.4d    | %-9s | %-15s | %-20s | %-10d |\n", roomRenter.fullName, roomRenter.birthDay.day, roomRenter.birthDay.month, roomRenter.birthDay.year, sex, roomRenter.phoneNumber, roomRenter.identityCard, roomRenter.roomNumber);
}