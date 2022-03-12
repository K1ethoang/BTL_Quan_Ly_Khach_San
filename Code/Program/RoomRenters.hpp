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

void createList(RoomRenters *roomRenters);                                 // tạo list
Node *createNode(RoomRenter value);                                        // tạo 1 node
bool isExitPhoneNumber(RoomRenters roomRenters, const char *phoneNumber);  // kiểm tra SĐT này có chưa
void addNodeInTail(RoomRenters *roomRenters, RoomRenter roomRenter);       // thêm node vào cuối
void addARoomRenter(RoomRenters *roomRenters);                             // thêm 1 người thuê vào list
void outputRoomRenters(RoomRenters roomRenters);                           // in list người thuê
void swapTwoRoomRenters(RoomRenter *roomRenter1, RoomRenter *roomRenter2); // hoán vị 2 người thuê
void editRoomRenters(RoomRenters *roomRenters, const char *phoneNumber);   // chỉnh sửa danh sách người thuê

void createList(RoomRenters *roomRenters)
{
    roomRenters->pHead = NULL;
    roomRenters->pTail = NULL;
}

Node *createNode(RoomRenter value)
{
    Node *p = (Node *)calloc(1, sizeof(Node));
    if (p == NULL)
    {
        printf("\n\t(!) Khong du bo nho (!)");
        return NULL;
    }
    else
    {
        p->data = value;
        p->pNext = NULL;
    }
    return p;
}

void addNodeInTail(RoomRenters *roomRenters, RoomRenter roomRenter)
{
    Node *p = createNode(roomRenter);
    if (roomRenters->pHead == NULL)
        roomRenters->pHead = roomRenters->pTail = p;
    else
    {
        roomRenters->pTail->pNext = p;
        roomRenters->pTail = p;
    }
}

bool isExitPhoneNumber(RoomRenters roomRenters, const char *phoneNumber)
{
    for (Node *t = roomRenters.pHead; t != NULL; t = t->pNext)
    {
        if (strcmp(t->data.phoneNumber, phoneNumber) == 0)
            return 1;
    }
    return 0;
}

void addARoomRenter(RoomRenters *roomRenters)
{
    RoomRenter r;
    inputARoomRenter(&r);
    do
    {
        if (isExitPhoneNumber(*roomRenters, r.phoneNumber))
        {
            system("cls");
            printf("\n\t(!) Da ton tai nguoi thue voi SDT nay (!)\n\a");
            printf("\n(?) Nhap lai so dien thoai khac: ");
            fflush(stdin);
            gets(r.phoneNumber);
        }
    } while (isExitPhoneNumber(*roomRenters, r.phoneNumber));
    system("cls");
    printf("\n\tTHONG TIN NGUOI THUE VUA NHAP\n");
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

void editRoomRenters(RoomRenters *roomRenters, const char *phoneNumber)
{
    for (Node *t = roomRenters->pHead; t != NULL; t = t->pNext)
    {
        if (strcmp(t->data.phoneNumber, phoneNumber) == 0)
        {
            inputARoomRenter(&(t->data));
            break;
        }
    }
}