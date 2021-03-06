void reservation()
{
    int num_train, num_seats;

    start1: system("cls");

    printf("---------------------STATIONS--------------------\n\n");
    printf("SNO  CODE     STATION NAME\n\n");
    printf("1. CSMT     Chhatrapati Shivaji Maharaj Terminus(Mumbai,MAHARASHTRA)\n\n");
    printf("2. JP       Jaipur Junction railway station (Jaipur,RAJASTHAN)\n\n");
    printf("3. MAO      Madgaon Junction railway station(Madgaon,GOA)\n\n");
    printf("4. ADI      Ahmedabad Junction (Ahmedabad,GUJARAT)\n\n");
    printf("5. PUNE     Pune Junction railway station (Pune, MAHARSHTRA)\n\n");
    printf("6. CHTS     Cochin Harbour Terminus(Cochin, KERALA)\n\n");
    printf("7. BNC      Bengaluru Cantonment (Bengaluru, KARNATAKA)\n\n");
    printf("8. MAS      Puratchi Thalaivar Dr. M.G. Ramachandran Central Railway Station(Chennai, TAMIL NADU)\n\n");
    printf("9. DEC      Delhi Cantonment railway station(Delhi)\n\n\n");

    char from[14], to[14];
    int train_num;
    printf("Enter From Station Code: ");
    scanf("%s",&from);

    if(!(strcmp(from,"CSMT")==0 || strcmp(from,"JP")==0 || strcmp(from,"MAO")==0 || strcmp(from,"ADI")==0 || strcmp(from,"PUNE")==0 || strcmp(from,"CHTS")==0||strcmp(from,"BNC")==0 || strcmp(from,"MAS")==0 ||strcmp(from,"DEC")==0))
    {
    printf("\n\nINVALID CHOICE\n\n");
    getch();
    goto start1;
    }

    else
    {
    printf("\nEnter To Station Code: ");
    scanf("%s",&to);
       if(!(strcmp(to,"CSMT")==0||strcmp(to,"JP")==0|| strcmp(to,"MAO")==0||strcmp(to,"ADI")==0||strcmp(to,"PUNE")==0||strcmp(to,"CHTS")==0||strcmp(to,"BNC")==0||strcmp(to,"MAS")==0 ||strcmp(to,"DEC")==0))
       {
            printf("\n\nINVALID CHOICE\n\n");
            getch();
            goto start1;
       }
       else
        {
            if(strcmp(from,to)==0)
            {
                printf("\n\nSOURCE AND DESTINATION CANNOT BE SAME\n\n");
                getch();
                goto start1;
            }

            else
            {
            printf("\n---------------------TRAINS AVAILABLE---------------------\n\n");
            get_trains(from, to);

            train: printf("\nEnter Train Number:");
            scanf("%d",&train_num);

            //check if train id exists
            struct node *p;
            p=root;

            bool valid=false;

                while(p!=NULL)
                {
                    if(train_num==p->train_id)
                    {
                        valid=true;
                    }
                    p=p->link;
                }

            if (valid==true)
            {
            get_details(train_num,from,to);
            }

            else
            {
                printf("\nINVALID TRAIN ID\n");
                getch();
                goto train;
            }

          }
       }
    }
}

void get_trains(char from[14], char to[14])
{
  int count=0;
  struct node *p;
  p=root;

      while(p!=NULL)
      {
        if((strcmp(from,p->source)==0 || strcmp(from,p->stop1)==0 ||strcmp(from,p->stop2)==0 ||strcmp(from,p->dest)==0)&&(strcmp(to,p->source)==0 || strcmp(to,p->stop1)==0 ||strcmp(to,p->stop2)==0 ||strcmp(to,p->dest)==0&&p->seats!=0))
            {
                printf("%d\t",p->train_id);
                printf("%s\t",p->train_name);
                printf("%s\t",p->source);
                printf("%s\t",p->dest);
                printf("%d\t",p->seats);
                printf("%.2f\t",p->cost);
                printf("\n");
                count++;
            }
        p=p->link;
      }

      if (count==0)
      {
          printf("\nNO TRAINS AVAILABLE\n");
          main_exit();
      }
}
//HASH TABLE TO STORE PASSENGER'S DETAILS
#define TABLE_SIZE 100

struct person
{
    int pnr;
    int age;
    char name[20];
    char sex[1];
    long long int phone_num;
    float bill;
    char train_name[30];
    int train_id;
    char source[20];
    char destination[20];

};


struct person *hash_table[TABLE_SIZE];//array of pointers
int pnr=3302;

//Quadratic probing in case of collision.
int hash(int p)
{
    int hash_value=p%TABLE_SIZE;
    return hash_value;
}

void get_details(int train_num, char from[14],char to[14])
{
    int seats,i;
    int index;

      struct node *ptr,*q;
      ptr=root;

      while(ptr!=NULL)
      {
        if(train_num==ptr->train_id)
        {
            q=ptr;
        }
        ptr=ptr->link;
      }

    seats: printf("\nEnter number of seats: ");
    scanf("%d",&seats);

    if(seats<0)
    {
        printf("\nNUMBER OF SEATS CANNOT BE NEGATIVE \n");
        getch();
        goto seats;
    }

    if(seats>6)
    {
        printf("\nNUMBER OF SEATS CANNOT EXCEED 6\n");
        getch();
        goto seats;
    }

    update_seats(train_num,seats);



    struct person *p;

    for(i=0; i<seats;i++)
    {
        system("cls");
        printf("\n------------RESERVATION DETAILS---------------\n\n");
        printf("\nDetails of passenger %d\n\n", i+1);
        p=(struct person*)malloc(sizeof(struct person));
        index=hash(pnr);

        hash_table[index]=p;
        p->pnr=pnr;

        char temp; char temp1; //buffer , null character is stored at the start of string when integer value is entered

        scanf("%c",&temp);

        printf("Enter Full Name: ");
        scanf("%[^\n]", p->name);

        gender: printf("Enter Gender M, F or O: ");
        scanf("%s",&p->sex);

        if(!(strcmp(p->sex,"F")==0||strcmp(p->sex,"M")==0||strcmp(p->sex,"O")==0))
        {
            printf("\nINVALID ENTRY\n");
            goto gender;
        }

        age: printf("Enter Age: ");
        scanf("%d",&p->age);

        if(p->age<0)
        {
        printf("\nAGE CANNOT BE NEGATIVE\n");
        getch();
        goto age;
        }

        else if(p->age>120)
        {
        printf("\nINVALID AGE\n");
        getch();
        goto age;
        }

        phone_num: printf("ENTER 10 DIGIT PHONE NUMBER: ");
        scanf("%lld",&p->phone_num);



        if(p->phone_num<1000000000)
        {
            printf("\nINVALID PHONE NUMBER\n");
            goto phone_num;
        }

        if(p->phone_num>9999999999)
        {
            printf("\nINVALID PHONE NUMBER\n");
            goto phone_num;
        }

        strcpy(p->source,from);
        strcpy(p->destination,to);
        strcpy(p->train_name,q->train_name);
        p->train_id=q->train_id;
        p->bill=q->cost;
        pnr++;
        printf("\nYOUR PNR NUMBER IS:%d", p->pnr);
        getch();
    }

    printf("\n\n\nRESERVATION SUCCESSFUL!");

    main_exit();
}


void print_table()
{
system("cls");
int i;
int count=0;
for(i=0; i<TABLE_SIZE; i++)
{
        if(hash_table[i] != NULL)
        {
        printf("%d\t",hash_table[i]->pnr);
        printf("%s\t",hash_table[i]->name);
        printf("%d\t",hash_table[i]->age);
        printf("%s\t",hash_table[i]->sex);
        printf("%d\t",hash_table[i]->phone_num);
        printf("\n");
        }
        else
        {
        count++;
        printf("");
        }
}

if(count==TABLE_SIZE)
{
    printf("\n\n\t\tNO PASSENGERS AS YET!!\n\n");
    main_exit();
}
