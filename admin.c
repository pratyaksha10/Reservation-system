/*MODULE 1. ADMIN*/
void admin()
{
start: system("cls");
int ch;
printf("\n\n\n\t\t----------ADMIN MODULE---------");
printf("\n\n\n\t\t1. Passenger List\n\n\n");
printf("\t\t2. Remaining Seats\n\n\n");
printf("\t\t3. Add a New Train\n\n\n");
printf("\t\t4. Return to Main Menu\n\n\n");
printf("\t\tSelect your choice: ");
scanf("%d",&ch);

switch(ch)
{
    case 1: system("cls");
            print_table();
            main_exit();
    break;

    case 2: system("cls");
            display_train_details();
            main_exit();
    break;

    case 3: add_train();
            main_exit();
    break;

    case 4: menu();
    break;

    default: printf("\n\n\t\tINVALID CHOICE\n\n");
             getch();
             goto start;

}
}
