#pragma once
#include "RoomRenter.hpp"
#include "Room.hpp"

struct Node
{
    RoomRenter data; // dữ liệu lưu trữ là 1 khách thuê (1 phần tử)
    Node *pNext;
};

struct RoomRenters
{
    Node *pHead;
    Node *pTail;
};

void createList(RoomRenters &roomRenters);                                 // tạo list
Node *createNode(RoomRenter value);                                        // tạo 1 node
bool isExitPhoneNumber(RoomRenters roomRenters, char *phoneNumber);        // kiểm tra SĐT này có chưa
bool isExitIdentityCard(RoomRenters roomRenters, char *identityCard);      // kiểm tra CCCD này có chưa
void addNodeInTail(RoomRenters &roomRenters, RoomRenter roomRenter);       // thêm node vào cuối
void removeNodeInHead(RoomRenters &roomRenters);                           // xoá node đầu
void removeNodeInTail(RoomRenters &roomRenters);                           // xoá node cuối
void addARoomRenter(RoomRenters &roomRenters);                             // thêm 1 người thuê vào list
void outputRoomRenters(RoomRenters roomRenters);                           // in list người thuê
void swapTwoRoomRenters(RoomRenter &roomRenter1, RoomRenter &roomRenter2); // hoán vị 2 người thuê
void UpdateRoomRenter(RoomRenters &roomRenters, char *phoneNumber);        // chỉnh sửa danh sách người thuê
void deleteARoomRenter(RoomRenters &roomRenters, char *phoneNumber);       // xoá 1 người thuê

void createList(RoomRenters &roomRenters)
{
    roomRenters.pHead = NULL;
    roomRenters.pTail = NULL;
}

Node *createNode(RoomRenter value)
{
    Node *p = (Node *)calloc(1, sizeof(Node));
    if (p == NULL)
    {
        printf("\n\t%50c(!) Khong du bo nho (!)", ' ');
        return NULL;
    }
    else
    {
        p->data = value;
        p->pNext = NULL;
    }
    return p;
}

void addNodeInTail(RoomRenters &roomRenters, RoomRenter roomRenter)
{
    Node *p = createNode(roomRenter);
    if (roomRenters.pHead == NULL)
        roomRenters.pHead = roomRenters.pTail = p;
    else
    {
        roomRenters.pTail->pNext = p;
        roomRenters.pTail = p;
    }
}

void removeNodeInHead(RoomRenters &roomRenters)
{
    if (roomRenters.pHead == NULL) // không có phần tử nào
        return;
    else
    {
        Node *p = roomRenters.pHead;
        roomRenters.pHead = p->pNext;
        free(p);
    }
}

void removeNodeInTail(RoomRenters &roomRenters)
{
    if (roomRenters.pHead == NULL)
        return;
    // nếu phần tử nằm đầu cũng là phần tử nằm cuối
    else if (roomRenters.pHead == roomRenters.pTail)
        removeNodeInHead(roomRenters);
    else
    {
        for (Node *t = roomRenters.pHead; t != NULL; t = t->pNext)
        {
            if (t->pNext == roomRenters.pTail)
            {
                free(roomRenters.pTail);
                t->pNext = NULL;
                roomRenters.pTail = t;
                return;
            }
        }
    }
}

bool isExitPhoneNumber(RoomRenters roomRenters, char *phoneNumber)
{
    for (Node *t = roomRenters.pHead; t != NULL; t = t->pNext)
    {
        if (strcmp(t->data.phoneNumber, phoneNumber) == 0) // giống nhau = chuỗi
            return 1;
    }
    return 0;
}

bool isExitIdentityCard(RoomRenters roomRenters, char *identityCard)
{
    for (Node *t = roomRenters.pHead; t != NULL; t = t->pNext)
    {
        if (strcmp(t->data.identityCard, identityCard) == 0)
            return 1;
    }
    return 0;
}

void addARoomRenter(RoomRenters &roomRenters)
{
    RoomRenter r;
    inputARoomRenter(r);
    do
    {
        if (isExitPhoneNumber(roomRenters, r.phoneNumber))
        {
            system("cls");
            printf("\n\t%40c(!) Da ton tai nguoi thue voi so dien thoai nay (!)\n\a", ' ');
            printf("\n%50c(?) Nhap lai so dien thoai khac: ", ' ');
            fflush(stdin);
            gets(r.phoneNumber);
        }
    } while (isExitIdentityCard(roomRenters, r.phoneNumber));
    do
    {
        if (isExitIdentityCard(roomRenters, r.identityCard))
        {
            system("cls");
            printf("\n\t%40c(!) Da ton tai nguoi thue voi so CCCD nay (!)\n\a", ' ');
            printf("\n%50c(?) Nhap lai so CCCD khac: ", ' ');
            fflush(stdin);
            gets(r.identityCard);
        }
    } while (isExitIdentityCard(roomRenters, r.identityCard));
    system("cls");
    printf("\n\t%50cTHONG TIN NGUOI THUE VUA NHAP\n", ' ');
    outputARoomRenterByVertical(r);
    system("pause");
    addNodeInTail(roomRenters, r);
}

void outputRoomRenters(RoomRenters roomRenters)
{
    int count = 1;
    printf("+ ------- + ----------------------------- + ------------- + --------- + --------------- + -------------------- + ---------- + \n");
    printf("|   STT   |           Ho va ten           |   Ngay sinh   | Gioi tinh |  So dien thoai  |        So CCCD       |  So phong  | \n");
    printf("+ ------- + ----------------------------- + ------------- + --------- + --------------- + -------------------- + ---------- + \n");

    for (Node *t = roomRenters.pHead; t != NULL; t = t->pNext)
    {
        printf("| %-7d ", count++);
        outputARoomRenterByHorizontal(t->data);
    }
    printf("+ ------- + ----------------------------- + ------------- + --------- + --------------- + -------------------- + ---------- + \n");
}

void swapTwoRoomRenters(RoomRenter *roomRenter1, RoomRenter *roomRenter2)
{
    RoomRenter temp = *roomRenter1;
    *roomRenter1 = *roomRenter2;
    *roomRenter2 = temp;
}

void UpdateRoomRenter(RoomRenters &roomRenters, char *phoneNumber)
{
    if (!isExitPhoneNumber(roomRenters, phoneNumber))
        printf("\n\t%40c(!) Khong ton tai nguoi thue nay (!)\n\a", ' ');
    else
    {
        for (Node *t = roomRenters.pHead; t != NULL; t = t->pNext)
        {
            if (strcmp(t->data.phoneNumber, phoneNumber) == 0)
            {
                inputARoomRenter(t->data);
                printf("\n\t%40c(*) Chinh sua thanh cong (*)\n", ' ');
                break;
            }
        }
    }
}

void deleteARoomRenter(RoomRenters &roomRenters, char *phoneNumber)
{
    // nếu phần tử nằm đầu
    if (strcmp(roomRenters.pHead->data.phoneNumber, phoneNumber) == 0)
    {
        removeNodeInHead(roomRenters);
        printf("\n\t%40c(*) Thanh toan thanh cong (*)\n", ' ');
    }
    // nếu phần tử nằm cuối
    else if (strcmp(roomRenters.pTail->data.phoneNumber, phoneNumber) == 0)
    {
        removeNodeInTail(roomRenters);
        printf("\n\t%40c(*) Thanh toan thanh cong (*)\n", ' ');
    }
    else
    {
        if (!isExitPhoneNumber(roomRenters, phoneNumber))
            printf("\n\t%40c(!) Khong ton tai nguoi thue nay (!)\n\a", ' ');
        else
        {
            Node *g = NULL; // node nằm trước node cần xoá
            for (Node *t = roomRenters.pHead->pNext; t != NULL; t = t->pNext)
            {
                if (strcmp(t->data.phoneNumber, phoneNumber) == 0)
                {
                    g->pNext = t->pNext; // cập nhật lại node nằm trước node cần xoá liên kết với node kế tiếp của nó
                    free(t);
                    printf("\n\t%40c(*) Thanh toan thanh cong (*)\n", ' ');
                    return;
                }
                g = t;
            }
        }
    }
}