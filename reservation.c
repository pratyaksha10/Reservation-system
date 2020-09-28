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
