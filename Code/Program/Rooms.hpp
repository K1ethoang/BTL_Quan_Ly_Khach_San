#include "Room.hpp"

void readRooms(Room room[], int &n);  // đọc danh sách các phòng
void writeRooms(Room room[], int &n); // ghi danh sách các phòng
void outputRooms(Room room[], int n); // xuất danh sách các phòng

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
            fflush(stdin);
            Room r;
            readARoom(fileIn, r);
            room[n++] = r; // đưa phòng vừa đọc vào mảng
            printf("\n%50c(*) Doc ban ghi thu %d (*)\n", ' ', n);
        }
    }
    fclose(fileIn);
}

void writeRooms(Room room[], int &n)
{
    int count = 1;
    FILE *fileOut = fopen("../File/room/room.in", "w");
    if (fileOut == NULL)
        printf("\n%50c(!) Loi khi mo file (!)\n\a");
    else
    {
        for (int i = 0; i < n; i++)
        {
            fflush(stdin);
            writeARoom(fileOut, room[i]);
            printf("\n%50c(*) Ban ghi thu %d (*)\n", ' ', count++);
        }
    }
    fclose(fileOut);
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
        printf("%50c|  %-5d", ' ', count++);
        outputARoomByHorizontal(room[i]);
    }
    printf("%50c+ ----- + ---------- + -------------- + -------------- +\n", ' ');
}
