
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

//MAIN MODULES
void admin();
void train_details();
void reservation();
void cancellation();
void extra_services();
void billing();


//SUB MODULES
void menu();
void append(int serial, char train_name[100], char source[30], char stop1[30], char stop2[30], char dest[30], int seats, float cost );
void append(int sno, char item[50], float rate);
void insert_elements();
void display_train_details();
void add_train();
void update_seats();
void update_cancelled_seats(int id);
void display_food_menu();
void get_trains(char from[14], char to[14]);
void details(int num_train, int num_seats);
struct person *hash_table_lookup(int pnr);
struct person *hash_table_cancel(int pnr);
float total(int choice, int quantity);
void add_total(int pnr, float subtotal);
void get_details(int train_num, char from[14], char to[14]);
void print_table();
void  main_exit();
int hash(int p);


int main()
{
system("color 9");
insert_elements();// update data of all modules
printf("\n\t\t\t\t\t\t\t---------- SUHANA SAFAR RAILWAY RESERVATION SYSTEM -------\n\n");
printf("\n\t\t\t\t\t\t\t\t\tBROUGHT TO YOU BY :\n\n");
printf("\n\t\t\t\t\t\t\t||              SILVI TANEJA        19BCE0782           ||\n");
printf("\n\t\t\t\t\t\t\t||              RASHI MARU          19BCE0757           ||\n");
printf("\n\t\t\t\t\t\t\t||              PRATYAKSHA          19BCI0136           ||\n");
printf("\n\t\t\t\t\t\t\t||              RISHABH RAJ         19BCE0777           ||\n");
printf("\n\t\t\t\t\t\t\t||              SHREYA RASTOGI      19BCE0756           ||\n");
printf("\n\t\t\t\t\t\t\t||              NISHMA REBELLO      19BCE0253           ||\n");
getch();
menu();
return 0;
}

void menu()
{

    int choice;
    system("cls");
    system("color 9");

    printf("\n\n\t    RAILWAY RESERVATION MANAGEMENT SYSTEM");
    printf("\n\n\n\t********* WELCOME TO THE MAIN MENU **********\n\n");
    printf("\n\t1. Admin\t\t\n");
    printf("\n\t2. Train Details\n\t\t");
    printf("\n\t3. Reservation\n\t\t");
    printf("\n\t4. Cancellation\n\t\t");
    printf("\n\t5. Extra Services\n\t\t");
    printf("\n\t6. Billing\n\t\t");
    printf("\n\t7. Exit\n\t\t");
    printf("\n\tSELECT YOUR CHOICE: ");
    scanf("%d",&choice);
    system("cls");
    switch(choice)
    {
        case 1:admin();
        break;
        case 2:train_details();
        break;
        case 3:reservation();
        break;
        case 4:cancellation();
        break;
        case 5:extra_services();
        break;
        case 6:billing();
        break;
        case 7:printf("\n\nTHANK YOU!!\n\n");
               exit(0);
        break;
        default:menu();

    }
}

//INSERT DATA INTO LINKED LISTS
void insert_elements()
{
    append(13456,"GOA EXPRESS            ","MAO","NULL","NULL","DEC", 350, 164.00);
    append(14356,"DELHI DURANTO EXPRESS  ","PUNE","NULL","NULL","DEC", 400, 2198.00);
    append(13256,"MANDOVI EXPRESS        ","MAO","NULL","NULL","CSMT", 600, 1272.00);
    append(14597,"GOLDEN CHARIOT         ","BNC","NULL","NULL","MAO", 500,  600.00);
    append(19984,"DEE GARIBRATH          ","CSMT","NULL","NULL","JP", 340,  800.00);
    append(12296,"PUNE ADI DURANTO       ","PUNE","CSMT","NULL","ADI", 456,  900.00);
    append(17018,"SURYA NAGARI EXPRESS   ","CSMT","ADI","NULL","JP", 100,  700.00);
    append(19784,"UDYAN EXPRESS          ","CSMT","PUNE","NULL","BNC", 450,  750.00);
    append(13981,"SBC EXPRESS            ","ADI","CSMT","PUNE","BNC", 650,  860.00);
    append(14584,"GITANJALI EXPRESS      ","CSMT","NULL","NULL","JP", 500,  890.00);
    append(15674,"CSMT CHENNAI EXPRESS   ","CSMT","PUNE","NULL","MAS", 120,  900.00);
    append(13767,"CHENNAI MAIL           ","CSMT","PUNE","BNC","MAS", 600,  1000.00);
    append(10935,"HUMSAFAR EXPRESS       ","JP","ADI","BNC","CHTS", 760,  800.00);
    append(16439,"MUMBAI DURANTO EXPRESS ","DEC","JP","ADI","CSMT", 400,  800.00);
    append(14577,"MANDOR EXPRESS         ","JP","NULL","NULL","DEC", 540,  340.00);
    append(13652,"JP PUNE EXPRESS        ","JP","PUNE","NULL","CSMT", 340,  670.00);
    append(12335,"JP CHENNAI EXPRESS     ","JP","BNC","NULL","MAS", 230,  450.00);
    append(10259,"MARU SAGAR EXPRESS     ","JP","BNC","NULL","CHTS", 650,  660.00);
    append(15677,"ADI PUNE EXPRESS       ","ADI","CSMT","NULL","PUNE", 750,  230.00);
    append(13782,"ADI MADGAON EXPRESS    ","ADI","CSMT","NULL","MAO", 560,  1120.00);
    append(16094,"NAVJEEVAN EXPRESS      ","ADI","NULL","NULL","MAS", 550,  860.00);
    append(18930,"RAJDHANI EXPRESS       ","ADI","CSMT","MAO","CHTS", 700,  900.00);
    append(12041,"MUMBAI RAJDHANI        ","DEC","NULL","NULL","CSMT", 500,  700.00);
    append(13844,"MMCT DURANTO           ","DEC","NULL","NULL","CSMT", 100,  860.00);
    append(11043,"SAINIK EXPRESS         ","DEC","NULL","NULL","JP", 700,  890.00);
    append(12584,"MAO SUP EXPRESS        ","MAO","NULL","NULL","ADI", 450,  880.00);



    append(1,"Tea                100 ml",10.00);
    append(2,"Coffee             100 ml",15.00);
    append(3,"Soup               150 ml",30.00);
    append(4,"Water Bottle           1L",20.00);
    append(5,"Idli Vada                ",40.00);
    append(6,"Upma                     ",40.00);
    append(7,"Pongal                   ",40.00);
    append(8,"Egg Omlet                ",50.00);
    append(9,"Standard Veg Meal        ",100.00);
    append(10,"Standard Non Veg Meal   ",120.00);
    append(11,"Veg Biriyani     (350gm)",70.00);
    append(12,"Egg Biriyani     (350gm)",80.00);
    append(13,"Chicken Biriyani (350gm)",80.00);
}

void  main_exit()
{
    int main_exit;
    start: printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    if(main_exit==1)
    {
        system("cls");
        menu();
    }
    if(main_exit==0)
    {
        printf("\n\nTHANK YOU!!");
        exit(0);
    }

    else
    {
    printf("\n\nINVALID CHOICE");
    goto start;
    }

}
