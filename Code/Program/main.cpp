#include "menu.hpp"
#include "conio.h"

int main()
{
    system("color 0B");
    char username[20], checkUsername[20] = "nhom3";
    char password[5], checkPassword[5] = "1234";
    int time = 3;
    while (1)
    {
        system("cls");
        printf("%50c+ ---------------------------------------- +\n", ' ');
        printf("%50c|                DANG NHAP                 |\n", ' ');
        printf("%50c+ ---------------------------------------- +\n", ' ');
        printf("%50c  (?) Tai Khoan:  ", ' ');
        scanf("%s", &username);
        fflush(stdin);
        printf("%50c  (?) Mat Khau (%d ki tu):  ", ' ', strlen(checkPassword));
        for (int i = 0; i < strlen(checkPassword); i++)
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
                printf("\n\n\t%30c (!) Chuong trinh tu dong thoat sau 2s (!)\n\a", ' ');
                Sleep(2000);
                break;
            }
            else
                printf("\n\n%60c(!) Ban con %d lan thu (!)\n\a", ' ', time--);
            system("pause");
        }
    }
    return 0;
}
