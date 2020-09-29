void cancellation()
{
int pnr;
system("cls");
printf("ENTER PNR NUMBER: ");
scanf("%d",&pnr);

struct person *temp=hash_table_lookup(pnr);

if(temp==NULL)
{
printf("\nPNR NUMBER DOES NOT EXIST\n");
}


else
{
printf("---------PASSENGER DETAILS-----\n\n");

printf("\t%s\n",temp->train_name);
printf("Source       :%s\t",temp->source);
printf("Destination  :%s\n",temp->destination);
printf("--------------------------------\n");
printf("PNR Number   :%d\n",temp->pnr);
printf("Name         :%s\n",temp->name);
printf("Age          :%d\n",temp->age);
printf("Sex          :%s\n",temp->sex);
printf("Phone Number :%lld\n",temp->phone_num);
printf("Ticket Cost  :%.2f\n",temp->bill);// Cost upto 2 decimal places
printf("--------------------------------");
update_cancelled_seats(temp->train_id);
hash_table_cancel(pnr);
printf("\n\nTICKET SUCCESSFULLY CANCELLED");
main_exit();
}
}

struct person *hash_table_cancel(int pnr)
{
    int index=hash(pnr);
    struct person *p=hash_table[index];
    hash_table[index]=NULL;

}

void update_cancelled_seats(int id)
{
        struct node *p;
        p=root;
		while(p!= NULL)
		{
		    if(id==p->train_id)
		    {
                 p->seats=p->seats+1;
		    }
			p = p->link;
		}

}
struct person *hash_table_lookup(int pnr)
{
    int index=hash(pnr);
    if(hash_table[index]!=NULL && hash_table[index]->pnr==pnr)
    {
           struct person *p=hash_table[index];
           return p;
    }

    else
    {
        return NULL;
    }

}
