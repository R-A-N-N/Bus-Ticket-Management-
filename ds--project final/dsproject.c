#include<stdio.h>
#include<malloc.h>
#include<string.h>
int seats1,bus_no;
struct node
{
int busno,price,seats;
char source[100],destination[100],date[100];
struct node *next;
};
struct user_node
{
	int reg_no,age;
	char name[100];
    double phoneno;
    struct user_node *next1;
};
int num=0;
int count=0;
struct node *start=NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct user_node *start1=NULL;
struct user_node *front=NULL;
struct user_node *rear=NULL;
struct user_node *create(struct user_node *);
void enqueue(struct user_node *);
struct user_node *dequeue();
void cancel();
void print_ticket();
struct user_node *display1(struct user_node *);
int main()
{
int choice,opt;
printf("Press 1 if you are an admin. Press 2 if you are a user: ");
scanf("%d",&choice);
while(choice!=0)
{
if(choice==1){
do
{
printf("\n ******Admin Entry******");
printf("\n 1.to enter details of bus");
printf("\n 2.to display entered details of bus");
printf("\n 3.to display passenger information of a bus ");
printf("\n 4.to exit");
printf("\n Enter your choice: ");
scanf("%d",&opt);
printf("\n");
switch(opt)
{
case 1: start=create_ll(start);
printf("\n-----------bus inserted----------\n");
break;
case 2:
		start=display(start);

break;
case 3: start1=display1(start1);
break;
case 4:break;
default:break;
}
}while(opt!=4);
}
if(choice==2)
{
	int option;
	do
	{
		printf("\n ******USER MENU****** ");
		printf("\n 1.to reserve ticket ");
		printf("\n 2. to cancel ticket");
		printf("\n 3.to exit");
		printf("\n Enter your choice: ");
		scanf("%d",&option);
		printf("\n");
		switch(option)
		{
			case 1:start1=create(start1);
			break;
			case 2:cancel();
			break;
			case 3:break;
			default: break;
		}
	}while(option!=3);
}
printf("Press 1 if you are an admin. Press 2 if you are a user. Else,press 0 to exit:  ");
scanf("%d",&choice);
}
return 0;
}

				struct node *create_ll(struct node *start)
				{
				struct node *new_node,*ptr;
				int busno1,price1 ;
				char source1[100], destination1[100], date1[100];
				printf(" Enter the bus no. (or press -1 to exit): ");
				scanf("%d",&busno1);
				while(busno1!=-1)
				{
				printf(" Enter the source: ");
				scanf("%s",source1);
				printf(" Enter the destination: ");
				scanf("%s",destination1);
				printf(" Enter the date of journey: mm/dd/yyyy: ");
				scanf("%s",date1);
				printf(" Enter the price of one ticket: ");
				scanf("%d",&price1);
				printf(" Enter the total number of seats: ");
				scanf("%d",&seats1);
				new_node=(struct node*)malloc(sizeof(struct node));
				new_node->busno=busno1;
				strcpy(new_node->source,source1);
				strcpy(new_node->destination,destination1);
				strcpy(new_node->date,date1);
				new_node->price=price1;
				new_node->seats=seats1;
				if(start ==NULL)
				{
				new_node->next=NULL;
				start=new_node;
				}
				else
				{
				ptr=start;
				while(ptr->next!=NULL)
				ptr=ptr->next;
				ptr->next=new_node;
				new_node->next=NULL;
				}
				printf("\n");
				printf(" Enter the busno(press -1 to exit): ");
				scanf("%d",&busno1);
				}
				return start;
				}


				struct node *display(struct node *start)
				{
				struct node *ptr;
		        ptr=start;
				while(ptr!=NULL)
				{
				printf("\n BUS NO: %d",ptr->busno);
				printf("\n SOURCE: %s",ptr->source);
				printf("\n DESTINATION: %s",ptr->destination);
				printf("\n DATE: %s",ptr->date);
				printf("\n PRICE: %d",ptr->price);
				printf("\n TOTAL NUMBER OF SEATS: %d",ptr->seats);
				printf("\n");
				ptr=ptr->next;
				}
				return start;
				}


struct user_node *create(struct user_node* start1)
{
	char src[100],dest[100];

	int no=0;
	struct node *ptr;
	struct user_node *pptr,*new_node;
	new_node=(struct user_node*)malloc(sizeof(struct user_node));
	new_node->next1=NULL;
	ptr=start;
	printf(" Enter the source:");
	scanf("%s",src);
	printf(" Enter the destination:");
	scanf("%s",dest);
	while(ptr!=NULL )
	{
		if(strcmp(ptr->source,src)==0 && strcmp(ptr->destination,dest)==0)
		{
			    no++;
				printf("\n BUS NO: %d",ptr->busno);
				printf("\n SOURCE: %s",ptr->source);
				printf("\n DESTINATION: %s",ptr->destination);
				printf("\n DATE: %s",ptr->date);
				printf("\n PRICE: %d",ptr->price);
				printf("\n TOTAL NUMBER OF SEATS: %d",ptr->seats);
				printf("\n");
		}

			ptr=ptr->next;
	}
	if(no==0)
	{
		printf("\n No bus is available....sorry!!\n");
	}
	else
    {
	printf("\n %d bus(es) is available....!!",no);
    printf("\n Enter the bus_no of the bus you wish to book: ");
	scanf("%d",&bus_no);
	printf("\n --------Enter your personal details------- ");
	printf("\n Enter your name:");
	scanf("%s",new_node->name);
	printf(" Enter your age:");
	scanf("%d",&new_node->age);
	printf(" Enter the phone no.:");
	scanf("%ld",&new_node->phoneno);
	if(start1==NULL)
	{
		new_node->reg_no=1;
		start1=new_node;
		num++;
		printf("\n Booking Successful...!!!\n Your reg no. is %d \n\n",num);
		print_ticket();
	}
	else
	{
		pptr=start1;
		while(pptr->next1!=NULL)
		pptr=pptr->next1;
		if(num<seats1)
		{
			num++;
			new_node->reg_no=num;
			pptr->next1=new_node;
			printf("\n Booking Successful...!!!\nYour reg no. is %d \n\n",num);
			print_ticket();
		}
		else
		{
			enqueue(new_node);
			printf("\n Booking is full....!!!\nYou are added to Waiting List no is %d \n\n",count);
		}
	}
}
	return start1;
}
	void enqueue(struct user_node *new_node)
	{
		if(rear==NULL)
		{
			rear=new_node;
			rear->next1=NULL;
			front=rear;
		}
		else
		{
			struct user_node *ptr;
			ptr=new_node;
			rear->next1=ptr;
			ptr->next1=NULL;
			rear=new_node;
		}
		count++;
	}

struct user_node *dequeue()
{
	if(front==NULL)
	{
		printf("\n Waiting list is empty...");
		return NULL;
	}
	else
	{
		count--;
		struct user_node *temp;
		temp=front;
		front=front->next1;
		temp->next1=NULL;
		return temp;
	}
}

void cancel()
{
	int reg;
	printf("\n Enter the reg no to be canceled: ");
	scanf("%d",&reg);
	if(reg>num)
	{
		printf(" INVALID NO....!!");
	}
	else
	{
		struct user_node *ptr,*preptr,*new_node;
		ptr=start1;
		if(start1==NULL)
	    	printf(" INVALID NO....!!");
	    if(ptr->next1==NULL && ptr->reg_no==reg)
	    {
	      start1=NULL;
		  num--;
		  free(ptr);
		  printf(" Reservation canceled Successfully...!!");
		}
		else
		{
			while(ptr->next1!=NULL && ptr->reg_no!=reg)
			{
				preptr=ptr;
		        ptr=ptr->next1;
			}
			if(ptr==NULL && ptr->reg_no!=reg)
			printf(" INVALID NO....!!");
			else
			preptr->next1=ptr->next1;
			free(ptr);
			new_node=dequeue();
			while(preptr->next1!=NULL)
			preptr=preptr->next1;
			preptr->next1=new_node;
			num--;
			printf(" Reservation canceled Successfully...!!");
		}
	}
}

struct user_node *display1(struct user_node *start)
{
	struct user_node *ptr;
	ptr=start1;
	printf("\n bus no %d passenger details: ",bus_no);
	while(ptr!=NULL)
	{
		printf("\n Registration no: %d",ptr->reg_no);
		printf("\n Name: %s",ptr->name);
	    printf("\n Age: %d",ptr->age);
	   // printf("\nPhone no.: %ld",ptr->phoneno);
	    ptr=ptr->next1;
	}
}

void print_ticket()
{
	struct node *ptr;
		        ptr=start;
				while(ptr!=NULL)
				{
					if(ptr->busno==bus_no)
					{
				printf("\n *********** YOUR TICKET IS ************");
				printf("\n -------------------------------------------");
				printf("\n| BUS NO: %d |" ,ptr->busno);
				printf("\n| SOURCE: %s |",ptr->source);
				printf("\n| DESTINATION: %s |",ptr->destination);
				printf("\n| DATE: %s |",ptr->date);
				printf("\n| PRICE: %d |",ptr->price);
				printf("\n-------------------------------------------");
				printf("\n");
				    }
				   ptr=ptr->next;
			    }
}

