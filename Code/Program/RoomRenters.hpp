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

void createList(RoomRenters *roomRenters);
Node *createNode(RoomRenter value);
void addNodeInTail(RoomRenters *roomRenters, RoomRenter roomRenter);
void addARoomRenter(RoomRenters *roomRenters);
void outputRoomRenters(RoomRenters roomRenters);

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

void addARoomRenter(RoomRenters *roomRenters)
{
    RoomRenter r;
    inputARoomRenter(&r);
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