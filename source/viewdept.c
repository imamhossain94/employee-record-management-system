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
    int test=0;
    system("color 7");
    console(19,0,100,25);
    for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
    gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
    gotoxy(45,1); printf(" %c%c%c%c     SEARCH RECORD     %c%c%c%c ",206,206,206,206,206,206,206,206);
    for(i=1;i<81;i++){ gotoxy(19+i,18); printf("%c",196); }

    FILE *find;
    find=fopen("employee.dat","r");
    gotoxy(20,3);printf("> Department ist:");
    gotoxy(38,3);
    while(fscanf(find,"%d %d/%d/%d %s %d %s %lf %s\n",&add.id_no,&add.doj.day,&add.doj.month,&add.doj.year,add.name,&add.age,add.dept,&add.salary,add.address)!=EOF)
    {
        printf("%s-", add.dept);
        test++;
    }fclose(find);

    FILE *view;
    view=fopen("employee.dat","r");
    gotoxy(20,17);printf("> Enter department Name:");gotoxy(45,17);scanf("%s",&check.dept);
    printf("\n\n");

    system("cls");
    console(1,0,100,1); gotoxy(40,1);printf(">>> RECORD  LIST <<<");
    for(i=1;i<100;i++){ gotoxy(1+i,6); printf("%c",196); }
    gotoxy(1,3);printf(" Searching for the Department:"); gotoxy(31,3);printf("%s",check.dept);
    gotoxy(8,5);printf("ID"); gotoxy(16,5);printf("NAME"); gotoxy(28,5);printf("AGE"); gotoxy(38,5);printf("DEPARTMENT"); gotoxy(56,5);printf("SALARY"); gotoxy(72,5);printf("ADDRESS"); gotoxy(87,5);printf("DATE OF JOIN");
    printf("\n");
    while(fscanf(view,"%d %d/%d/%d %s %d %s %lf %s\n",&add.id_no,&add.doj.day,&add.doj.month,&add.doj.year,add.name,&add.age,add.dept,&add.salary,add.address)!=EOF)
    {
        if(strcmpi(add.dept,check.dept)==0)
            {
               printf("\n     %4d.\t%-12s%-5d\t%-10s\t%-7.lf\t\t%-8s\t%d/%d/%d\n", add.id_no, add.name, add.age,add.dept,add.salary,add.address,add.doj.day,add.doj.month,add.doj.year);
               test++;

            }
    }
    fclose(view);
    getche();
}
