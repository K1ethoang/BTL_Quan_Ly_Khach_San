#include "menu.hpp"
#include "conio.h"

int main()
{
    system("color 0e");
    char username[20], checkUsername[20] = "nhom3";
    char password[5], checkPassword[5] = "1234";
    int time = 3;

    while (1)
    {
        system("cls");
        printf("%50c+ ---------------------------------------- +\n");
        printf("%50c|                DANG NHAP                 |\n");
        printf("%50c+ ---------------------------------------- +\n");
        printf("%50c  (?) Tai Khoan:  ");
        scanf("%s", &username);
        fflush(stdin);
        printf("%50c  (?) Mat Khau (4 ki tu):  ");
        for (int i = 0; i < 4; i++)
        {
            password[i] = getch();
            printf("%c", '*');
        }
        if (strcmp(password, checkPassword) == 0 && strcmp(username, checkUsername) == 0)
        {
            fflush(stdin);
            loading();
            menu();
            break;
        }
        else
        {
            if (time == 0)
            {
                printf("\n\n\t%30c (!) Chuong trinh tu dong thoat vi ban dang nhap qua so lan cho phep (!)\n\a", ' ');
                system("pause");
                break;
            }
            else
                printf("\n\n%60c(!) Ban con %d lan thu (!)\n\a", ' ', time--);
            system("pause");
        }
    }
    return 0;
}