struct node
{
    int train_id;
    char train_name[100];
    char source[30];
    char stop1[30];
    char stop2[30];
    char dest[30];
    int seats;
    float cost;
    struct node *link;

};

struct node *root=NULL;

void train_details()
{
    display_train_details();
    main_exit();
}

//INSERTION OF TRAIN DETAILS INTO A SINGLE LINKED LIST
void append(int train_id, char *train_name, char source[30], char stop1[30], char stop2[30], char dest[30], int seats, float cost)
{

	struct node *temp;

	temp=(struct node *)malloc(sizeof(struct node));
	temp->train_id = train_id;
	temp->cost   = cost;
	temp->seats  = seats;
    strcpy(temp->train_name,train_name);
    strcpy(temp->source,source);
    strcpy(temp->stop1,stop1);
    strcpy(temp->stop2,stop2);
    strcpy(temp->dest,dest);

	temp->link = NULL;


	if(root==NULL)
    {
		root = temp;
	}

	else
	{
	    struct node *p;
        p=root;
		while(p->link != NULL)
		{
			p = p->link;
		}

		p->link = temp;
	}

}


void add_train()
{
    system("cls");
    int train_id;
    char name[100];
    char source[30];
    char stop1[30];
    char stop2[30];
    char destination[30];
    int seats;
    float price;
    char temp;


    train_id: printf("\nEnter the  Train ID: ");
    scanf("%d",&train_id);

    if(train_id<0)
    {
        printf("\nTRAIN ID CANNOT BE NEGATIVE\n");
        goto train_id;
    }

    if(train_id>99999)
    {
        printf("\nTRAIN ID CANNOT EXCEED FIVE DIGITS\n");
        goto train_id;
    }

    struct node *p;
    p=root;

    while(p!=NULL)
    {
        if(train_id==p->train_id)
        {
            printf("\nTRAIN ID ALREADY EXISTS\n");
            getch();
            goto train_id;
        }
        p=p->link;
    }

    scanf("%c",&temp);
    printf("\nEnter Train Name: ");
    scanf("%[^\n]", name);


    source: printf("\nEnter source station code: ");
    scanf("%s",&source);


    if(!(strcmp(source,"CSMT")==0||strcmp(source,"JP")==0|| strcmp(source,"MAO")==0||strcmp(source,"ADI")==0||strcmp(source,"PUNE")==0||strcmp(source,"CHTS")==0||strcmp(source,"BNC")==0||strcmp(source,"MAS")==0 ||strcmp(source,"DEC")==0))
    {
            printf("\n\nINVALID CHOICE\n\n");
            getch();
            goto source;
    }

    stop1: printf("\nEnter stop1 station code: ");
    scanf("%s",&stop1);

    if(!(strcmp(stop1,"CSMT")==0||strcmp(stop1,"JP")==0|| strcmp(stop1,"MAO")==0||strcmp(stop1,"ADI")==0||strcmp(stop1,"PUNE")==0||strcmp(stop1,"CHTS")==0||strcmp(stop1,"BNC")==0||strcmp(stop1,"MAS")==0 ||strcmp(stop1,"DEC")==0||strcmp(stop1,"NULL")==0))
    {
            printf("\nINVALID CHOICE\n");
            getch();
            goto stop1;
    }

    if(strcmp(stop1,source)==0)
    {
        printf("\nSTATION ALREADY ENTERED\n");
        getch();
        goto stop1;
    }

    stop2: printf("\nEnter stop2 station code: ");
    scanf("%s",&stop2);

    if(!(strcmp(stop2,"CSMT")==0||strcmp(stop2,"JP")==0|| strcmp(stop2,"MAO")==0||strcmp(stop2,"ADI")==0||strcmp(stop2,"PUNE")==0||strcmp(stop2,"CHTS")==0||strcmp(stop2,"BNC")==0||strcmp(stop2,"MAS")==0 ||strcmp(stop2,"DEC")==0||strcmp(stop2,"NULL")==0))
    {
            printf("\n\nINVALID CHOICE\n\n");
            getch();
            goto stop2;
    }

    if(strcmp(stop2,source)==0||strcmp(stop2,stop1)==0)
    {
        printf("\nSTATION ALREADY ENTERED\n");
        getch();
        goto stop2;
    }

    destination: printf("\nEnter destination station code: ");
    scanf("%s",&destination);

    if(!(strcmp(destination,"CSMT")==0||strcmp(destination,"JP")==0|| strcmp(destination,"MAO")==0||strcmp(destination,"ADI")==0||strcmp(destination,"PUNE")==0||strcmp(destination,"CHTS")==0||strcmp(destination,"BNC")==0||strcmp(destination,"MAS")==0 ||strcmp(destination,"DEC")==0))
    {
            printf("\n\nINVALID CHOICE\n\n");
            getch();
            goto destination;
    }

    if(strcmp(destination,source)==0||strcmp(destination,stop1)==0||strcmp(destination,stop2)==0)
    {
        printf("\nSTATION ALREADY ENTERED\n");
        getch();
        goto destination;
    }

    seats: printf("\nEnter Seats: ");
    scanf("%d",&seats);

    if(seats<0)
    {
        printf("\n\nNUMBER OF SEATS CANNOT BE NEGATIVE\n\n");
        getch();
        goto seats;
    }

    price: printf("\nEnter Ticket Price: ");
    scanf("%f",&price);

    if(price<0)
    {
        printf("\n\nPRICE CANNOT BE NEGATIVE\n\n");
        getch();
        goto price;
    }

    append(train_id,name,source,stop1,stop2,destination, seats, price);

    printf("\n\nTRAIN SUCCESSFULLY ADDED!\n\n");

}


void update_seats(int id, int seats)
{
        struct node *p;
        p=root;
		while(p!= NULL)
		{
		    if(id==p->train_id)
		    {
                 p->seats=p->seats-seats;
		    }
			p = p->link;
		}

}

void display_train_details()
{
    printf("\n--------------------------------------------------TRAIN DETAILS-------------------------------------------------------\n\n");
    printf("ID      TRAIN NAME                      SOURCE  DEST   SEATS    PRICE\n\n");
    struct node *p;
    p=root;

    while(p!=NULL)
    {
        printf("%d\t",p->train_id);
        printf("%s\t\t",p->train_name);
        printf("%s\t",p->source);
        printf("%s\t",p->dest);
        printf("%d\t",p->seats);
        printf("%.2f\t",p->cost);
        printf("\n");
        p=p->link;
    }
}
