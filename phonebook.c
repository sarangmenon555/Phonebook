#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

struct person
{
    char name[35];
    char address[50];
    char father_name[35];
    char mother_name[30];
    long int mble_no;
    char sex[8];
    char mail[100];
    char citision_no[20];
};

void menu();
void got(char *name);
void start();
void back();
void addrecord();
void listrecord();
void modifyrecord();
void deleterecord();
void searchrecord();

int main()
{
    system("color 5f");
    start();
    return 0;
}

void back()
{
    start();
}

void start()
{
    menu();
}

void menu()
{
    system("cls");
    printf("\t\t**********WELCOME TO PHONEBOOK*************");
    printf("\n\n\t\t\t MENU\t\t\n\n");
    printf("\t1.Add New \t2.List \t3.Exit \n\t4.Modify \t5.Search\t6.Delete");

    switch(getch())
    {
        case '1': addrecord(); break;
        case '2': listrecord(); break;
        case '3': exit(0); break;
        case '4': modifyrecord(); break;
        case '5': searchrecord(); break;
        case '6': deleterecord(); break;
        default:
            system("cls");
            printf("\nEnter 1 to 6 only");
            printf("\nEnter any key");
            getch();
            menu();
    }
}

void addrecord()
{
    system("cls");
    FILE *f;
    struct person p;
    f = fopen("project", "ab+");
    if(f == NULL)
    {
        printf("\nError opening file.");
        getch();
        menu();
        return;
    }
    printf("\nEnter name: ");
    got(p.name);
    printf("\nEnter the address: ");
    got(p.address);
    printf("\nEnter father name: ");
    got(p.father_name);
    printf("\nEnter mother name: ");
    got(p.mother_name);
    printf("\nEnter phone no.: ");
    scanf("%ld", &p.mble_no);
    int ch; while((ch = getchar()) != '\n' && ch != EOF);
    printf("Enter sex: ");
    got(p.sex);
    printf("\nEnter e-mail address: ");
    got(p.mail);
    printf("\nEnter citizenship no: ");
    got(p.citision_no);
    fwrite(&p, sizeof(p), 1, f);
    fclose(f);
    printf("\nRecord saved.");
    printf("\nEnter any key");
    getch();
    system("cls");
    menu();
}

void listrecord()
{
    struct person p;
    FILE *f;
    f = fopen("project", "rb");
    if(f == NULL)
    {
        printf("\nNo records found.");
        printf("\nEnter any key");
        getch();
        system("cls");
        menu();
        return;
    }
    while(fread(&p, sizeof(p), 1, f) == 1)
    {
        printf("\n\n\n YOUR RECORD IS\n\n");
        printf("\nName        : %s", p.name);
        printf("\nAddress     : %s", p.address);
        printf("\nFather Name : %s", p.father_name);
        printf("\nMother Name : %s", p.mother_name);
        printf("\nMobile No   : %ld", p.mble_no);
        printf("\nSex         : %s", p.sex);
        printf("\nE-mail      : %s", p.mail);
        printf("\nCitizenship : %s", p.citision_no);
        printf("\n\nEnter any key for next record");
        getch();
        system("cls");
    }
    fclose(f);
    printf("\nNo more records.");
    printf("\nEnter any key");
    getch();
    system("cls");
    menu();
}

void searchrecord()
{
    struct person p;
    FILE *f;
    char name[100];
    int flag = 0;

    f = fopen("project", "rb");
    if(f == NULL)
    {
        printf("\nNo records found.");
        printf("\nEnter any key");
        getch();
        system("cls");
        menu();
        return;
    }
    printf("\nEnter name of person to search: ");
    got(name);
    while(fread(&p, sizeof(p), 1, f) == 1)
    {
        if(strcmp(p.name, name) == 0)
        {
            flag = 1;
            printf("\n\tDetail Information About %s", name);
            printf("\nName        : %s", p.name);
            printf("\nAddress     : %s", p.address);
            printf("\nFather Name : %s", p.father_name);
            printf("\nMother Name : %s", p.mother_name);
            printf("\nMobile No   : %ld", p.mble_no);
            printf("\nSex         : %s", p.sex);
            printf("\nE-mail      : %s", p.mail);
            printf("\nCitizenship : %s", p.citision_no);
            break;
        }
    }
    if(flag == 0)
        printf("\nRecord not found.");
    fclose(f);
    printf("\nEnter any key");
    getch();
    system("cls");
    menu();
}

void deleterecord()
{
    struct person p;
    FILE *f, *ft;
    int flag = 0;
    char name[100];

    f = fopen("project", "rb");
    if(f == NULL)
    {
        printf("CONTACT'S DATA NOT ADDED YET.");
        printf("\nEnter any key");
        getch();
        system("cls");
        menu();
        return;
    }
    ft = fopen("temp", "wb+");
    if(ft == NULL)
    {
        printf("File opening error.");
        fclose(f);
        printf("\nEnter any key");
        getch();
        system("cls");
        menu();
        return;
    }
    printf("Enter CONTACT'S NAME: ");
    got(name);
    while(fread(&p, sizeof(p), 1, f) == 1)
    {
        if(strcmp(p.name, name) != 0)
            fwrite(&p, sizeof(p), 1, ft);
        else
            flag = 1;
    }
    fclose(f);
    fclose(ft);
    if(flag != 1)
    {
        printf("NO CONTACT'S RECORD TO DELETE.");
        remove("temp");
    }
    else
    {
        remove("project");
        rename("temp", "project");
        printf("RECORD DELETED SUCCESSFULLY.");
    }
    printf("\nEnter any key");
    getch();
    system("cls");
    menu();
}

void modifyrecord()
{
    FILE *f;
    int flag = 0;
    struct person p, s;
    char name[50];

    f = fopen("project", "rb+");
    if(f == NULL)
    {
        printf("CONTACT'S DATA NOT ADDED YET.");
        printf("\nEnter any key");
        getch();
        system("cls");
        menu();
        return;
    }
    system("cls");
    printf("\nEnter CONTACT'S NAME TO MODIFY: ");
    got(name);
    while(fread(&p, sizeof(p), 1, f) == 1)
    {
        if(strcmp(name, p.name) == 0)
        {
            printf("\nEnter name: ");
            got(s.name);
            printf("\nEnter the address: ");
            got(s.address);
            printf("\nEnter father name: ");
            got(s.father_name);
            printf("\nEnter mother name: ");
            got(s.mother_name);
            printf("\nEnter phone no: ");
            scanf("%ld", &s.mble_no);
            int ch; while((ch = getchar()) != '\n' && ch != EOF);
            printf("\nEnter sex: ");
            got(s.sex);
            printf("\nEnter e-mail: ");
            got(s.mail);
            printf("\nEnter citizen no: ");
            got(s.citision_no);
            fseek(f, -(long)sizeof(p), SEEK_CUR);
            fwrite(&s, sizeof(p), 1, f);
            flag = 1;
            break;
        }
    }
    if(flag == 1)
        printf("\nRecord modified successfully.");
    else
        printf("\nRecord not found.");
    fclose(f);
    printf("\nEnter any key");
    getch();
    system("cls");
    menu();
}

void got(char *name)
{
    int i = 0, j;
    char c, ch;
    do
    {
        c = getch();
        if(c != 8 && c != 13)
        {
            *(name + i) = c;
            putch(c);
            i++;
        }
        if(c == 8)
        {
            if(i > 0)
            {
                i--;
                printf("\b \b");
            }
        }
    } while(c != 13);
    *(name + i) = '\0';
}
