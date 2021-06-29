#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>


COORD coord = {0,0};
void gotoxy(int x,int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

int i,j;
int main_exit;
void menu();

struct date
{
  int day,month,year;
};

struct employ
{
    int id_no;
    char name[40];
    int age;
    char dept[20];
    char address[20];
    double salary;
    struct date doj;
}add,check,upd,rem;

void line()
{
    int i;
    for(i=1;i<81;i++)
    {
        gotoxy(19+i,2); printf("%c",205);
    }
}
void console(int x1,int y1,int x2,int y2);
void console(int x1,int y1,int x2,int y2)
{
    int i;
    gotoxy(x1,y1); printf("%c",201);
    for(i=x1+1;i<x2;i++)
    {
        printf("%c",205);
    }
    printf("%c",187);
    for(i=y1+1;i<y2;i++)
    {
        gotoxy(x1,i); printf("%c",186);
        gotoxy(x2,i); printf("%c",186);
    }
    gotoxy(x1,y2); printf("%c",200);

    for(i=x1+1;i<x2;i++)
    {
        printf("%c",196);
    }
    printf("%c",188);
}
void line1(void)
{
    int i;
    gotoxy(1,2); printf("%c",201);
    for(i=2;i<100;i++)
    {
        gotoxy(i,2);printf("%c",205);
    } printf("%c",187);

}

void line2(void)
{
    int i;
    for(i=2;i<100;i++)
    {
        gotoxy(i,4);printf("%c",196);
    }

}



int main()
{

    FILE *view;
    view=fopen("employee.dat","r");
    int test=0;
    console(1,0,100,1);
    system("color 7");

    gotoxy(40,1);printf(">>> RECORD  LIST <<<");
    console(1,4,100,6);
    gotoxy(8,5);printf("ID"); gotoxy(16,5);printf("NAME"); gotoxy(28,5);printf("AGE"); gotoxy(38,5);printf("DEPARTMENT"); gotoxy(56,5);printf("SALARY"); gotoxy(72,5);printf("ADDRESS"); gotoxy(87,5);printf("DATE OF JOIN");
    printf("\n");

    while(fscanf(view,"%d %d/%d/%d %s %d %s %lf %s\n",&add.id_no,&add.doj.day,&add.doj.month,&add.doj.year,add.name,&add.age,add.dept,&add.salary,add.address)!=EOF)
    {

        printf("\n     %4d.\t%-12s%-5d\t%-10s\t%-7.lf\t\t%-8s\t%d/%d/%d\n", add.id_no, add.name, add.age,add.dept,add.salary,add.address,add.doj.day,add.doj.month,add.doj.year);
        test++;
        console(1,6,100,7+test++);
    }
    fclose(view);
    getche();
    if(test==5)
    {
        system("cls");
        printf("\nNO RECORDS TO SHOW !!\n");
    }
}
