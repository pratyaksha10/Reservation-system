int choice, quantity;

struct food
{
    int serial_no;
    char name[50];
    float price;
    struct food *link;

};

struct food *root_food=NULL;

void extra_services()
{
    char ch[1];
    int pnr;


    new_order: printf("\n----------------Today's Menu-----------------\n\n");

    printf("SNO     ITEM                            PRICE\n\n");

    display_food_menu();

    printf("\nEnter your PNR number: ");
    scanf("%d",&pnr);

    struct person *p=hash_table_lookup(pnr);

    if(p==NULL)
    {
        printf("\n\nINVALID PNR NUMBER");
        getch();
        system("cls");
        extra_services();
    }

    else
    {
        printf("\nSelect your choice: ");
        scanf("%d",&choice);

        printf("Select Quantity: ");
        scanf("%d",&quantity);

        printf("\nOrder Placed Successfully!!\n");


        printf("\nCurrent Subtotal: %.2f",total(choice, quantity));

        add_total(pnr,total(choice, quantity)); // Add cost to final bill

        printf("\nWant Anything else? 'Y'/'N'\n");
        scanf("%s",&ch);

        if(strcmp(ch,"Y")==0)
        {
        system("cls");
        goto new_order;
        }

        else
        {
        main_exit();
        }
    }
}

//DISPLAY FOOD MENU
void display_food_menu()
{
    struct food *q;
    q=root_food;

    while(q!=NULL)
    {
        printf("%d\t",q->serial_no);
        printf("%s\t",q->name);
        printf("%.2f\t",q->price);
        printf("\n");
        q=q->link;
    }
}

//INSERTION OF FOOD ITEMS INTO A SINGLE LINKED LIST
void append(int sno, char item[50], float rate)
{

	struct food *temp;

	temp=(struct food *)malloc(sizeof(struct food));
	temp->serial_no = sno;
	temp->price = rate;
    strcpy(temp->name,item);

	temp->link = NULL;


	if(root_food==NULL)
    {
		root_food= temp;
	}

	else
	{
	    struct food *p;
        p=root_food;
		while(p->link != NULL)
		{
			p = p->link;
		}

		p->link = temp;
	}

}

//CALCULATE COST OF FOOD ITEMS
float total(int choice , int quantity)
{
    float bill=0;
    struct food *p;
    p=root_food;
    int ch=choice;
    int qty=quantity;

    while(p!=NULL)
    {
        if(ch==p->serial_no)
        {
            bill=bill+p->price*qty;
        }
        p=p->link;
    }
    return bill;
}

//ADD COST OF FOOD ITEMS TO BILL
void add_total(int pnr, float subtotal)
{

    printf("\n\nSUBTOTAL ADDED TO MAIN BILL\n\n");
    struct person *temp=hash_table_lookup(pnr);
    temp->bill=temp->bill+subtotal;
}

/*BILLING MODULE*/
void billing()
{
int pnr;
printf("\nPlease enter your PNR number to print receipt: ");
scanf("%d",&pnr);

struct person *temp=hash_table_lookup(pnr);

if(temp==NULL)
{
    printf("\nINVALID PNR NUMBER\n");
}

else
{
printf("---------------PASSENGER DETAILS-----------\n\n");
printf("\t%s\n\n",temp->train_name);
printf("Source       :%s\t",temp->source);
printf("Destination  :%s\n",temp->destination);
printf("-------------------------------------------\n");
printf("PNR Number   :%d\n",temp->pnr);
printf("Name         :%s\n",temp->name);
printf("Age          :%d\n",temp->age);
printf("Sex          :%s\n",temp->sex);
printf("Phone Number :%lld\n",temp->phone_num);
printf("Ticket Cost  :%.2f\n",temp->bill);
printf("--------------------------------------------");
}

main_exit();
}
