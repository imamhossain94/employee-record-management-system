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
{
    int i,k;
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
    char newname[40];
    int age;
    char dept[20];
    char newdept[20];
    char address[20];
    char newaddress[20];
    double salary,newsalary;
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
        printf("%c",205);
    }
    printf("%c",188);
}

void login ()
{
    system("cls");
    int i=0;
    char uname[10],username[10]="bubt";
    char pass[10],password[10]="1234";

    console(19,0,100,25);
    for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
    gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
    gotoxy(45,1); printf(" %c%c%c%c        ADMIN        %c%c%c%c ",206,206,206,206,206,206,206,206);

    for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}

    console(45,8,75,10);
    char d[9]=" USERNAME"; int k; gotoxy(45,7); for(k=0;k<9;k++){; printf("%c",d[k]); }
    gotoxy(46,9);scanf("%s",&uname);

    console(45,13,75,15);
    char e[9]=" PASSWORD"; int l; gotoxy(45,12); for(l=0;l<9;l++){; printf("%c",e[l]); }
    gotoxy(46,14);scanf("%s",pass);

    if ((strcmp(pass,password)==0)&&(strcmp(uname,username)==0))
    {
        char f[11]="LOGING IN.."; int m; gotoxy(55,24); for(m=0;m<11;m++){; printf("%c",f[m]); Sleep(3); }
        int j=1;while(j!=7) {for(i=1;i<6;i++){ gotoxy(63+i,24); printf("."); Sleep(100);}j++;} system("cls");
    }
    else
        {
            char g[28]=" WRONG USERNAME OR PASSWORD"; int n; gotoxy(47,24); for(n=0;n<28;n++){; printf("%c",g[n]); Sleep(50); }

            login_try:
            gotoxy(20,24); printf(" ENTER '1' TO TRY AGAIN:                                       ");
            gotoxy(45,24);scanf("%d",&main_exit);
            if (main_exit==1)
                    {
                        system("cls");
                        login();
                    }
            else
                    {
                    gotoxy(70,23); printf("Invalid! Selection");
                    fordelay(100000000);
                     for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
                    goto login_try;
                    }

        }
}

void login_choice()
{
    system("cls");
    char choice;
    console(19,0,100,25);
    for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
    gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
    gotoxy(45,1); printf(" %c%c%c%c        LOGIN        %c%c%c%c ",206,206,206,206,206,206,206,206);

    console(33,11,47,13); console(73,11,87,13);
    for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
    gotoxy(20,24); printf("ENTER '1' FOR ADMIN '2' FOR EMPLOYEE: ");
    gotoxy(34,12); printf("    ADMIN "); gotoxy(74,12); printf("   EMPLOYEE");
    login_choice:
    gotoxy(58,24);choice  = getche();
		switch(choice)
		{
	 	    case '1' : login();  admin_menu();
			break;
			case '2' :EmpMENU();
			break;
			default : gotoxy(70,23); printf("Invalid! Selection");
                            gotoxy(58,24); printf(" ");
                            fordelay(100000000);
                            for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
                            goto login_choice;
		}

}

void new_acc()
{
    system("cls");
    int choice,p;
    int test=0;
    system("color 7");
    console(19,0,100,25);
    for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
    gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
    gotoxy(45,1); printf(" %c%c%c%c     ADD RECORD     %c%c%c%c ",206,206,206,206,206,206,206,206);
    gotoxy(20,3);printf("ID list:");
    for(i=1;i<81;i++){ gotoxy(19+i,4); printf("%c",196); }
    for(i=1;i<81;i++){ gotoxy(19+i,20); printf("%c",196); }
    for(i=1;i<81;i++){ gotoxy(19+i,21); printf(" "); }

    FILE *view;
    view=fopen("employee.dat","r");
    gotoxy(29,3);
    while(fscanf(view,"%d %d/%d/%d %s %d %s %lf %s\n",&add.id_no,&add.doj.day,&add.doj.month,&add.doj.year,add.name,&add.age,add.dept,&add.salary,add.address)!=EOF)
    {
        if(test<=12)
        {
        printf("%d-", add.id_no);
        test++;
        }
    }fclose(view);gotoxy(99,3); printf(" ");


    FILE *ptr;
    ptr=fopen("employee.dat","a+");
    gotoxy(20,6);printf("> Enter ID:");
    gotoxy(32,6);scanf("%d",&check.id_no);
    while(fscanf(ptr," %d %d/%d/%d %s %d %s %lf %s\n",&add.id_no,&add.doj.day,&add.doj.month,&add.doj.year,add.name,&add.age,add.dept,&add.salary,add.address)!=EOF)
    {
        if(check.id_no==add.id_no)
        {
            gotoxy(45,20);printf(">> This ID No. already taken! <<");
            gotoxy(32,6); printf(" ");
            fordelay(100000000);
            new_acc();
        }
    }
    add.id_no=check.id_no;
    gotoxy(20,8);printf("> Enter joining date(dd/mm/yyyy)    :");
    gotoxy(59,8);scanf("%d/%d/%d",&add.doj.day,&add.doj.month,&add.doj.year);
    gotoxy(20,10);printf("> Enter the name                    :");
    gotoxy(59,10);scanf("%s",add.name);
    gotoxy(20,12);printf("> Enter the age                     :");
    gotoxy(59,12);scanf("%d",&add.age);
    gotoxy(20,14);printf("> Enter department name             :");
    gotoxy(59,14);scanf("%s",add.dept);
    gotoxy(20,16);printf("> Enter the salary                  :  BDT- ");
    gotoxy(63,16);scanf("%lf",&add.salary);
    gotoxy(20,18);printf("> Enter the address                 :");
    gotoxy(59,18);scanf("%s",add.address);
    fprintf(ptr,"%d %d/%d/%d %s %d %s %.2lf %s\n",add.id_no,add.doj.day,add.doj.month,add.doj.year,add.name,add.age,add.dept,add.salary,add.address);
    fclose(ptr);
    gotoxy(58,20);printf(">> Employee record added successfully! <<");

    add_invalid:
            gotoxy(20,21);printf("> 0 [add another account]");
            gotoxy(20,22);printf("> 1 [main menu]");
            gotoxy(20,23);printf("> 2 [view records]");
            gotoxy(50,24);printf(">Enter your choice: ");
            gotoxy(69,24);scanf("%d",&main_exit);
            if (main_exit==1)
                admin_menu();
            else if (main_exit==2){
                system("start view/view.exe");goto add_invalid;}
            else if(main_exit==0)
                new_acc();
            else
                {
                    gotoxy(60,25);printf("Invalid!\a");
                    goto add_invalid;
                }
}

void erase(void)
{
    system("cls");
    FILE *view;
    view=fopen("employee.dat","r");
    FILE *old,*newrac;
    old=fopen("employee.dat","r");
    newrac=fopen("new.dat","w");
    int test=0;
    system("color 7");
    console(19,0,100,25);
    for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
    gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
    gotoxy(45,1); printf(" %c%c%c%c     REMOVE RECORD     %c%c%c%c ",206,206,206,206,206,206,206,206);
    gotoxy(20,3);printf("ID list:");
    for(i=1;i<81;i++){ gotoxy(19+i,4); printf("%c",196); }
    for(i=1;i<81;i++){ gotoxy(19+i,19); printf("%c",196); }

    gotoxy(29,3);
    while(fscanf(view,"%d %d/%d/%d %s %d %s %lf %s\n",&add.id_no,&add.doj.day,&add.doj.month,&add.doj.year,add.name,&add.age,add.dept,&add.salary,add.address)!=EOF)
    {
        printf("%d-", add.id_no);
        test++;
    }fclose(view);

    gotoxy(20,5);printf("> Enter ID NO. to remove:");
    gotoxy(47,5);scanf("%d",&rem.id_no);


    FILE *ptr; ptr=fopen("employee.dat","r");
    while(fscanf(ptr," %d %d/%d/%d %s %d %s %lf %s\n",&add.id_no,&add.doj.day,&add.doj.month,&add.doj.year,add.name,&add.age,add.dept,&add.salary,add.address)!=EOF)
        {
            if(add.id_no==rem.id_no)
            {
                test=1;
                gotoxy(20,9);printf("> 1.ID:%d",add.id_no);
                gotoxy(20,10);printf("> 2.Name:%s " ,add.name);
                gotoxy(20,11);printf("> 3.Age:%d",add.age);
                gotoxy(20,12);printf("> 4.Department:%s",add.dept);
                gotoxy(20,13);printf("> 5.Salary:%lf",add.salary);
                gotoxy(20,14);printf("> 6.Address:%s",add.address);
                gotoxy(20,15);printf("> 7.Date of join:%d/%d/%d",add.doj.day,add.doj.month,add.doj.year);
                fordelay(10000000);
                gotoxy(85,18);printf("Removing.");
                int j=1;while(j!=5) {for(i=1;i<5;i++){ gotoxy(92+i,18); printf("."); Sleep(200);}j++;}
                for(i=1;i<81;i++){ gotoxy(19+i,9); printf(" "); }
                for(i=1;i<81;i++){ gotoxy(19+i,10); printf(" "); }
                for(i=1;i<81;i++){ gotoxy(19+i,11); printf(" "); }
                for(i=1;i<81;i++){ gotoxy(19+i,12); printf(" "); }
                for(i=1;i<81;i++){ gotoxy(19+i,13); printf(" "); }
                for(i=1;i<81;i++){ gotoxy(19+i,14); printf(" "); }
                for(i=1;i<81;i++){ gotoxy(19+i,15); printf(" "); }
                gotoxy(85,18);printf("              "); gotoxy(90,18);printf("Removed!!");
                char f[7]=" EMPTY "; int m; gotoxy(55,12); for(m=0;m<7;m++){; printf("%c",f[m]); Sleep(10); }
            }
        }fclose(ptr);
    while(fscanf(old,"%d %d/%d/%d %s %d %s %lf %s\n",&add.id_no,&add.doj.day,&add.doj.month,&add.doj.year,add.name,&add.age,add.dept,&add.salary,add.address)!=EOF)
    {
        if(add.id_no!=rem.id_no)
        {
            fprintf(newrac,"%d %d/%d/%d %s %d %s %.2lf %s\n",add.id_no,add.doj.day,add.doj.month,add.doj.year,add.name,add.age,add.dept,add.salary,add.address);
        }
            else
          {
            test++;
            gotoxy(45,19);printf("> Record deleted successfully!\n");
          }
    }
    fclose(old);
    fclose(newrac);
    remove("employee.dat");
    rename("new.dat","employee.dat");
    if(test==0)
    {

        gotoxy(20,6);printf("> Record not found\a\a\a");

        erase_invalid:
        gotoxy(20,21); for(i=1; i<81; i++) {  printf(" "); }
            gotoxy(20,21);printf("> 0 [try again]");
            gotoxy(20,22);printf("> 1 [main menu]");
            gotoxy(20,23);printf("> 2 [view records]");
            gotoxy(50,24);printf(">Enter your choice: ");
            gotoxy(69,24);scanf("%d",&main_exit);
            if (main_exit==1)
                admin_menu();
            else if (main_exit==2){
                system("start view/view.exe");goto erase_invalid;}
            else if(main_exit==0)
                erase();
            else
                {
                    gotoxy(50,25);printf("Invalid!\a");
                    goto erase_invalid;
                }
        }
    else
        {
            gotoxy(20,21);printf(">0 [Remove another Record]");
            gotoxy(20,22);printf("> 1 [main menu]");
            gotoxy(20,23);printf("> 2 [view records]");
            gotoxy(50,24);printf(">Enter your choice: ");
            gotoxy(69,24);scanf("%d",&main_exit);
            if (main_exit==1)
                admin_menu();
            else if (main_exit==2){
                system("start view/view.exe");goto erase_invalid;}
            else if(main_exit==0)
                erase();
            else
                {
                    gotoxy(50,25);printf("Invalid!\a");
                    goto erase_invalid;
                }
        }
    }

void edit(void)
{
    system("cls");
    int choice,test=0;
    system("color 7");
    console(19,0,100,25);
    for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
    gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
    gotoxy(45,1); printf(" %c%c%c%c     EDIT RECORD     %c%c%c%c ",206,206,206,206,206,206,206,206);
    gotoxy(20,3);printf("ID list:");
    for(i=1;i<81;i++){ gotoxy(19+i,4); printf("%c",196); }
    for(i=1;i<81;i++){ gotoxy(19+i,16); printf("%c",196); }
    gotoxy(20,18); for(i=1; i<81; i++) {  printf("%c",205); }

    FILE *view;
    view=fopen("employee.dat","r");
    gotoxy(29,3);
    while(fscanf(view,"%d %d/%d/%d %s %d %s %lf %s\n",&add.id_no,&add.doj.day,&add.doj.month,&add.doj.year,add.name,&add.age,add.dept,&add.salary,add.address)!=EOF)
    {
        printf("%d-", add.id_no);
        test++;
    } fclose(view);


    FILE*old,*newrec;
    old=fopen("employee.dat","r");
    newrec=fopen("new.dat","w");

    gotoxy(20,5);printf(">Enter ID: ");
    gotoxy(30,5);scanf("%d",&upd.id_no);
    while(fscanf(old,"%d %d/%d/%d %s %d %s %lf %s\n",&add.id_no,&add.doj.day,&add.doj.month,&add.doj.year,add.name,&add.age,add.dept,&add.salary,add.address)!=EOF)
    {
        if(add.id_no==upd.id_no)
        {
            test=1;
            gotoxy(20,17);printf("> Enter choice:");
            gotoxy(22,8);printf("1.Name");
            gotoxy(22,9);printf("2.Age");
            gotoxy(22,10);printf("3.Department");
            gotoxy(22,11);printf("4.Salary");
            gotoxy(22,12);printf("5.Address");
            gotoxy(20,15);printf("6.Full Edit");
            gotoxy(50,15);printf("7.Not this Edit another");
            gotoxy(87,15);printf("8.Main menu");


            gotoxy(37,8);printf("::> %s ",add.name);
            gotoxy(37,9);printf("::> %d",add.age);
            gotoxy(37,10);printf("::> %s",add.dept);
            gotoxy(37,11);printf("::> BDT-%.0lf",add.salary);
            gotoxy(37,12);printf("::> %s",add.address);

            gotoxy(36,17);scanf("%d",&choice);

            if(choice==1)
            {
                gotoxy(20,17); for(i=1; i<81; i++) {  printf(" "); }
                gotoxy(20,17);printf("> Enter name            :");
                gotoxy(45,17);scanf("%s",upd.name);
                fprintf(newrec,"%d %d/%d/%d %s %d %s %lf %s\n",add.id_no,add.doj.day,add.doj.month,add.doj.year,upd.name,add.age,add.dept,add.salary,add.address);
                gotoxy(83,17);printf(">change saved!!");
            }
            else if(choice==2)
            {
                gotoxy(20,17); for(i=1; i<81; i++) {  printf(" "); }
                gotoxy(20,17);printf("> Enter age             :");
                gotoxy(45,17);scanf("%d",&upd.age);
                fprintf(newrec,"%d %d/%d/%d %s %d %s %lf %s\n",add.id_no,add.doj.day,add.doj.month,add.doj.year,add.name,upd.age,add.dept,add.salary,add.address);
                gotoxy(85,17);printf(">change saved!!");
            }

            else if(choice==3)
            {
                gotoxy(20,17); for(i=1; i<81; i++) {  printf(" "); }
                gotoxy(20,17);printf("> Enter department      :");
                gotoxy(45,17);scanf("%s",upd.dept);
                fprintf(newrec,"%d %d/%d/%d %s %d %s %lf %s\n",add.id_no,add.doj.day,add.doj.month,add.doj.year,add.name,add.age,upd.dept,add.salary,add.address);
                gotoxy(85,17);printf(">change saved!!");
            }
            else if(choice==4)
            {
                gotoxy(20,17); for(i=1; i<81; i++) {  printf(" "); }
                gotoxy(20,17);printf("> Enter salary          :BDT-");
                gotoxy(49,17);scanf("%lf",&upd.salary);
                fprintf(newrec,"%d %d/%d/%d %s %d %s %lf %s\n",add.id_no,add.doj.day,add.doj.month,add.doj.year,add.name,add.age,add.dept,upd.salary,add.address);
                gotoxy(85,17);printf(">change saved!!");
            }
            else if(choice==5)
            {
                gotoxy(20,17); for(i=1; i<81; i++) {  printf(" "); }
                gotoxy(20,17);printf("> Enter address        :");
                gotoxy(45,17);scanf("%s",upd.address);
                fprintf(newrec,"%d %d/%d/%d %s %d %s %lf %s\n",add.id_no,add.doj.day,add.doj.month,add.doj.year,add.name,add.age,add.dept,add.salary,upd.address);
                gotoxy(85,17);printf(">change saved!!");
            }
            else if(choice==6)
            {
                gotoxy(45,15); for(i=1; i<56; i++) {  printf(" "); }
                gotoxy(20,17); for(i=1; i<81; i++) {  printf(" "); }
                console(21,7,58,13);
                console(61,7,98,13);
                gotoxy(62,8);printf("> Enter name        ::> ");
                gotoxy(86,8);scanf("%s",upd.name);
                gotoxy(62,9);printf("> Enter age         ::> ");
                gotoxy(86,9);scanf("%d",&upd.age);
                gotoxy(62,10);printf("> Enter department  ::> ");
                gotoxy(86,10);scanf("%s",upd.dept);
                gotoxy(62,11);printf("> Enter salary      ::> BDT- ");
                gotoxy(90,11);scanf("%lf",&upd.salary);
                gotoxy(62,12);printf("> Enter address     ::> ");
                gotoxy(86,12);scanf("%s",upd.address);

                char f[16]="SAVING CHANGED.."; int m; gotoxy(20,17); for(m=0;m<16;m++){; printf("%c",f[m]); Sleep(3); }
                int j=1;while(j!=5) {for(i=1;i<6;i++){ gotoxy(35+i,17); printf("."); Sleep(100);}j++;}
                gotoxy(20,17); for(i=1; i<81; i++) {  printf(" "); }
                fprintf(newrec,"%d %d/%d/%d %s %d %s %lf %s\n",add.id_no,add.doj.day,add.doj.month,add.doj.year,upd.name,upd.age,upd.dept,upd.salary,upd.address);
                gotoxy(85,17);printf(">change saved!!");

            }
            else if(choice==7)
            {
                edit();
            }
            else if(choice==8)
            {
                admin_menu();
            }
        }
            else
                fprintf(newrec,"%d %d/%d/%d %s %d %s %lf %s\n",add.id_no,add.doj.day,add.doj.month,add.doj.year,add.name,add.age,add.dept,add.salary,add.address);

        }
        fclose(old);
        fclose(newrec);
        remove("employee.dat");
        rename("new.dat","employee.dat");


       if(test!=1)
        {
            gotoxy(45,18);printf(">> Record not found!! <<\a\a\a");
            edit_invalid:
            gotoxy(20,20); for(i=1; i<81; i++) {  printf(" "); }
            gotoxy(20,20);printf("> 0 [Try again]");
            gotoxy(20,21);printf("> 1 [main menu]");
            gotoxy(20,22);printf("> 2 [view records]");
            gotoxy(50,24);printf(">Enter your choice: ");
            gotoxy(69,24);scanf("%d",&main_exit);
            if (main_exit==1)
                admin_menu();
            else if (main_exit==2){
                system("start view/view.exe");goto edit_invalid;}
            else if(main_exit==0)
                edit();
            else
                {
                    gotoxy(50,25);printf("Invalid!\a");
                    goto edit_invalid;
                }
        }
    else
        {
            gotoxy(20,20);printf("> 0 [Edit another Record]");
            gotoxy(20,21);printf("> 1 [main menu]");
            gotoxy(20,22);printf("> 2 [view records]");
            gotoxy(50,24);printf(">Enter your choice: ");
            gotoxy(69,24);scanf("%d",&main_exit);
            if (main_exit==1)
                admin_menu();
            else if (main_exit==2){
                system("start view/view.exe");goto edit_invalid;}
            else if(main_exit==0)
                edit();
            else
                {
                    gotoxy(50,25);printf("Invalid!\a");
                    goto edit_invalid;
                }
        }
}

void search(void)
{
    FILE *ptr;
    ptr=fopen("employee.dat","r");

    int test=0,choice;
    system("cls");

    console(19,0,100,25);
    for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
    gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
    gotoxy(45,1); printf(" %c%c%c%c     SEARCH RECORD     %c%c%c%c ",206,206,206,206,206,206,206,206);
    gotoxy(20,3);printf("Search By:");
    gotoxy(20,7);printf("> 1. ID");
    gotoxy(20,11);printf("> 2. Name");
    gotoxy(20,15);printf("> 3. Department");
    for(i=1;i<81;i++){ gotoxy(19+i,4); printf("%c",196); }
    for(i=1;i<81;i++){ gotoxy(19+i,18); printf("%c",196); }
    gotoxy(31,3);scanf("%d",&choice);

    if(choice==1)
    {
        gotoxy(20,7);printf("                                               ");
        gotoxy(20,11);printf("                                               ");
        gotoxy(20,15);printf("                                               ");
        char f[39]="Floating windows opening Please wait "; int m; gotoxy(20,11); for(m=0;m<39;m++){; printf("%c",f[m]); Sleep(5); }
        fordelay(100000000);system("start view/viewid");
    }
    else if(choice==2)
    {
        gotoxy(20,7);printf("                                               ");
        gotoxy(20,11);printf("                                               ");
        gotoxy(20,15);printf("                                               ");
        char f[39]="Floating windows opening Please wait "; int m; gotoxy(20,11); for(m=0;m<39;m++){; printf("%c",f[m]); Sleep(5); }
        fordelay(100000000);system("start view/viewname");
    }
    else if(choice==3)
    {
         gotoxy(20,7);printf("                                               ");
        gotoxy(20,11);printf("                                               ");
        gotoxy(20,15);printf("                                               ");
        char f[39]="Floating windows opening Please wait "; int m; gotoxy(20,11); for(m=0;m<39;m++){; printf("%c",f[m]); Sleep(5); }
        fordelay(100000000);system("start view/viewdept");
    }

    fclose(ptr);
      if(test!=1)
        {
            search_invalid:
            gotoxy(20,20);printf("> 0 [Search another Record]");
            gotoxy(20,21);printf("> 1 [main menu]");
            gotoxy(20,22);printf("> 2 [view Records]");
            gotoxy(50,24);printf(">Enter your choice: ");
            gotoxy(69,24);scanf("%d",&main_exit);
            if (main_exit==1)
                admin_menu();
            else if (main_exit==2){
                system("start view/view.exe");goto search_invalid;}
            else if(main_exit==0)
                search();
            else
                {
                    gotoxy(50,25);printf("Invalid!\a");
                    goto search_invalid;
                }
        }
}

void EmpREQ()
{

    int i=0,ch;
    Req:
    console(19,0,100,25);
    for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
    gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
    gotoxy(40,1); printf(" %c%c%c%c        EMPLOYER REQUEST        %c%c%c%c ",206,206,206,206,206,206,206,206);
    for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}

    gotoxy(20,5); printf("# VIEW");
    gotoxy(20,7); printf("> 1. View Name change Request .");
    gotoxy(20,8); printf("> 2. View Department change Request.");
    gotoxy(20,9); printf("> 3. View Address change Request.");
    gotoxy(20,10); printf("> 4. View Request To increase salary.");
    gotoxy(20,14); printf("# DELETE");
    gotoxy(20,16); printf("> 5. Delete Name change Request .");
    gotoxy(20,17); printf("> 6. Delete Department change Request.");
    gotoxy(20,18); printf("> 7. Delete Address change Request.");
    gotoxy(20,19); printf("> 8. Delete Request of increase salary.");
    gotoxy(20,20); printf("> 9. Delete All Request");
    gotoxy(20,22);printf("> 0.Main Menu");
    gotoxy(20,24);printf("> Enter choice:");
    scanf("%d",&ch);

    if(ch==1)
    {
    system("cls");
    console(19,0,100,25);
    for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
    gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
    gotoxy(40,1); printf(" %c%c%c%c        NAME REQ        %c%c%c%c ",206,206,206,206,206,206,206,206);
    for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}

    FILE *Rname;
    Rname=fopen("file/NRequest.dat","a+");
    gotoxy(20,2);
    while(fscanf(Rname,"%d %s %s \n",&add.id_no,&add.name,&add.newname)!=EOF)
    {
       printf("\n\t\t\t\tID: %d \tOld Name: %s \tRequested: %s\n", add.id_no,add.name,add.newname);
        i++;
    }fclose(Rname);


    Retry:
            gotoxy(20,24); printf("> 1 [Edit]    > 2 [Employee Request]    > 3 [Main Menu]    > Enter choice:");
            gotoxy(94,24);scanf("%d",&main_exit);
            if (main_exit==1)
            {

                // Edit
    system("cls");
    int choice,test=0;
    system("color 7");
    console(19,0,100,25);
    for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
    gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
    gotoxy(45,1); printf(" %c%c%c%c     EDIT RECORD     %c%c%c%c ",206,206,206,206,206,206,206,206);
    gotoxy(20,3);printf("ID list:");
    for(i=1;i<81;i++){ gotoxy(19+i,4); printf("%c",196); }
    for(i=1;i<81;i++){ gotoxy(19+i,21); printf("%c",196); }
    gotoxy(20,23); for(i=1; i<81; i++) {  printf("%c",205); }


    FILE *Rname2;
    Rname2=fopen("file/NRequest.dat","r");
    gotoxy(29,3);
    while(fscanf(Rname2,"%d %s %s \n",&add.id_no,&add.name,&add.newname)!=EOF)
    {
       printf("%d-", add.id_no);
        i++;
    }fclose(Rname2);

    gotoxy(20,5);printf(">Enter ID: ");
    gotoxy(30,5);scanf("%d",&upd.id_no);

    FILE *Rname3;
    Rname3=fopen("file/NRequest.dat","r");

    while(fscanf(Rname3,"%d %s %s \n",&add.id_no,&add.name,&add.newname)!=EOF)
    {
       if(add.id_no==upd.id_no)
       {
           i=1;
           fscanf(Rname3,"%s",upd.newname);
           console(45,5,75,7); gotoxy(46,4); printf("Old Name"); gotoxy(46,6); printf("%s ",add.name);
            console(45,10,75,12); gotoxy(46,9);printf("New Name "); gotoxy(46,11); printf("%s",add.newname);
            console(45,15,75,17); gotoxy(46,14);printf("Enter Name ");
       }
    }fclose(Rname3);

    FILE*old,*newrec;
    old=fopen("employee.dat","r");
    newrec=fopen("new.dat","w");
    while(fscanf(old,"%d %d/%d/%d %s %d %s %lf %s\n",&add.id_no,&add.doj.day,&add.doj.month,&add.doj.year,add.name,&add.age,add.dept,&add.salary,add.address)!=EOF)
    {
        if(add.id_no==upd.id_no)
        {
            i=1;
            gotoxy(46,16);scanf("%s",upd.name);
            fprintf(newrec,"%d %d/%d/%d %s %d %s %lf %s\n",add.id_no,add.doj.day,add.doj.month,add.doj.year,upd.name,add.age,add.dept,add.salary,add.address);
        }
        else
        fprintf(newrec,"%d %d/%d/%d %s %d %s %lf %s\n",add.id_no,add.doj.day,add.doj.month,add.doj.year,add.name,add.age,add.dept,add.salary,add.address);
    }
    if(i!=1)
    {
        gotoxy(20,22); printf(" Record not found!!");
        goto Name_try;
    }
        fclose(old);
        fclose(newrec);
        remove("employee.dat");
        rename("new.dat","employee.dat");

    char f[9]="SAVEING.."; int m; gotoxy(20,22); for(m=0;m<9;m++){; printf("%c",f[m]); Sleep(3); }
    int j=1;while(j!=5) {for(i=1;i<6;i++){ gotoxy(29+i,22); printf("."); Sleep(100);}j++;}
    gotoxy(20,22); for(i=1; i<81; i++) {  printf(" "); } gotoxy(20,22);printf(">change saved!!");


        Name_try:
            gotoxy(20,24); printf("> 1 [Employee Req]:   ");
            gotoxy(41,24);scanf("%d",&main_exit);
            if (main_exit==1)
                    {
                        system("cls");
                        EmpREQ();
                    }
            else
                    {
                    gotoxy(70,23); printf("Invalid! Selection");
                    fordelay(100000000);
                     for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
                    goto Name_try;
                    }
        }



            else if (main_exit==2)
            {
                system("cls"); EmpREQ();
            }
            else if (main_exit==3)
            {
                admin_menu();
            }
            else
                    {
                    gotoxy(70,23); printf("Invalid! Selection");
                    fordelay(100000000);
                     for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
                    goto Retry;
                    }

    }

    if(ch==2)
    {
    system("cls");
    console(19,0,100,25);
    for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
    gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
    gotoxy(40,1); printf(" %c%c%c%c        DEPT REQ        %c%c%c%c ",206,206,206,206,206,206,206,206);
    for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}

    FILE *Dname;
    Dname=fopen("file/DRequest.dat","a+");
    gotoxy(20,2);
    while(fscanf(Dname,"%d %s %s \n",&add.id_no,&add.dept,&add.newdept)!=EOF)
    {
        printf("\n\t\t\t\tID: %d \tOld Dept: %s \tRequested: %s\n", add.id_no,add.dept,add.newdept);
        i++;

    }

    Setry:
            gotoxy(20,24); printf("> 1 [Edit]    > 2 [Employee Request]    > 3 [Main Menu]    > Enter choice:");
            gotoxy(94,24);scanf("%d",&main_exit);
            if (main_exit==1)
            {
                system("cls");
                int choice,test=0;
                system("color 7");
                console(19,0,100,25);
                for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
                gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
                gotoxy(45,1); printf(" %c%c%c%c     EDIT RECORD     %c%c%c%c ",206,206,206,206,206,206,206,206);
                gotoxy(20,3);printf("ID list:");
                for(i=1;i<81;i++){ gotoxy(19+i,4); printf("%c",196); }
                for(i=1;i<81;i++){ gotoxy(19+i,21); printf("%c",196); }
                gotoxy(20,23); for(i=1; i<81; i++) {  printf("%c",205); }




                FILE *Dname2;
                Dname2=fopen("file/DRequest.dat","r");
                gotoxy(29,3);
                while(fscanf(Dname2,"%d %s %s \n",&add.id_no,&add.dept,&add.newdept)!=EOF)
                {
                    printf("%d-", add.id_no);
                    i++;
                }fclose(Dname2);

                gotoxy(20,5);printf(">Enter ID: ");
                gotoxy(30,5);scanf("%d",&upd.id_no);

                FILE *Dname3;
                Dname3=fopen("file/DRequest.dat","r");




                 while(fscanf(Dname3,"%d %s %s \n",&add.id_no,&add.dept,&add.newdept)!=EOF)
                {
                if(add.id_no==upd.id_no)
                {
                    i=1;
                    fscanf(Dname3,"%s",upd.newdept);
                    console(45,5,75,7); gotoxy(46,4); printf("Old Dept"); gotoxy(46,6); printf("%s ",add.dept);
                    console(45,10,75,12); gotoxy(46,9);printf("New Dept "); gotoxy(46,11); printf("%s",add.newdept);
                    console(45,15,75,17); gotoxy(46,14);printf("Enter Dept ");
                }
                }fclose(Dname3);

                FILE*old,*newrec;
                old=fopen("employee.dat","r");
                newrec=fopen("new.dat","w");
                while(fscanf(old,"%d %d/%d/%d %s %d %s %lf %s\n",&add.id_no,&add.doj.day,&add.doj.month,&add.doj.year,add.name,&add.age,add.dept,&add.salary,add.address)!=EOF)
                {
                    if(add.id_no==upd.id_no)
                    {
                        i=1;
                        gotoxy(46,16);scanf("%s",upd.dept);
                        fprintf(newrec,"%d %d/%d/%d %s %d %s %lf %s\n",add.id_no,add.doj.day,add.doj.month,add.doj.year,add.name,add.age,upd.dept,add.salary,add.address);
                    }
                    else
                    fprintf(newrec,"%d %d/%d/%d %s %d %s %lf %s\n",add.id_no,add.doj.day,add.doj.month,add.doj.year,add.name,add.age,add.dept,add.salary,add.address);
                }
                if(i!=1)
                {
                    gotoxy(20,22); printf(" Record not found!!");
                    goto Dept_try;
                }
                fclose(old);
                fclose(newrec);
                remove("employee.dat");
                rename("new.dat","employee.dat");

                char f[9]="SAVEING.."; int m; gotoxy(20,22); for(m=0;m<9;m++){; printf("%c",f[m]); Sleep(3); }
                int j=1;while(j!=5) {for(i=1;i<6;i++){ gotoxy(29+i,22); printf("."); Sleep(100);}j++;}
                gotoxy(20,22); for(i=1; i<81; i++) {  printf(" "); } gotoxy(20,22);printf(">change saved!!");

                Dept_try:
                gotoxy(20,24); printf("> 1 [Employee Req]:   ");
                gotoxy(41,24);scanf("%d",&main_exit);
                if (main_exit==1)
                {
                        system("cls");
                        EmpREQ();
                }
                else
                {
                    gotoxy(70,23); printf("Invalid! Selection");
                    fordelay(100000000);
                     for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
                    goto Dept_try;
            }
            }

            else if (main_exit==2)
            {
                system("cls"); EmpREQ();
            }
            else if (main_exit==3)
            {
                admin_menu();
            }
            else
                    {
                    gotoxy(70,23); printf("Invalid! Selection");
                    fordelay(100000000);
                     for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
                    goto Setry;
                    }
    }

    if(ch==3)
    {
    system("cls");
    console(19,0,100,25);
    for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
    gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
    gotoxy(40,1); printf(" %c%c%c%c        ADDRESS REQ        %c%c%c%c ",206,206,206,206,206,206,206,206);
    for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}


    FILE *Aname;
    Aname=fopen("file/ARequest.dat","a+");
    gotoxy(20,2);
    while(fscanf(Aname,"%d %s %s \n",&add.id_no,&add.address,&add.newaddress)!=EOF)
    {
        printf("\n\t\t\t\tID: %d \tOld Address: %s \tRequested: %s\n", add.id_no,add.address,add.newaddress);
        i++;
    }fclose(Aname);

    Aetry:
            gotoxy(20,24); printf("> 1 [Edit]    > 2 [Employee Request]    > 3 [Main Menu]    > Enter choice:");
            gotoxy(94,24);scanf("%d",&main_exit);
            if (main_exit==1)
            {
            system("cls");
            int choice,test=0;
            system("color 7");
            console(19,0,100,25);
            for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
            gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
            gotoxy(45,1); printf(" %c%c%c%c     EDIT RECORD     %c%c%c%c ",206,206,206,206,206,206,206,206);
            gotoxy(20,3);printf("ID list:");
            for(i=1;i<81;i++){ gotoxy(19+i,4); printf("%c",196); }
            for(i=1;i<81;i++){ gotoxy(19+i,21); printf("%c",196); }
            gotoxy(20,23); for(i=1; i<81; i++) {  printf("%c",205); }

            FILE *Aname2;
            Aname2=fopen("file/ARequest.dat","r");
            gotoxy(29,3);
            while(fscanf(Aname2,"%d %s %s \n",&add.id_no,&add.address,&add.newaddress)!=EOF)
            {
                printf("%d-", add.id_no);
                i++;
            }fclose(Aname2);

            gotoxy(20,5);printf(">Enter ID: ");
            gotoxy(30,5);scanf("%d",&upd.id_no);


            FILE *Aname3;
            Aname3=fopen("file/ARequest.dat","r");

            while(fscanf(Aname3,"%d %s %s \n",&add.id_no,&add.address,&add.newaddress)!=EOF)
            {
                if(add.id_no==upd.id_no)
                {
                    i=1;
                    fscanf(Aname3,"%s",upd.newaddress);
                    console(45,5,75,7); gotoxy(46,4); printf("Old Address"); gotoxy(46,6); printf("%s ",add.address);
                    console(45,10,75,12); gotoxy(46,9);printf("New Address "); gotoxy(46,11); printf("%s",add.newaddress);
                    console(45,15,75,17); gotoxy(46,14);printf("Enter Address ");
                }
            }fclose(Aname3);


            FILE*old,*newrec;
            old=fopen("employee.dat","r");
            newrec=fopen("new.dat","w");
            while(fscanf(old,"%d %d/%d/%d %s %d %s %lf %s\n",&add.id_no,&add.doj.day,&add.doj.month,&add.doj.year,add.name,&add.age,add.dept,&add.salary,add.address)!=EOF)
            {
                if(add.id_no==upd.id_no)
                {
                    i=1;
                    gotoxy(46,16);scanf("%s",upd.address);
                    fprintf(newrec,"%d %d/%d/%d %s %d %s %lf %s\n",add.id_no,add.doj.day,add.doj.month,add.doj.year,add.name,add.age,add.dept,add.salary,upd.address);
                }
                else
                fprintf(newrec,"%d %d/%d/%d %s %d %s %lf %s\n",add.id_no,add.doj.day,add.doj.month,add.doj.year,add.name,add.age,add.dept,add.salary,add.address);
            }
            if(i!=1)
            {
                gotoxy(20,22); printf(" Record not founf!!");
                goto Address_try;
            }

            fclose(old);
            fclose(newrec);
            remove("employee.dat");
            rename("new.dat","employee.dat");

            char f[9]="SAVEING.."; int m; gotoxy(20,22); for(m=0;m<9;m++){; printf("%c",f[m]); Sleep(3); }
            int j=1;while(j!=5) {for(i=1;i<6;i++){ gotoxy(29+i,22); printf("."); Sleep(100);}j++;}
            gotoxy(20,22); for(i=1; i<81; i++) {  printf(" "); } gotoxy(20,22);printf(">change saved!!");

            Address_try:
            gotoxy(20,24); printf("> 1 [Employee Req]:   ");
            gotoxy(41,24);scanf("%d",&main_exit);
            if (main_exit==1)
                    {
                        system("cls");
                        EmpREQ();
                    }
            else
                    {
                    gotoxy(70,23); printf("Invalid! Selection");
                    fordelay(100000000);
                     for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
                    goto Address_try;
                    }
            }
            else if (main_exit==2)
            {
                system("cls"); EmpREQ();
            }
            else if (main_exit==3)
            {
                admin_menu();
            }
            else
                    {
                    gotoxy(70,23); printf("Invalid! Selection");
                    fordelay(100000000);
                     for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
                    goto Aetry;
                    }
    }

    if(ch==4)
    {
    system("cls");
    console(19,0,100,25);
    for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
    gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
    gotoxy(40,1); printf(" %c%c%c%c        SALARY REQ        %c%c%c%c ",206,206,206,206,206,206,206,206);
    for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}

    FILE *Sname;
    Sname=fopen("file/SRequest.dat","a+");
    gotoxy(20,2);
    while(fscanf(Sname,"%d %lf %lf \n",&add.id_no,&add.salary,&add.newsalary)!=EOF)
    {
        printf("\n\t\t\t\tID: %d \tOld Salary: %0.lf \tRequested: %0.lf\n", add.id_no,add.salary,add.newsalary);
        i++;

    }


    Saetry:
            gotoxy(20,24); printf("> 1 [Edit]    > 2 [Employee Request]    > 3 [Main Menu]    > Enter choice:");
            gotoxy(94,24);scanf("%d",&main_exit);
            if (main_exit==1)
            {
                system("cls");
                int choice,test=0;
                system("color 7");
                console(19,0,100,25);
                for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
                gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
                gotoxy(45,1); printf(" %c%c%c%c     EDIT RECORD     %c%c%c%c ",206,206,206,206,206,206,206,206);
                gotoxy(20,3);printf("ID list:");
                for(i=1;i<81;i++){ gotoxy(19+i,4); printf("%c",196); }
                for(i=1;i<81;i++){ gotoxy(19+i,21); printf("%c",196); }
                gotoxy(20,23); for(i=1; i<81; i++) {  printf("%c",205); }

                FILE *salary;
                salary=fopen("file/SRequest.dat","r");
                gotoxy(29,3);
                while(fscanf(salary,"%d %lf %lf \n",&add.id_no,&add.salary,&add.newsalary)!=EOF)
                {
                    printf("%d-", add.id_no);
                    i++;
                }fclose(salary);

                gotoxy(20,5);printf(">Enter ID: ");
                gotoxy(30,5);scanf("%d",&upd.id_no);

                FILE *Sname3;
                Sname3=fopen("file/SRequest.dat","r");

                while(fscanf(Sname3,"%d %lf %lf \n",&add.id_no,&add.salary,&add.newsalary)!=EOF)
                {
                if(add.id_no==upd.id_no)
                {
                    i=1;
                    fscanf(Sname3,"%lf",upd.newsalary);
                    console(45,5,75,7); gotoxy(46,4); printf("Old Salary"); gotoxy(46,6); printf("%.lf ",add.salary);
                    console(45,10,75,12); gotoxy(46,9);printf("New Salary "); gotoxy(46,11); printf("%.lf",add.newsalary);
                    console(45,15,75,17); gotoxy(46,14);printf("Enter Salary ");
                }
                }fclose(Sname3);


                FILE*old,*newrec;
                old=fopen("employee.dat","r");
                newrec=fopen("new.dat","w");
                while(fscanf(old,"%d %d/%d/%d %s %d %s %lf %s\n",&add.id_no,&add.doj.day,&add.doj.month,&add.doj.year,add.name,&add.age,add.dept,&add.salary,add.address)!=EOF)
                {
                    if(add.id_no==upd.id_no)
                    {
                        i=1;
                        gotoxy(46,16);scanf("%lf",&upd.salary);
                        fprintf(newrec,"%d %d/%d/%d %s %d %s %lf %s\n",add.id_no,add.doj.day,add.doj.month,add.doj.year,add.name,add.age,add.dept,upd.salary,add.address);
                    }
                    else
                    fprintf(newrec,"%d %d/%d/%d %s %d %s %lf %s\n",add.id_no,add.doj.day,add.doj.month,add.doj.year,add.name,add.age,add.dept,add.salary,add.address);
                }
                if(i!=1)
                {
                    gotoxy(20,22); printf(" Record not found!!");
                    goto Sal_try;
                }
                fclose(old);
                fclose(newrec);
                remove("employee.dat");
                rename("new.dat","employee.dat");

                char f[9]="SAVEING.."; int m; gotoxy(20,22); for(m=0;m<9;m++){; printf("%c",f[m]); Sleep(3); }
                int j=1;while(j!=5) {for(i=1;i<6;i++){ gotoxy(29+i,22); printf("."); Sleep(100);}j++;}
                gotoxy(20,22); for(i=1; i<81; i++) {  printf(" "); } gotoxy(20,22);printf(">change saved!!");

                Sal_try:
                gotoxy(20,24); printf("> 1 [Employee Req]:   ");
                gotoxy(41,24);scanf("%d",&main_exit);
                if (main_exit==1)
                {
                        system("cls");
                        EmpREQ();
                }
                else
                {
                    gotoxy(70,23); printf("Invalid! Selection");
                    fordelay(100000000);
                     for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
                    goto Sal_try;
                }

            }
            else if (main_exit==2)
            {
                system("cls"); EmpREQ();
            }
            else if (main_exit==3)
            {
                admin_menu();
            }
            else
                    {
                    gotoxy(70,23); printf("Invalid! Selection");
                    fordelay(100000000);
                     for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
                    goto Saetry;
                    }
    }

    if(ch==5)
    {
    system("cls");
    console(19,0,100,25);
    for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
    gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
    gotoxy(40,1); printf(" %c%c%c%c        NAME REQ        %c%c%c%c ",206,206,206,206,206,206,206,206);
    for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
    FILE *Rnd;
    Rnd=fopen("file/NRequest.dat","r");
    fclose(Rnd);

    char f[11]="REMOVING..."; int m; gotoxy(55,24); for(m=0;m<11;m++){; printf("%c",f[m]); Sleep(3); }
    int j=1;while(j!=7) {for(i=1;i<6;i++){ gotoxy(63+i,24); printf("."); Sleep(100);}j++;}

    remove("file/NRequest.dat");

    gotoxy(45,15); printf("Removed!!");

    NRD:
    gotoxy(20,24); printf("> 1 [Employee Request]     > 2 [Main Menu]    > Enter choice:");
    gotoxy(94,24);scanf("%d",&main_exit);
    if (main_exit==1)
    {
        system("cls"); EmpREQ();
    }
    else if (main_exit==3)
    {
        admin_menu();
    }
    else
        {
            gotoxy(70,23); printf("Invalid! Selection");
            fordelay(100000000);
            for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
            goto NRD;
        }

    }

    if(ch==6)
    {
    system("cls");
    console(19,0,100,25);
    for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
    gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
    gotoxy(40,1); printf(" %c%c%c%c        DEPT REQ        %c%c%c%c ",206,206,206,206,206,206,206,206);
    for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
    FILE *Rdd;
    Rdd=fopen("file/DRequest.dat","r");
    fclose(Rdd);

    char f[11]="REMOVING..."; int m; gotoxy(55,24); for(m=0;m<11;m++){; printf("%c",f[m]); Sleep(3); }
    int j=1;while(j!=7) {for(i=1;i<6;i++){ gotoxy(63+i,24); printf("."); Sleep(100);}j++;}


        remove("file/DRequest.dat");

        gotoxy(45,15); printf("Removed!!");


    DRD:
    gotoxy(20,24); printf("> 1 [Employee Request]     > 2 [Main Menu]    > Enter choice:");
    gotoxy(94,24);scanf("%d",&main_exit);
    if (main_exit==1)
    {
        system("cls"); EmpREQ();
    }
    else if (main_exit==3)
    {
        admin_menu();
    }
    else
        {
            gotoxy(70,23); printf("Invalid! Selection");
            fordelay(100000000);
            for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
            goto DRD;
        }


    }

    if(ch==7)
    {
    system("cls");
    console(19,0,100,25);
    for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
    gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
    gotoxy(40,1); printf(" %c%c%c%c        ADDRESS REQ        %c%c%c%c ",206,206,206,206,206,206,206,206);
    for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
    FILE *Rad;
    Rad=fopen("file/ARequest.dat","r");
    fclose(Rad);

    char f[11]="REMOVING..."; int m; gotoxy(55,24); for(m=0;m<11;m++){; printf("%c",f[m]); Sleep(3); }
    int j=1;while(j!=7) {for(i=1;i<6;i++){ gotoxy(63+i,24); printf("."); Sleep(100);}j++;}


    remove("file/ARequest.dat");

    gotoxy(45,15); printf("Removed!!");

    ARD:
    gotoxy(20,24); printf("> 1 [Employee Request]     > 2 [Main Menu]    > Enter choice:");
    gotoxy(94,24);scanf("%d",&main_exit);
    if (main_exit==1)
    {
        system("cls"); EmpREQ();
    }
    else if (main_exit==3)
    {
        admin_menu();
    }
    else
        {
            gotoxy(70,23); printf("Invalid! Selection");
            fordelay(100000000);
            for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
            goto ARD;
        }


    }

    if(ch==8)
    {
    system("cls");
    console(19,0,100,25);
    for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
    gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
    gotoxy(40,1); printf(" %c%c%c%c        SALARY REQ        %c%c%c%c ",206,206,206,206,206,206,206,206);
    for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
    FILE *Rsd;
    Rsd=fopen("file/SRequest.dat","r");
    fclose(Rsd);

    char f[11]="REMOVING..."; int m; gotoxy(55,24); for(m=0;m<11;m++){; printf("%c",f[m]); Sleep(3); }
    int j=1;while(j!=7) {for(i=1;i<6;i++){ gotoxy(63+i,24); printf("."); Sleep(100);}j++;}


    remove("file/SRequest.dat");

    gotoxy(45,15); printf("Removed!!");

    SRD:
    gotoxy(20,24); printf("> 1 [Employee Request]     > 2 [Main Menu]    > Enter choice:");
    gotoxy(94,24);scanf("%d",&main_exit);
    if (main_exit==1)
    {
        system("cls"); EmpREQ();
    }
    else if (main_exit==3)
    {
        admin_menu();
    }
    else
        {
            gotoxy(70,23); printf("Invalid! Selection");
            fordelay(100000000);
            for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
            goto SRD;
        }



    }

    if(ch==9)
    {
    system("cls");
    console(19,0,100,25);
    for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
    gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
    gotoxy(40,1); printf(" %c%c%c%c        SALARY REQ        %c%c%c%c ",206,206,206,206,206,206,206,206);
    for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}

    FILE *Rnd;
    Rnd=fopen("file/NRequest.dat","r");
    fclose(Rnd);

    FILE *Rdd;
    Rdd=fopen("file/DRequest.dat","r");
    fclose(Rdd);

     FILE *Rad;
    Rad=fopen("file/ARequest.dat","r");
    fclose(Rad);

    FILE *Rsd;
    Rsd=fopen("file/SRequest.dat","r");
    fclose(Rsd);

     gotoxy(20,7); printf("NRequest");
     gotoxy(20,9); printf("DRequest");
     gotoxy(20,11); printf("ARequest");
     gotoxy(20,13); printf("SRequest");

    char f[11]="REMOVING..."; int m; gotoxy(55,24); for(m=0;m<11;m++){; printf("%c",f[m]); Sleep(3); }
    int j=1;while(j!=7) {for(i=1;i<6;i++){ gotoxy(63+i,24); printf("."); Sleep(100);}j++;}

    fordelay(90000000);gotoxy(30,7); printf("%c",251);
    fordelay(90000000);gotoxy(30,9); printf("%c",251);
    fordelay(90000000);gotoxy(30,11); printf("%c",251);
    fordelay(9990000);gotoxy(30,13); printf("%c",251);

     remove("file/NRequest.dat");
     remove("file/DRequest.dat");
     remove("file/ARequest.dat");
     remove("file/SRequest.dat");

    gotoxy(20,22); printf("Removed!!");


    ALLRD:
    gotoxy(20,24); printf("> 1 [Employee Request]     > 2 [Main Menu]    > Enter choice:");
    gotoxy(84,24);scanf("%d",&main_exit);
    if (main_exit==1)
    {
        system("cls"); EmpREQ();
    }
    else if (main_exit==2)
    {
        admin_menu();
    }
    else
        {
            gotoxy(70,23); printf("Invalid! Selection");
            fordelay(100000000);
            for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
            goto ALLRD;
        }
    }

    if(ch==0)
    {
        admin_menu();
    }

    else
    {
        gotoxy(70,23); printf("Invalid! Selection");
        fordelay(100000000);
        for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
        goto Req;
    }

}

void preclose(void)
{
            permission_try:
            console(19,0,100,25);
            for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
            gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
            gotoxy(45,1); printf(" %c%c%c%c      CLOSE ERMS        %c%c%c%c ",206,206,206,206,206,206,206,206);
            for(i=1;i<81;i++){ gotoxy(19+i,23); printf("%c",196); }
            gotoxy(20,24); for(i=1; i<81; i++) {  printf("\xb1"); }

            console(45,6,75,8); gotoxy(46,7);printf("> WHAT DO YOU  WANT TO EXIT <");
            console(29,13,45,15);gotoxy(30,14); printf(" 1>>  YES  <<1 ");
		    console(75,13,91,15);gotoxy(76,14); printf(" 2>>  N0!  <<2 ");
            console(58,16,62,18);gotoxy(60,17);scanf("%d",&main_exit);
            if (main_exit==1)
                    {
                        system("cls");
                        close();
                    }
            else if (main_exit==2) { admin_menu(); }
            else
                    {
                    gotoxy(56,24);printf("Invalid!");
                    fordelay(100000000);
                    gotoxy(60,17);printf(" ");
                    gotoxy(20,24); for(i=1; i<81; i++) {  printf("\xb1"); }
                    goto permission_try;
                    }
}

void close()
{
            console(19,0,100,25);
            for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
            gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
            gotoxy(45,1); printf(" %c%c%c%c       ABOUT ERMS       %c%c%c%c ",206,206,206,206,206,206,206,206);
            for(i=1;i<81;i++){ gotoxy(19+i,23); printf("%c",196); }
            gotoxy(20,24); for(i=1; i<81; i++) {  printf("\xb1"); }

            fordelay(90000000); gotoxy(57,4); printf("V2-STABLE");
            fordelay(90000000); gotoxy(44,5); printf("COPIED FORM HTTPS://CODEWITHC.COM");

            fordelay(90000000); gotoxy(58,7); printf("V3-ALPA");
            fordelay(9000000000); gotoxy(35,8); printf("[ADDED] [SERACH] [ADMIN-LOGIN] [EDIT] [INPROVE UI]");

            fordelay(90000000); gotoxy(57,10); printf("V4-STABLE");
            fordelay(9000000000); gotoxy(38,11); printf("APPS UI FULLY CHANGE & RENEWED ALL FUNCTIONS");
            fordelay(90000000); gotoxy(41,12); printf("FIXED SUDDENLY CLOSED & SOME TINY BUGS");

            fordelay(90000000000); gotoxy(58,14); printf("V5-BETA");
            fordelay(90000000); gotoxy(41,15); printf("[ADDED] [EMP-LOGIN] [EMP-MENU] [EMP-REQ]");
            fordelay(9000000000); gotoxy(42,16); printf("ALL FUNCTIONS ARE NOT WORKED PERFECTLY");

            fordelay(90000000000); gotoxy(57,18); printf("V6-STABLE");
            fordelay(9000000078); gotoxy(34,19); printf("ALL THE BUGS ARE FIXED WITH INPROUVMENT OF DATA SAPETY");
            fordelay(90000000644); gotoxy(48,20); printf("ADDED CHANGELOG/WIPE & MORE");
            fordelay(9000000000); gotoxy(21,24); printf("  NOTE- V6 IS THE FINAL BUILD SO NO MORE UPDATE & THE APPS IS [DISCONTINUED]  ");


            gotoxy(20,4); for(i=0; i<1; i++) { printf("                                                                       "); Sleep(25); }
            gotoxy(20,5); for(i=0; i<1; i++) { printf("                                                                       "); Sleep(25); }
            gotoxy(20,7); for(i=0; i<1; i++) { printf("                                                                       "); Sleep(25); }
            gotoxy(20,8); for(i=0; i<1; i++) { printf("                                                                       "); Sleep(25); }
            gotoxy(20,10); for(i=0; i<1; i++) { printf("                                                                       "); Sleep(25); }
            gotoxy(20,11); for(i=0; i<1; i++) { printf("                                                                       "); Sleep(25); }
            gotoxy(20,12); for(i=0; i<1; i++) { printf("                                                                       "); Sleep(25); }
            gotoxy(20,14); for(i=0; i<1; i++) { printf("                                                                       "); Sleep(25); }
            gotoxy(20,15); for(i=0; i<1; i++) { printf("                                                                       "); Sleep(25); }
            gotoxy(20,16); for(i=0; i<1; i++) { printf("                                                                       "); Sleep(25); }
            gotoxy(20,18); for(i=0; i<1; i++) { printf("                                                                       "); Sleep(25); }
            gotoxy(20,19); for(i=0; i<1; i++) { printf("                                                                       "); Sleep(25); }
            gotoxy(20,20); for(i=0; i<1; i++) { printf("                                                                       "); Sleep(25); }
            gotoxy(20,24); for(i=1; i<81; i++) {  printf("\xb1"); }

            gotoxy(59,4); printf("EMRS");
            gotoxy(45,5); printf("EMPLOYEE RECORD MANAGEMENT SYATEM");
            gotoxy(36,6); printf("DEVOLOPED BY THE STUDENT OF BUBT/CSE/INTAKE-37/SEC-3");
            gotoxy(50,8); printf("@IMAM [ID-17181103084]");
            gotoxy(50,9); printf("@AHAD [ID-17181103094]");
            gotoxy(50,10); printf("@ANIK [ID-17181103000]");

            gotoxy(37,13); printf("ONLINE BOOK- https://www.sattacademy.com");
            gotoxy(37,14); printf("ONLINE HELP- https://www.stackoverflow.com");
            gotoxy(37,15); printf("SOURCE CODE- https://www.codewithc.com");
            gotoxy(37,16); printf("TEXT   BOOK- Code With C/First C Program/C Programming");

            gotoxy(37,18); printf("COURCE TITLE  - 	SOFTWARE DEVELOPMENT I");
            gotoxy(37,19); printf("COURSE NO     - CSE 100");
            gotoxy(37,20); printf("COURSE TEACHER- MR.FOJLE RABBI SIR");
            gotoxy(23,22); printf("FINALLY THANKS TO OUR TEACHERS/GOOGLE/CLASSMATES/GROUPMATE & SENIOR BROTHER");
            fordelay(999000000);
            exit(1);

}

void admin_menu(void)
{
    admin:
    system("cls");
    system("color 7");
    console(19,0,100,25);
    for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
    gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
    gotoxy(45,1); printf(" %c%c%c%c      ADMIN MENU        %c%c%c%c ",206,206,206,206,206,206,206,206);
    for(i=1;i<81;i++){ gotoxy(19+i,23); printf("%c",196); }

    gotoxy(21,4);printf("1- Add employee's records. ");
    gotoxy(21,6);printf("2- Remove employee's records.  ");
    gotoxy(21,8);printf("3- Edit employee's records. ");
    gotoxy(21,10);printf("4- Search employee's records.");
    gotoxy(21,12);printf("5- View the list of employee's records.");
    gotoxy(21,14);printf("6- View Employees request.");
    gotoxy(21,16);printf("7- Exit()");
    char choice;
    gotoxy(21,24);printf("Enter your choice: ");
    gotoxy(41,24);choice  = getche();

    switch(choice)
    {
        case '1':system("cls"); new_acc();
        break;
        case '2':system("cls"); erase();
        break;
        case '3':system("cls"); edit();
        break;
        case '4': system("cls");search();
        break;
        case '5':system("start view/view.exe"); admin_menu();
        break;
        case '6':system("cls"); EmpREQ();
        break;
        case '7':system("cls"); preclose();
        break;
        default:
            {
                gotoxy(70,23); printf("Invalid! Selection");
                fordelay(100000000);
                for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
                goto admin;
            }
    }
}

void EmpMENU()
{
    system("cls");
    console(19,0,100,25);
    for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
    gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
    gotoxy(45,1); printf(" %c%c%c%c        EMPLOYEE        %c%c%c%c ",206,206,206,206,206,206,206,206);
    for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}

    console(45,8,75,10);
    char d[9]=" USER ID"; int k; gotoxy(45,7); for(k=0;k<9;k++){; printf("%c",d[k]); }
    gotoxy(46,9);scanf("%d",&check.id_no);
    console(45,13,75,15);
    char e[9]=" PASSWORD"; int l; gotoxy(45,12); for(l=0;l<9;l++){; printf("%c",e[l]); }
    gotoxy(46,14);scanf("%s",check.name);
    char pass[10],password[10]="1234";

    int choice;int a,test=0;
    char ch;
    FILE *id;
    id=fopen("employee.dat","r");

    while(fscanf(id,"%d %d/%d/%d %s %d %s %lf %s\n",&add.id_no,&add.doj.day,&add.doj.month,&add.doj.year,add.name,&add.age,add.dept,&add.salary,add.address)!=EOF)
    {
        if(add.id_no==check.id_no)
        {
            if((strcmp(check.name,add.name))==0)
            {
            char f[11]="LOGING IN.."; int m; gotoxy(55,24); for(m=0;m<11;m++){; printf("%c",f[m]); Sleep(3); }
            int j=1;while(j!=7) {for(i=1;i<6;i++){ gotoxy(63+i,24); printf("."); Sleep(100);}j++;}
            system("cls");
            Emenu:
            system("cls");
            console(19,0,100,25);
            for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
            gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
            gotoxy(40,1); printf(" %c%c%c%c        EMPLOYEE MENU        %c%c%c%c ",206,206,206,206,206,206,206,206);
            for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
            gotoxy(20,3);printf("# %s ",add.name);
            gotoxy(20,7); printf("> 1. View record.");
            gotoxy(20,9); printf("> 2. Request Name change.");
            gotoxy(20,11); printf("> 3. Request Department change.");
            gotoxy(20,13); printf("> 4. Request Address change.");
            gotoxy(20,15); printf("> 5. Request To increase salary.");
            gotoxy(20,17); printf("> 6. View sent request");
            gotoxy(20,19); printf("> 7. Exit()");
            gotoxy(20,24);printf("> Enter choice:");
            ch = getche();

            switch(ch)
            {
                case '1' :
                {
                system("cls");
                console(19,0,100,25);
                gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
                gotoxy(42,1); printf(" %c%c%c%c        VIEW RECORD        %c%c%c%c ",206,206,206,206,206,206,206,206);
                for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
                for(i=1;i<81;i++) { gotoxy(19+i,21); printf("%C",196);}
                gotoxy(20,3);printf("> Hey %s, here is your records!!",add.name);
                gotoxy(20,6);printf("** ID");                       gotoxy(35,6);printf("::> %d ",add.id_no);
                gotoxy(20,8);printf("** Name");                 gotoxy(35,8);printf("::> %s ",add.name);
                gotoxy(20,10);printf("** Age");                  gotoxy(35,10);printf("::> %d",add.age);
                gotoxy(20,12);printf("** Department");     gotoxy(35,12);printf("::> %s",add.dept);
                gotoxy(20,14);printf("** Salary");               gotoxy(35,14);printf("::> BDT-%.0lf",add.salary);
                gotoxy(20,16);printf("** Address");           gotoxy(35,16);printf("::> %s",add.address);
                gotoxy(20,18);printf("** Date of join");     gotoxy(35,18);printf("::> %d/%d/%d",add.doj.day,add.doj.month,add.doj.year);

                int a;
                Eview:
                gotoxy(20,22);printf("> 1 [main menu]");
                gotoxy(50,24);printf(">Enter your choice: ");
                gotoxy(69,24);scanf("%d",&a);
                if(a==1)  {   goto Emenu;   }
                else{ gotoxy(69,24);printf("Invalid!\a"); fordelay(10000000); gotoxy(69,24);printf("           "); goto Eview; }break;
                }

                case '2' :
                {
                system("cls");
                console(19,0,100,25);
                gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
                gotoxy(42,1); printf(" %c%c%c%c        NAME CHANGE        %c%c%c%c ",206,206,206,206,206,206,206,206);
                for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
                for(i=1;i<81;i++) { gotoxy(19+i,21); printf("%C",196);}


                FILE *Rname;
                Rname=fopen("file/NRequest.dat","a+");

                console(45,8,75,10); gotoxy(46,7); printf("Current Name"); gotoxy(46,9); printf("%s ",add.name);
                console(45,13,75,15); gotoxy(46,12);printf("New Name "); gotoxy(46,14); scanf("%s",add.newname);
                fprintf(Rname,"%d %s %s\n",check.id_no,add.name,add.newname);
                fclose(Rname);
                gotoxy(20,18); printf("Request sent");
                gotoxy(20,19); printf("Warning!! If your requested name changed successfully.");

                FILE *passname;
                passname=fopen("file/NRequest.dat","r");
                while(fscanf(passname,"%d %s %s \n",&add.id_no,&add.name,&add.newname)!=EOF)
                    {
                        if(add.id_no==check.id_no)
                        {
                            gotoxy(20,20); printf("Then you have to login with [%s] as new password.",add.newname);
                        }
                    }fclose(passname);



                Nview:
                gotoxy(20,22);printf("> 1 [main menu]");
                gotoxy(50,24);printf(">Enter your choice: ");
                gotoxy(69,24);scanf("%d",&a);
                if(a==1)  {   goto Emenu;   }
                else{ gotoxy(69,24);printf("Invalid!\a"); fordelay(10000000); gotoxy(69,24);printf("           "); goto Nview; }break;
                }
                case '3':
                {
                system("cls");
                console(19,0,100,25);
                gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
                gotoxy(42,1); printf(" %c%c%c%c        DEPARTMENT CHANGE        %c%c%c%c ",206,206,206,206,206,206,206,206);
                for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
                for(i=1;i<81;i++) { gotoxy(19+i,21); printf("%C",196);}


                FILE *Rdept;
                Rdept=fopen("file/DRequest.dat","a+");
                console(45,8,75,10); gotoxy(46,7); printf("Current Department"); gotoxy(46,9);printf("%s ",add.dept);
                console(45,13,75,15); gotoxy(46,12); printf("New Department ");    gotoxy(46,14); scanf("%s",add.newdept);

                fprintf(Rdept,"%d %s %s\n",check.id_no,add.dept,add.newdept);
                fclose(Rdept);
                gotoxy(20,20); printf("Request sent");

                Dview:
                gotoxy(20,22);printf("> 1 [main menu]");
                gotoxy(50,24);printf(">Enter your choice: ");
                gotoxy(69,24);scanf("%d",&a);
                if(a==1)  {   goto Emenu;   }
                else{ gotoxy(69,24);printf("Invalid!\a"); fordelay(10000000); gotoxy(69,24);printf("           "); goto Dview; }break;
                 }


                case '4':
                {
                system("cls");
                console(19,0,100,25);
                gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
                gotoxy(42,1); printf(" %c%c%c%c        ADDRESS CHANGE        %c%c%c%c ",206,206,206,206,206,206,206,206);
                for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
                for(i=1;i<81;i++) { gotoxy(19+i,21); printf("%C",196);}

                FILE *Radd;
                Radd=fopen("file/ARequest.dat","a+");
                console(45,8,75,10); gotoxy(46,7);  printf("Current Address");     gotoxy(46,9);printf("%s ",add.address);
                console(45,13,75,15); gotoxy(46,12);printf("New Address ");        gotoxy(46,14); scanf("%s",add.newaddress);

                fprintf(Radd,"%d %s %s\n",check.id_no,add.address,add.newaddress);
                fclose(Radd);
                gotoxy(20,20); printf("Request sent");

                Aview:
                gotoxy(20,22);printf("> 1 [main menu]");
                gotoxy(50,24);printf(">Enter your choice: ");
                gotoxy(69,24);scanf("%d",&a);
                if(a==1)  {   goto Emenu;   }
                else{ gotoxy(69,24);printf("Invalid!\a"); fordelay(10000000); gotoxy(69,24);printf("           "); goto Aview; }break;
                }

                case '5':
                {
                system("cls");
                console(19,0,100,25);
                gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
                gotoxy(42,1); printf(" %c%c%c%c        INCREASE SALARY        %c%c%c%c ",206,206,206,206,206,206,206,206);
                for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
                for(i=1;i<81;i++) { gotoxy(19+i,21); printf("%C",196);}

                FILE *Rsalary;
                Rsalary=fopen("file/SRequest.dat","a+");
                console(45,8,75,10); gotoxy(46,7); printf("Current Salary");      gotoxy(46,9);printf("%0.lf ",add.salary);
                console(45,13,75,15); gotoxy(46,12); printf("New Salary ");         gotoxy(46,14); scanf("%lf",&add.newsalary);

                fprintf(Rsalary,"%d %lf %lf\n",check.id_no,add.salary,add.newsalary);
                fclose(Rsalary);
                gotoxy(20,20); printf("Request sent");

                Sview:
                gotoxy(20,22);printf("> 1 [main menu]");
                gotoxy(50,24);printf(">Enter your choice: ");
                gotoxy(69,24);scanf("%d",&a);
                if(a==1)  {   goto Emenu;   }
                else{ gotoxy(69,24);printf("Invalid!\a"); fordelay(10000000); gotoxy(69,24);printf("           "); goto Sview; }break;
                }

                case '6':
                {
                    system("cls");
                    console(19,0,100,25);
                    gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
                    gotoxy(42,1); printf(" %c%c%c%c        SENT REQUEST        %c%c%c%c ",206,206,206,206,206,206,206,206);
                    for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
                    for(i=1;i<81;i++) { gotoxy(19+i,21); printf("%C",196);}

                    int x=1,a=1,b=1,c=1,d=1;
                    FILE *Rname;
                    Rname=fopen("file/NRequest.dat","r");
                    gotoxy(20,7); printf("Name change request:-");
                    gotoxy(50,7);
                    while(fscanf(Rname,"%d %s %s \n",&add.id_no,&add.name,&add.newname)!=EOF)
                    {
                        if(add.id_no==check.id_no)
                        {
                            printf("%d.%s ",a++,add.newname);
                            x++;
                        }
                    }fclose(Rname);



                    FILE *Rdept;
                    Rdept=fopen("file/DRequest.dat","r");
                    gotoxy(20,9); printf("Dept change request:-");
                    gotoxy(50,9);
                    while(fscanf(Rdept,"%d %s %s \n",&add.id_no,&add.dept,&add.newdept)!=EOF)
                    {
                        if(add.id_no==check.id_no)
                        {
                            printf("%d.%s ",b++,add.newdept);
                            x++;
                        }
                    }fclose(Rname);



                    FILE *Radd;
                    Radd=fopen("file/ARequest.dat","r");
                    gotoxy(20,11); printf("Add  change request:-");
                    gotoxy(50,11);
                    while(fscanf(Radd,"%d %s %s \n",&add.id_no,&add.address,&add.newaddress)!=EOF)
                    {
                        if(add.id_no==check.id_no)
                        {
                            printf("%d.%s ",c++,add.newaddress);
                            x++;
                        }
                    }  fclose(Radd);



                    FILE *Rsalary;
                    Rsalary=fopen("file/SRequest.dat","r");
                    gotoxy(20,13); printf("salary change request:-");
                    gotoxy(50,13);
                    while(fscanf(Rsalary,"%d %lf %lf \n",&add.id_no,&add.salary,&add.newsalary)!=EOF)
                    {
                        if(add.id_no==check.id_no)
                        {
                            printf("%d.%.lf ",d++,add.newsalary);
                            x++;
                        }
                    } fclose(Rsalary);

                    requview:
                    gotoxy(20,22);printf("> 1 [main menu]");
                    gotoxy(50,24);printf(">Enter your choice: ");
                    gotoxy(69,24);scanf("%d",&a);
                    if(a==1)
                    {
                        goto Emenu;
                    }
                    else
                    {
                        gotoxy(69,24);printf("Invalid!\a"); fordelay(10000000); gotoxy(69,24);printf("           "); goto requview; }break;
                    }

                case '7':
                {
                permission_try:
                system("cls");
                console(19,0,100,25);
                for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
                gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
                gotoxy(45,1); printf(" %c%c%c%c      CLOSE ERMS        %c%c%c%c ",206,206,206,206,206,206,206,206);
                for(i=1;i<81;i++){ gotoxy(19+i,23); printf("%c",196); }
                gotoxy(20,24); for(i=1; i<81; i++) {  printf("\xb1"); }

                console(45,6,75,8); gotoxy(46,7);printf("> WHAT DO YOU  WANT TO EXIT <");
                console(29,13,45,15);gotoxy(30,14); printf(" 1>>  YES  <<1 ");
                console(75,13,91,15);gotoxy(76,14); printf(" 2>>  N0!  <<2 ");
                console(58,16,62,18);gotoxy(60,17);scanf("%d",&main_exit);
                if (main_exit==1)
                {
                    system("cls");
                    close();
                }
                else if (main_exit==2)
                {
                        goto Emenu;
                }
                else{
                        gotoxy(56,24);printf("Invalid!");
                        fordelay(100000000);
                        gotoxy(60,17);printf(" ");
                        gotoxy(20,24); for(i=1; i<81; i++) {  printf("\xb1"); }
                        goto permission_try;
                      }
                }

                default:
                    {
                        gotoxy(70,23); printf("Invalid! Selection");
                        fordelay(100000000);
                        for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
                        goto Emenu;
                    }
                }
            }
            else
            {
            char g[28]=" WRONG  PASSWORD"; int n; gotoxy(47,24); for(n=0;n<28;n++){; printf("%c",g[n]); Sleep(50); }
            login_try:
            gotoxy(20,24); printf(" ENTER '1' TO TRY AGAIN:                                       ");
            gotoxy(45,24);scanf("%d",&main_exit);
            if (main_exit==1) {  system("cls"); EmpMENU(); }
            else { gotoxy(70,23); printf("Invalid! Selection"); fordelay(100000000);
                    for(i=1;i<81;i++) { gotoxy(19+i,23); printf("%C",196);}
                    goto login_try;
                    }
            }
        }
        }
        if(add.id_no!=check.id_no)
        {
            char g[18]=" WRONG USERID "; int n; gotoxy(47,24); for(n=0;n<18;n++){; printf("%c",g[n]); Sleep(50); }
            goto login_try;
        }
    }

int main()
{
    console(19,0,100,25);
    system("color 7");
    int i;
    for(i=1;i<81;i++){ gotoxy(19+i,2); printf("%c",205); }
    gotoxy(20,1); for(i=1; i<81; i++) {  printf("\xb1"); }
    gotoxy(45,1); printf(" %c%c%c%c       WELCOME       %c%c%c%c ",206,206,206,206,206,206,206,206);
    //for letter 'T'
    gotoxy(54,6); printf("\xb1\xb1\xb1\xb1\xb1\xb1"); for(i=1;i<4;i++) {gotoxy(56,6+i); printf("\xb1\xb1");}
    //for letter 'O'
    for(i=1;i<5;i++){ gotoxy(61,5+i); printf("\xb1\xb1");}
    for(i=1;i<5;i++){ gotoxy(65,5+i); printf("\xb1\xb1");}
    for(i=1;i<5;i++){ gotoxy(61+i,6); printf("\xb1\xb1");}
    for(i=1;i<5;i++){ gotoxy(61+i,9); printf("\xb1\xb1");}

    // for letter 'E'
    for(i=1;i<10;i++){ gotoxy(25+i,10); printf("\xb1\xb1"); }
    for(i=1;i<10;i++){ gotoxy(25+i,14); printf("\xb1\xb1");}
    for(i=1;i<10;i++){ gotoxy(25+i,18); printf("\xb1\xb1");}
    for(i=1;i<10;i++) { gotoxy(25,9+i); printf("\xb1\xb1");}
    // for letter 'R'
    for(i=1;i<10;i++) { gotoxy(45,12+i); printf("\xb1\xb1");}
    for(i=1;i<8;i++){ gotoxy(45+i,13); printf("\xb1\xb1");}  gotoxy(53,14); printf("\xb1\xb1"); gotoxy(54,15); printf("\xb1\xb1"); gotoxy(53,16); printf("\xb1\xb1");
    for(i=1;i<8;i++){ gotoxy(45+i,17); printf("\xb1\xb1");} gotoxy(49,18); printf("\xb1\xb1"); gotoxy(50,19); printf("\xb1\xdb1"); gotoxy(51,20); printf("\xb1\xb1"); gotoxy(52,21); printf("\xb1\xb1");
    // for letter 'M'
    for(i=1;i<10;i++) { gotoxy(65,12+i); printf("\xb1\xb1");} gotoxy(66,13); printf("\xb1\xb1"); gotoxy(67,14); printf("\xb1\xb1"); gotoxy(68,15); printf("\xb1\xb1"); gotoxy(69,16); printf("\xb1\xb1"); gotoxy(70,17); printf("\xb1\xb1");
    for(i=1;i<10;i++) { gotoxy(75,12+i); printf("\xb1\xb1");} gotoxy(74,13); printf("\xb1\xb1"); gotoxy(73,14); printf("\xb1\xb1"); gotoxy(72,15); printf("\xb1\xb1"); gotoxy(71,16); printf("\xb1\xb1"); gotoxy(70,17); printf("\xb1\xb1");
    // for letter 'S'
    for(i=1;i<11;i++){ gotoxy(85+i,10); printf("\xb1\xb1"); }
    for(i=1;i<11;i++){ gotoxy(85+i,14); printf("\xb1\xb1");} for(i=1;i<6;i++) { gotoxy(86,9+i); printf("\xb1\xb1");}
    for(i=1;i<11;i++){ gotoxy(85+i,18); printf("\xb1\xb1");} for(i=1;i<6;i++) { gotoxy(95,13+i); printf("\xb1\xb1");}

    for(i=1;i<81;i++){ gotoxy(19+i,23); printf("%c",205); }
    gotoxy(20,24); for(i=1; i<81; i++) {  printf("\xb1"); }

    char d[35]=" EMPLOYEE RECORD MENAGEMENT SYSTEM"; int k; gotoxy(43,24); for(k=0;k<35;k++){; printf("%c",d[k]); Sleep(50); }

	login_choice();
	/*char choice; gotoxy(46,10);choice  = getche();

    switch(choice)
		{
	 	    case '1' :

			break;
			case '2' :

			break;


		}*/
}
