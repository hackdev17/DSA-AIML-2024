/*				Program 3
 * Develop a menu driven Program in C for the following operations on
 * STACK of Integers (Array Implementation of Stack with maximum size MAX)
 *	a. Push an Element on to Stack
 *	b. Pop an Element from Stack
 *	c. Demonstrate how Stack can be used to check Palindrome
 *	d. Demonstrate Overflow and Underflow situations on Stack
 *	e. Display the status of Stack
 *	f. Exit
 * Support the program with appropriate functions for each of the above
 * operations.
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define max_size 5

int stack[max_size],top=-1,flag=1;
int i,ispali,temp,item,rev[max_size],num[max_size];

void push(){
	if(top==(max_size-1))
		printf("\nStack Overflow !");
	else{
		printf("Enter the element to be inserted : ");
		scanf("%d",&item);
		top++;
		stack[top]=item;
	}
	temp=top;
}

void pop(){
	if(top==-1){
		printf("Stack Underflow !\n");
		flag=0;
	}else{
		item=stack[top];
		top--;
	}
}

void pali(){
	if(top==-1)
		printf("Push some elements into the stack first !\n");
	else{
		while(top!=-1){
			rev[top]=stack[top];
			pop();
		}
		top=temp;
		for(i=0;i<=temp;i++)
			if(stack[top--]==rev[i]&&i==temp)
				ispali=1;
			else
				ispali=0;
	}
		if(ispali)
			printf("Palindrome !\n");
		else 
			printf("Not Palindrome\n");
}

void display(){
	int i;
	top=temp;
	
	if(top==-1)
		printf("Stack is Empty !\n");
	else{
		printf("The stack elements are : ");
		for(i=top;i>=0;i--)
			printf("%d ",stack[i]);
		printf("\n");
	}
}

int main(){
	int choice;
	printf("\n\n--------STACK OPERATIONS--------\n");
	printf("1.Push\n2.Pop\n3.Palindrome\n4.Display\n5.Exit\n");
	while(1){
		printf("> ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				push();
				break;
			case 2:
				pop();
				if(flag)
					printf("\nThe poped element : %d\n",item);
				temp=top;
				break;
			case 3:
				pali();
				top=temp;
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
				break;
			
			default:
				printf("\nInvalid choice !");
				break;
		}
	}
}

