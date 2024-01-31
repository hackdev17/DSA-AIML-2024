#include<stdio.h>
#include<stdlib.h>

struct node{
	char usn[12],name[20],dept[25],desig[20];
	unsigned long long int phno;
	float sal;
	struct node *prev;
	struct node *next;
};

typedef struct node *NODE;
NODE temp,FIRST=NULL,END=NULL;

NODE getnode(){
	NODE x;
	x=(NODE)malloc(sizeof(struct node));
	x->prev=NULL;
	x->next=NULL;
	return x;
}

void read(){
	temp=getnode();
	printf("Enter USN : ");
	scanf("%s",temp->usn);
	printf("Enter Name :\n");
	scanf("%s",temp->name);
	printf("Enter Department : ");
	scanf("%s",temp->dept);
	printf("Enter Designation : ");
	scanf("%s",temp->desig);
	printf("Enter Phone : ");
	scanf("%llu",&temp->phno);
	printf("Enter Salary : ");
	scanf("%f",&temp->sal);

}

void Create_DLL(){
	int n,i=1;
	printf("Enter the number of Employees : ");
	scanf("%d",&n);
	while(i<=n){
		printf("Enter the details of the %d employee\n",i++);
		read();

		if(FIRST==NULL)
			FIRST=END=temp;
		else{
			END->next=temp;
			temp->prev=END;
			END=temp;
		}
	}
}

void display_count(){
	temp=FIRST;
	int count=0;
	if(FIRST==NULL)
		printf("The Employee detail is NULL and count is %d\n",count);
	else{
		printf("Employee details:\n");
		printf("USN \tEMPLOYEE NAME\tDEPARTMENT\tDESIGNATION\tPHONE NUMBER\tSALARY");
		while(temp!=NULL){
			count++;
			printf("\n%s\t%s\t%s\t\t%s\t\t%llu\t\t%0.2f",\
					temp->usn,temp->name,temp->dept,temp->desig,temp->phno,temp->sal);
			temp=temp->next;
		}
			printf("\n Employee count is %d\n",count);
	}

}

void Insertionfront(){
	printf("Enter the details of the employee\n");
	read();

	if(FIRST==NULL)
		FIRST=END=temp;
	else{
		temp->next=FIRST;
		FIRST->prev=temp;
		FIRST=temp;
	}
}

void Insertionend(){
	printf("Enter the details of the new employee\n");
	read();
	if(FIRST==NULL)
		FIRST=END=temp;
	else{
		END->next=temp;
		temp->prev=END;
		END=temp;
	}

}
void Deletionfront(){
	temp=FIRST;
	if(FIRST==NULL)
		printf("List is empty !\n");
	else if(FIRST==END){
		printf("Deleted element is %s\n",temp->usn);
		FIRST=END=NULL;
		free(temp);
	}else{
		printf("Deleted element is %s\n",temp->usn);
		FIRST=FIRST->next;
		FIRST->prev=NULL;
		free(temp);
	}

}
void Deletionend(){
	temp=END;
	if(FIRST==NULL)
		printf("List is empty !\n");
	else if(FIRST==END){
		printf("Deleted element is %s\n",temp->usn);
		FIRST=END=NULL;
		free(temp);
	}else{
		printf("Deleted element is %s\n",temp->usn);
		END=END->prev;
		END->next=NULL;
		free(temp);
	}
}

int main(){
	int choice;
	while(1){
		printf("\n1.Create DLL of N Employees\n2.Display DLL\n3.Insertion at front");
		printf("\n4.Insertion at end");
		printf("\n5.Deletion at front\n6.Deletion at end\n7.Exit\n");
		printf("\nEnter Your Choice : ");

		scanf("%d",&choice);

			switch(choice){
				case 1 :
					Create_DLL();
					break;
				case 2:
					display_count();
					break;
				case 3:
					Insertionfront();
					break;
				case 4:
					Insertionend();
					break;
				case 5:
					Deletionfront();
					break;
				case 6:
					Deletionend();
					break;
				case 7:
					exit(0);
					break;
				default: printf("Invalid Choice !\n");
			}
	}
}
