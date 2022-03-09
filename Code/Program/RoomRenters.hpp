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
