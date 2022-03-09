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

bool validDate(int *day, int *month, int *year);
void inputDate(int *day, int *month, int *year);
bool chooseSex();
void inputARoomRenter(RoomRenter *roomRenter);
void outputARoomRenter(RoomRenter roomRenter);

bool validDate(int *day, int *month, int *year) // kiểm tra ngày nhập
{
    if (*year <= 0 || *month <= 0 || *month > 12 || *day <= 0 || *day > 31)
        return 0;
    if (*month == 1 || *month == 3 || *month == 5 || *month == 7 || *month == 8 || *month == 10 || *month == 12)
    {
        if (*day <= 31)
            return true;
    }
    if (*month == 4 || *month == 6 || *month == 9 || *month == 11)
    {
        if (*day <= 30)
            return true;
    }
    if ((*year % 4 == 0 && *year % 100 != 0) || *year % 400 == 0)
    {
        if (*day <= 29)
            return 1;
    }
    else
    {
        if (*day <= 28)
            return 1;
    }
    return 0;
}

void inputDate(int *day, int *month, int *year)
{
    do
    {
        printf("\n(?) Nhap ngay: ");
        scanf("%d", day);
        printf("\n(?) Nhap thang: ");
        scanf("%d", month);
        printf("\n(?) Nhap nam: ");
        scanf("%d", year);
        if (!validDate(day, month, year))
        {
            printf("\n\t(!) Ngay thang khong hop le - Nhap lai (!)\n");
        }
    } while (!validDate(day, month, year));
}

bool chooseSex()
{
    int choose;
    bool exit = false, sex;
    do
    {
        printf("\n  1. Nu");
        printf("\n  2. Nam");
        printf("\nNhap lua chon: ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            sex = 0;
            exit = true;
            break;
        case 2:
            sex = 1;
            exit = true;
            break;
        default:
            printf("\n\t(!) Gioi tinh khong hop le - Nhap lai (!)\n");
            break;
        }
    } while (!exit);
    return sex;
}

void inputARoomRenter(RoomRenter *roomRenter)
{
    printf("\n(?) Nhap ho va ten: ");
    gets(roomRenter->fullName);
    system("cls");
    printf("\n\tNgay sinh\n");
    inputDate(&roomRenter->birthDay.day, &roomRenter->birthDay.month, &roomRenter->birthDay.year);
    system("cls");
    printf("\n(?) Gioi tinh");
    roomRenter->sex = chooseSex();
    system("cls");
    fflush(stdin);
    do
    {
        printf("\n(?) Nhap so dien thoai: ");
        gets(roomRenter->phoneNumber);
        if (strlen(roomRenter->phoneNumber) <= 0 || strlen(roomRenter->phoneNumber) > 10 || strlen(roomRenter->phoneNumber) != 10)
            printf("\n\t(!) So dien thoai khong hop le - Nhap lai (!)\n");
    } while (strlen(roomRenter->phoneNumber) <= 0 || strlen(roomRenter->phoneNumber) > 10 || strlen(roomRenter->phoneNumber) != 10);
    system("cls");
    do
    {
        printf("\n(?) Nhap so CCCD: ");
        gets(roomRenter->identityCard);
        if ((strlen(roomRenter->identityCard) <= 0 || strlen(roomRenter->identityCard) > 12) || strlen(roomRenter->identityCard) != 12)
            printf("\n\t(!) So CMND/CCCD khong hop le - Nhap lai (!)\n");
    } while ((strlen(roomRenter->identityCard) <= 0 || strlen(roomRenter->identityCard) > 12) || strlen(roomRenter->identityCard) != 12);
    system("cls");
}

void outputARoomRenter(RoomRenter roomRenter)
{
    printf("\nHo va ten: %s", roomRenter.fullName);
    printf("\nNgay sinh: %d/%d/%d", roomRenter.birthDay.day, roomRenter.birthDay.month, roomRenter.birthDay.year);
    char sex[4];
    if (roomRenter.sex == 0)
        strcpy(sex, "Nu");
    else
        strcpy(sex, "Nam");
    printf("\nGioi tinh: %s", sex);
    printf("\nSo dien thoai: %s", roomRenter.phoneNumber);
    printf("\nSo CCCD: %s", roomRenter.identityCard);
    printf("\nSo phong: %d", roomRenter.roomNumber);
}